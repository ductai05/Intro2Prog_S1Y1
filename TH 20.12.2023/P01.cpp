//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 20.12.2023

#include <iostream>
using namespace std;

struct PhanSo {
    int tuso;   
    int mauso; 
};

PhanSo NhapPhanSo() {
    PhanSo phanso;
    cout << "Nhap tu so: ";
    cin >> phanso.tuso;
    cout << "Nhap mau so: ";
    cin >> phanso.mauso;
    return phanso;
}

int TimGCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void RutGon(PhanSo& phanso) {
    int gcd = TimGCD(phanso.tuso, phanso.mauso);
    phanso.tuso /= gcd;
    phanso.mauso /= gcd;
}

PhanSo CongPhanSo(const PhanSo& phanso1, const PhanSo& phanso2) {
    PhanSo result;
    result.tuso = phanso1.tuso * phanso2.mauso + phanso2.tuso * phanso1.mauso;
    result.mauso = phanso1.mauso * phanso2.mauso;
    RutGon(result);
    return result;
}

PhanSo TruPhanSo(const PhanSo& phanso1, const PhanSo& phanso2) {
    PhanSo result;
    result.tuso = phanso1.tuso * phanso2.mauso - phanso2.tuso * phanso1.mauso;
    result.mauso = phanso1.mauso * phanso2.mauso;
    RutGon(result);
    return result;
}

PhanSo NhanPhanSo(const PhanSo& phanso1, const PhanSo& phanso2) {
    PhanSo result;
    result.tuso = phanso1.tuso * phanso2.tuso;
    result.mauso = phanso1.mauso * phanso2.mauso;
    RutGon(result);
    return result;
}

PhanSo ChiaPhanSo(const PhanSo& phanso1, const PhanSo& phanso2) {
    PhanSo result;
    result.tuso = phanso1.tuso * phanso2.mauso;
    result.mauso = phanso1.mauso * phanso2.tuso;
    RutGon(result);
    return result;
}

void InPhanSo(const PhanSo& phanso) {
    cout << phanso.tuso << "/" << phanso.mauso << endl;
}

int main() {
    cout << "Nhap phan so thu nhat:\n";
    PhanSo phanso1 = NhapPhanSo();

    cout << "\nNhap phan so thu hai:\n";
    PhanSo phanso2 = NhapPhanSo();

    cout << "\nTong hai phan so: ";
    InPhanSo(CongPhanSo(phanso1, phanso2));

    cout << "Hieu hai phan so: ";
    InPhanSo(TruPhanSo(phanso1, phanso2));

    cout << "Tich hai phan so: ";
    InPhanSo(NhanPhanSo(phanso1, phanso2));

    cout << "Thuong hai phan so: ";
    InPhanSo(ChiaPhanSo(phanso1, phanso2));

    return 0;
}