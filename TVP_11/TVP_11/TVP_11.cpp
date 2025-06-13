#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

void bubble(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quick(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    quick(arr, left, i);
    quick(arr, i + 2, right);
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

void sortTime(void (*sortFunction)(vector<int>&), vector<int> arr, const string& name) {
    clock_t start = clock();
    sortFunction(arr);
    clock_t end = clock();
    cout << name << " работала " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << " миллисекунд(у/ы)" << '\n';
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int size;
    cout << "Введите размер массива: " << '\n';
    cin >> size;
    vector<int> arr(size);
    int avto;
    cout << "Хотите заполнить вручную(1) или автоматически(любое другое число): " << '\n';
    cin >> avto;
    if (avto == 1) {
        cout << "Введите элементы массива: " << '\n';
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
	}
	else {
		arr = generateRandomArray(size);
	}
    sortTime(bubble, arr, "Пузырьковая сортировка");
    sortTime(insertion, arr, "Сортировка вставками");
    auto quickWrapper = [](vector<int>& arr) {
        quick(arr, 0, arr.size() - 1);
    };
    sortTime(quickWrapper, arr, "Быстрая сортировка");
}
