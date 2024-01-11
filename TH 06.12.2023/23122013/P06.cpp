//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 06.12.2023

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool doixung(const std::string& chuoi) {
    int n = chuoi.length();
    for (int i = 0; i < n; i++) {
        if (chuoi[i] != chuoi[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Nhap vao 1 chuoi: ";
    string chuoi;
    getline(cin, chuoi);

    if (doixung(chuoi)) {
        cout << "Chuoi la doi xung." << "\n";
    }
    else {
        cout << "Chuoi khong la doi xung." << "\n";
    }
    return 0;
}
