#include <iostream>
#include <fstream>

using namespace std;

bool is_Prime(int x) {
    if (x < 2) {
        return false;
    }
    else if (x == 2) {
        return true;
    }
    else {
        for (int i = 2; i*i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    ifstream File("matrix.txt"); 

    if (!File) {
        cout << "Khong the mo file." << "\n";
        return 1;
    }
    
    int a, b;
    File >> a >> b;

    int** t = new int* [a];
    for (int i = 0; i < a; i++) {
        t[i] = new int[b];
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            File >> t[i][j];
        }
    }
    File.close();
    int ans = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (is_Prime(t[i][j])) {
                ans += t[i][j];
            }
        }
    }

    for (int i = 0; i < a; i++) {
        delete[] t[i];
    }
    delete[] t;

    ofstream file("ketqua.txt"); 

    if (file.is_open()) {
        file << ans;
    }
    else {
        cout << "Khong the tao file.";
    }

    return 0;
}