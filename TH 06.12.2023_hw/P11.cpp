//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> timViTriXuatHien(const string& chuoiCha, const string& chuoiCon) {
    vector<int> viTri;

    size_t pos = 0;
    while ((pos = chuoiCha.find(chuoiCon, pos)) != string::npos) {
        viTri.push_back(pos);
        pos += chuoiCon.length();
    }

    return viTri;
}

int main() {
    string S1, S2;

    cout << "Nhap chuoi S1: ";
    getline(cin, S1);

    cout << "Nhap chuoi S2: ";
    getline(cin, S2);

    vector<int> viTriXuatHienS1TrongS2 = timViTriXuatHien(S2, S1);
    vector<int> viTriXuatHienS2TrongS1 = timViTriXuatHien(S1, S2);

    cout << "S1 xuat hien " << viTriXuatHienS1TrongS2.size() << " lan trong S2 tai cac vi tri: ";
    for (int i = 0; i < viTriXuatHienS1TrongS2.size(); i++) {
        cout << viTriXuatHienS1TrongS2[i];
        if (i < viTriXuatHienS1TrongS2.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "S2 xuat hien " << viTriXuatHienS2TrongS1.size() << " lan trong S1 tai cac vi tri: ";
    for (int i = 0; i < viTriXuatHienS2TrongS1.size(); i++) {
        cout << viTriXuatHienS2TrongS1[i];
        if (i < viTriXuatHienS2TrongS1.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}