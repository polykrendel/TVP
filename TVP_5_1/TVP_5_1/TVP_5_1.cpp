#include <iostream>
#include <list>
#include <string>

class ListDEQ {
private:
    std::list<std::string> deque;
    int maxLength;

public:
    ListDEQ(int maxLen) : maxLength(maxLen) {}

    void push_back(const std::string& str) {
        deque.push_back(str);
    }

    void push_front(const std::string& str) {
        deque.push_front(str);
    }

    void pop_front() {
        if (!deque.empty()) {
            deque.pop_front();
        }
    }

    void pop_back() {
        if (!deque.empty()) {
            deque.pop_back();
        }
    }

    void remove_long_elements() {
        for (auto it = deque.begin(); it != deque.end();) {
            if (it->length() > maxLength) {
                it = deque.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void display() const {
        for (const auto& str : deque) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int maxLen;
    std::cout << "Введите максимальную длину строки: ";
    std::cin >> maxLen;

    ListDEQ deq(maxLen);

    std::string input;
    std::cout << "Введите строки (для окончания введите '0'): " << std::endl;
    while (true) {
        std::cin >> input;
        if (input == "0") break;
        deq.push_back(input);
    }

    std::cout << "Очередь до удаления: ";
    deq.display();

    deq.remove_long_elements();

    std::cout << "Очередь после удаления длинных элементов: ";
    deq.display();

    return 0;
}
