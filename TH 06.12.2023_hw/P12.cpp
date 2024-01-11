//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sapXepTheoThuTuABC(const string& S) {
    string S1 = S;
    sort(S1.begin(), S1.end());
    return S1;
}

int main() {
    string S;

    cout << "Nhap chuoi S: ";
    getline(cin, S);

    string S1 = sapXepTheoThuTuABC(S);

    cout << "Xau S1 duoc lap tu xau S theo thu tu abc: " << S1 << endl;

    return 0;
}