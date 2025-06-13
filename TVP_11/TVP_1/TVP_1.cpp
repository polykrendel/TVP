#include <iostream>
#include <set>
using namespace std;

set<int> unite(set<int> s1, set<int> s2) {
    set<int> s3;
    for (int i : s1) {
        s3.insert(i);
    }
    for (int i : s2) {
        s3.insert(i);
    }
    return (s3);
}

set<int> divide(set<int> s1, set<int> s2) {
    set<int> s3;
    for (int i : s2) {
        if (s1.contains(i)==true) {

        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    set<int> set1;
    set<int> set2;
    int len1, len2;
    cout << "Введите размерность 1, затем 2 множества:";
    cin >> len1 >> len2;
    cout << "Введите элементы 1 множества:";
    for (int i = 0; i < len1; i++) {
        int el;
        cin >> el;
        set1.insert(el);
    }
    cout << "Введите элементы 2 множества:";
    for (int i = 0; i < len2; i++) {
        int el;
        cin >> el;
        set2.insert(el);
    }

}