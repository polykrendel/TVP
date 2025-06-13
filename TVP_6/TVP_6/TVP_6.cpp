#include <iostream>
#include <unordered_map>
#include <string>
#include <Windows.h>
using namespace std;

class HashTable {
private:
    unordered_map<string, string> keyWords;

public:
    HashTable() {
        keyWords = {
            {"if", "Используется для условных операторов"},
            {"else", "Используется в альтернативной ветке условий"},
            {"while", "Оператор цикла с условием"},
            {"for", "Оператор цикла с параметрами"},
            {"int", "Тип данных для целых чисел"},
            {"float", "Тип данных для чисел с плавающей точкой"},
            {"double", "Тип данных для чисел с плавающей точкой двойной точности"},
            {"false", "Одно из двух значений для переменной типа bool"},
            {"return", "Используется для возврата значения из функции"},
            {"void", "Используется для функций, которые не возвращают значения"},
            {"switch", "Оператор выбора для нескольких альтернатив"},
            {"case", "Определяет одну альтернативу в switch"},
            {"namespace", "Область, в рамках которой определяются различные идентификаторы"},
            {"break", "Прерывает выполнение цикла или switch"},
            {"continue", "Переходит к следующей итерации цикла"},
            {"const", "Определяет неизменяемую переменную"},
            {"static", "Определяет статическую переменную или функцию"},
            {"protected", "Указывает доступ к членам класса в списке членов до следующего описателя доступа"},
            {"class", "Определяет класс в объектно-ориентированном программировании"},
            {"public", "Определяет общедоступную секцию класса"},
            {"or", "Логический оператор"},
            {"friend", "Предоставляет доступ к частным и защищенным членам класса"}
        };
    }

    void getHelp(const string& word) {
        auto it = keyWords.find(word);
        if (it != keyWords.end()) {
            cout << "Подсказка для '" << word << "': " << it->second << endl;
        }
        else {
            cout << "Слово не найдено((( Желаете добавить новое слово? (yes/no): ";
            string answer;
            cin >> answer;
            if (answer == "yes") {
                addWord(word);
            }
        }
    }

    void addWord(const string& word) {
        cout << "Введите описание для слова '" << word << "': ";
        string help;
        cin.ignore();
        getline(cin, help);
        keyWords[word] = help;
        cout << "Слово успешно добавлено." << endl;
    }
};

int main() {
    HashTable table;
    string input;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        cout << "Введите зарезервированное слово (или '0' для выхода): ";
        cin >> input;
        if (input == "0") break;
        table.getHelp(input);
    }

    return 0;
}
