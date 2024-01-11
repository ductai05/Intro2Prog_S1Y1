//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 06.12.2023

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void daochuoi(std::string& chuoi) {
    string goc = chuoi;
    int n = chuoi.length();
    for (int i = 0; i < n; i++) {
        chuoi[i] = goc[n - i - 1];
    }
}

int main() {
    cout << "Nhap vao 1 chuoi: ";
    string chuoi;
    getline(cin, chuoi);
    daochuoi(chuoi);
    cout << "Chuoi sau khi dao nguoc la:\n";
    cout << chuoi;
    return 0;
}
