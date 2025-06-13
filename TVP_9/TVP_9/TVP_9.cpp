#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <openssl/md5.h>
#include "streebog.hpp"
using namespace std;

vector<unsigned char> readFile(const string& filename) {
    ifstream file(filename, ios::binary);
    return vector<unsigned char>(istreambuf_iterator<char>(file), {});
}

vector<unsigned char> MD5(const vector<unsigned char>& data) {
    vector<unsigned char> md5Hash(MD5_DIGEST_LENGTH);
    MD5(data.data(), data.size(), md5Hash.data());
    return md5Hash;
}

vector<unsigned char> Stribog(const std::string& filename) {
    Streebog hash;
	hash.init();
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
		cout << "File is open" << endl;
        hash.update(file);
        file.close();
    }
    return hash.digest();
}

int main() {
    string filename = "C:\\Users\\Uberd\\Downloads\\test_file_15MB.txt";
    vector<unsigned char> data = readFile(filename);

    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл." << endl;
        return 1;
    }
    cout << "Файл успешно открыт." << endl;
    file.close();

    auto startMD5 = chrono::high_resolution_clock::now();
    auto md5Hash = MD5(data);
    auto endMD5 = chrono::high_resolution_clock::now();
    auto durationMD5 = chrono::duration_cast<chrono::milliseconds>(endMD5 - startMD5).count();
    cout << "MD5 Time: " << durationMD5 << " ms" << endl;
    
    cout << "bruh";

    auto startStribog = chrono::high_resolution_clock::now();
    auto stribogHash = Stribog(filename);
    auto endStribog = chrono::high_resolution_clock::now();
    auto durationStribog = chrono::duration_cast<chrono::milliseconds>(endStribog - startStribog).count();
    cout << "StriBog Time: " << durationStribog << " ms" << endl;
}
