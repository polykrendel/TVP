#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstdlib> 

using namespace std;

mutex mtx; 
long long globalSum = 0; 
int globalMax = INT_MAX; 
int globalMin = INT_MIN; 
double globalAvg = 0.0; 

void sum(const vector<int>& data) {
    lock_guard<mutex> lock(mtx);
    long long localSum = 0;
    for (int num : data) {
        localSum += num;
    }
    globalSum = localSum;
}

void findMax(const vector<int>& data) {
    lock_guard<mutex> lock(mtx);
    int localMax = INT_MIN;
    for (int num : data) {
        localMax = max(localMax, num);
    }
    globalMax = localMax;
}

void findMin(const vector<int>& data) {
    lock_guard<mutex> lock(mtx);
    int localMin = INT_MAX;
    for (int num : data) {
        localMin = min(localMin, num);
    }
    globalMin = localMin;
}

void avg(const vector<int>& data) {
    lock_guard<mutex> lock(mtx);
    long long localSum = 0;
    for (int num : data) {
        localSum += num;
    }
    globalAvg = static_cast<double>(localSum) / data.size();
}

int main() {
	setlocale(LC_ALL, "Russian");
    int size;
	cout << "Введите размер массива: ";
	cin >> size;
    vector<int> data(size);
	int choice;
	cout << "Выберите способ ввода массива: 1 - ручной ввод, другое число - автоматический ввод" << '\n';
	cin >> choice;
	if (choice == 1) {
		for (int i = 0; i < size; ++i) {
			cin >> data[i];
		}
	}
	else {
		for (int i = 0; i < size; ++i) {
			data[i] = rand() % 1000;
		}
	}

    thread sumThread(sum, cref(data));
    thread maxThread(findMax, cref(data));
    thread minThread(findMin, cref(data));
    thread avgThread(avg, cref(data));

    sumThread.join();
    maxThread.join();
    minThread.join();
    avgThread.join();

    cout << "Сумма элементов: " << globalSum << '\n';
    cout << "Максимальный элемент: " << globalMax << '\n';
    cout << "Минимальный элемент: " << globalMin << '\n';
    cout << "Среднее значение: " << globalAvg << '\n';
}
