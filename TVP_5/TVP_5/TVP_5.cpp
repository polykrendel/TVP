#include <iostream>
#include <string>
using namespace std;

class ArrDEQ {
private:
    string* arr;
    int front;          
    int rear;         
    int count; 
    int size;
    int length;

    void resize() {
        int newSize = size + 1;
        string* newArr = new string[newSize];

        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(front + i) % size];
        }

        delete[] arr;

        arr = newArr;
        front = 0;
        rear = count;
        size = newSize;
    }

public:
    ArrDEQ(int maxLen, int fSize) : front(0), rear(0), count(0), size(fSize), length(maxLen) {
        arr = new string[size];
    }

    ~ArrDEQ() {
        delete[] arr;
    }

    void push_front(const string& value) {
        if (count == size) {
            resize(); 
        }
        front = (front - 1 + size) % size;
        arr[front] = value;
        count++;
    }

    void push_back(const string& value) {
        arr[rear] = value;
        rear = (rear + 1) % size;
        count++;
    }

    void pop_front() {
        front = (front + 1) % size;
        count--;
    }

    void pop_back() {
        rear = (rear - 1 + size) % size;
        count--;
    }

    void remove_long_elements() {
        int newCount = 0;
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size;
            if (arr[index].length() <= length) {
                arr[newCount] = arr[index];
                newCount++;
            }
        }
        front = 0;
        rear = newCount;
        count = newCount;
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size;
            cout << arr[index] << " ";
        }
        cout << '\n';
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int maxLen, size;
    cout << "Введите максимальную длину строки, длину очереди: ";
    cin >> maxLen >> size;

    ArrDEQ deq(maxLen, size);

    string input;
    cout << "Введите строки (для окончания введите '0'): " << '\n';
    while (true) {
        cin >> input;
        if (input == "0") break;
        deq.push_back(input);
    }

    cout << "Очередь до удаления: ";
    deq.display();

    deq.remove_long_elements();

    cout << "Очередь после удаления длинных элементов: ";
    deq.display();

    return 0;
}
