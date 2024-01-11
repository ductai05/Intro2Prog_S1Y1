//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 20.12.2023

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct PhanSo {
    int tuso;   
    int mauso; 
};

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

vector<PhanSo> TaoMang(int N) {
    vector<PhanSo> MangPS;
    int tuso = 2;
    int mauso = 3;

    while (MangPS.size() < N) {
        PhanSo phanso;
        phanso.tuso = tuso;
        phanso.mauso = mauso;

        RutGon(phanso);

        if (phanso.mauso > phanso.tuso && phanso.mauso <= 2 * phanso.tuso) {
            MangPS.push_back(phanso);
        }

        mauso++;
        if (mauso > tuso + 1) {
            tuso++;
            mauso = tuso + 1;
        }
    }

    return MangPS;
}

void VietFile(const vector<PhanSo>& MangPS, const string& tenfile) {
    ofstream file(tenfile);
    if (file.is_open()) {
        file << MangPS.size() << endl;
        for (const PhanSo& phanso : MangPS) {
            file << phanso.tuso << "/" << phanso.mauso << " ";
        }
        file.close();
        cout << "Da ghi thong tin mang phan so vao tap tin " << tenfile << endl;
    }
    else {
        cout << "Khong the mo tap tin " << tenfile << " de ghi." << endl;
    }
}

int main() {
    int N;
    cout << "Nhap so luong phan so N: ";
    cin >> N;

    vector<PhanSo> MangPS = TaoMang(N);

    VietFile(MangPS, "Mang PS toi gian.txt");

    return 0;
}