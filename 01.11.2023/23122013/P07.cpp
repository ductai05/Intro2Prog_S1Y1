//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>

using namespace std;

int ucln(int a, int b) {
    if (b == 0)
        return a;
    return ucln(b, a % b);
}

void rutGonPhanSo(int& tuSo, int& mauSo) {
    int uocChung = ucln(tuSo, mauSo);
    tuSo /= uocChung;
    mauSo /= uocChung;
}

void tinhTongPhanSo(int tuSo1, int mauSo1, int tuSo2, int mauSo2, int& tuSoTong, int& mauSoTong) {
    tuSoTong = tuSo1 * mauSo2 + tuSo2 * mauSo1;
    mauSoTong = mauSo1 * mauSo2;
    rutGonPhanSo(tuSoTong, mauSoTong);
}

void tinhHieuPhanSo(int tuSo1, int mauSo1, int tuSo2, int mauSo2, int& tuSoHieu, int& mauSoHieu) {
    tuSoHieu = tuSo1 * mauSo2 - tuSo2 * mauSo1;
    mauSoHieu = mauSo1 * mauSo2;
    rutGonPhanSo(tuSoHieu, mauSoHieu);
}

int main() {
    int tuSo1, mauSo1, tuSo2, mauSo2;

    cout << "Nhap phan so thu nhat:\n";
    cout << "Tu so: ";
    cin >> tuSo1;
    cout << "Mau so: ";
    cin >> mauSo1;

    cout << "\nNhap phan so thu hai:\n";
    cout << "Tu so ";
    cin >> tuSo2;
    cout << "Mau so: ";
    cin >> mauSo2;

    rutGonPhanSo(tuSo1, mauSo1);
    rutGonPhanSo(tuSo2, mauSo2);

    int tuSoTong, mauSoTong;
    tinhTongPhanSo(tuSo1, mauSo1, tuSo2, mauSo2, tuSoTong, mauSoTong);

    int tuSoHieu, mauSoHieu;
    tinhHieuPhanSo(tuSo1, mauSo1, tuSo2, mauSo2, tuSoHieu, mauSoHieu);

    cout << "\nPhan so rut gon:\n";
    cout << "Phan so thu nhat: " << tuSo1 << "/" << mauSo1 << '\n';
    cout << "Phan so thu hai: " << tuSo2 << "/" << mauSo2 << '\n';

    cout << "\nTong cua hai phan so: " << tuSoTong << "/" << mauSoTong << '\n';
    cout << "Hieu cua hai phan so: " << tuSoHieu << "/" << mauSoHieu << '\n';

    return 0;
}