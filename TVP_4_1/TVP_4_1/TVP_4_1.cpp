#include <iostream>
#include <list>
using namespace std;

void maxToEnd(list<int>& l) {
    int maxn = l.front();
    auto iter = l.cbegin();
    auto maxIter = l.cbegin();
    for (int n : l) {
        if (n > maxn) {
            maxn = n;
            maxIter = iter;
        }
        iter++;
    }
    l.erase(maxIter);
    l.push_back(maxn);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    list<int> l;
    int size;
    cout << "Введите количество элементов списка: ";
    cin >> size;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < size; i++) {
        int el;
        cin >> el;
        l.push_back(el);
    }
    maxToEnd(l);
    cout << "Список после перемещения: ";
    for (int n : l) {
        cout << n << " ";
    }
}