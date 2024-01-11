//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

#include <iostream>
#include <string>

using namespace std;

string xoaKyTu(string s, int i, int n) {
    if (i >= 1 && i < s.length() && n > 0) {
        i--;
        s.erase(i, n);
    }
    return s;
}

int main() {
    string chuoi;
    int viTri, soKyTu;

    cout << "Nhap chuoi: ";
    getline(cin, chuoi);

    cout << "Nhap vi tri can xoa: ";
    cin >> viTri;

    cout << "Nhap so ky tu can xoa: ";
    cin >> soKyTu;

    string chuoiSauKhiXoa = xoaKyTu(chuoi, viTri, soKyTu);
    cout << "Chuoi sau khi xoa: " << chuoiSauKhiXoa << endl;

    return 0;
}