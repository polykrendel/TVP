#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int performOperation(char op, int op1, int op2) {
    switch (op) {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    default: return 0;
    }
}

int performPrefix(const string& expression) {
    stack<int> s;

    for (int i = expression.length() - 1; i >= 0; --i) {
        if (isspace(expression[i])) {
            continue;
        }

        if (isOperator(expression[i])) {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            int result = performOperation(expression[i], op1, op2);
            s.push(result);
        }
        else if (isdigit(expression[i])) {
            int op = 0;
            int mult = 1;

            while (i >= 0 && isdigit(expression[i])) {
                op = (expression[i] - '0') * mult + op;
                mult *= 10;
                --i;
            }
            ++i;
            s.push(op);
        }
    }
    return s.top();
}

int main() {
    string expression;
    setlocale(LC_ALL, "Russian");
    cout << "Введите выражение в префиксной форме:" << '\n';
    getline(cin, expression);
    cout << "Результат вычисления: " << performPrefix(expression) << '\n';
}