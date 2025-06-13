#include <iostream>
#include <set>
using namespace std;

set<int> unite(set<int> s1, set<int> s2) {
    set<int> s3=s1;
    for (int i : s2) {
        s3.insert(i);
    }
    return (s3);
}

set<int> divide(set<int> s1, set<int> s2) {
    set<int> s3;
    for (int i : s1) {
        for (int j : s2) {
            if (s1.count(i) != 0 && s2.count(i)!=0) {
                s3.insert(i);
            }
        }
    }
    return(s3);
}

multiset<int> slit(set<int> s1, set<int> s2) {
    multiset<int> ms1;
    for (int i : s1) {
        ms1.insert(i);
    }
    for (int i : s2) {
        ms1.insert(i);
    }
    return(ms1);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    set<int> set1;
    set<int> set2;
    int len1, len2;
    cout << "Введите мощность 1, затем 2 множества:";
    cin >> len1 >> len2;
    cout << endl;
    cout << "Введите элементы 1 множества:";
    for (int i = 0; i < len1; i++) {
        int el;
        cin >> el;
        set1.insert(el);
    }
    cout << endl;
    cout << "Введите элементы 2 множества:";
    for (int i = 0; i < len2; i++) {
        int el;
        cin >> el;
        set2.insert(el);
    }
    cout <<endl<< "Результат слияния:";
    multiset<int> ms = slit(set1, set2);
    for (int i : ms) {
        cout << i<<" ";
    }
    cout << endl;
    set<int> s3 = unite(set1, set2);
    cout << "Результат объединения:";
    for (int i : s3) {
        cout << i << " ";
    }
    cout << endl;
    s3 = divide(set1, set2);
    cout << "Результат пересечения:";
    for (int i : s3) {
        cout << i << " ";
    }
}