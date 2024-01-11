//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

#include <iostream>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;

string chuyenDoiSoThanhChuoi(ll n) {
    string str = to_string(n);

    ll len = str.length();
    ll pos = len % 3;
    if (pos == 0) pos = 3;
    for (ll i = pos; i < len; i += 4) {
        str.insert(i, ",");
        len++;
    }

    return str;
}

int main() {
    ll soNguyen;

    cout << "Nhap so nguyen: ";
    cin >> soNguyen;

    string chuoiChuyenDoi = chuyenDoiSoThanhChuoi(soNguyen);
    cout << "Chuoi sau khi chuyen doi: " << chuoiChuyenDoi << "\n";

    return 0;
}