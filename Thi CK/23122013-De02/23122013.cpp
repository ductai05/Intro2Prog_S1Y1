// Ho ten: Dinh Duc Tai
// MSSV: 23122013
// So may: 04


#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

void XuatMang(int a[], int n) {
    cout << "\nMang co cac phan tu la:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return;
}

bool TongChan(int x) {
    int ans = 0;
    if (x < 0) {
        x = -x;
    }
    while (x != 0) {
        ans += x % 10;
        x /= 10;
    }
    if (ans % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void TongChuSoChan(int a[], int n, ofstream& output) {
    cout << "Cac phan tu co tong cac chu so la chan: \n";
    for (int i = 0; i < n; i++) {
        if (TongChan(a[i])) {
            cout << a[i] << " ";
            output << a[i] << " ";
        }
    }
    output << "\n";
    cout << "\n";
}

void ThemPhanTuDuong(int a[], int& n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            for (int j = n; j > i; j--) {
                a[j] = a[j - 1]; // j = i + 1;
            }
            a[i + 1] = - a[i];
            n++;
        }
    }
    cout << "\n";
}

bool NguyenTo(int x) {
    if (x < 2) {
        return false;
    }
    else if (x == 2) {
        return true;
    }
    else {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
}

void XoaPhanTu(int a[], int n, ofstream& output) {
    bool check = false;
    cout << "Xoa cac phan tu co gia tri tuyet doi lien ke so nguyen to\n";
    cout << "Mang co cac phan tu la:\n";
    int c, d;
    for (int i = 0; i < n; i++) {
        c = abs(a[i]) + 1;
        d = abs(a[i]) - 1;
        if (NguyenTo(c) == false && NguyenTo(d) == false) {
            check = true;
            cout << a[i] << " ";
            output << a[i] << " ";
        }
    }
    if (check == false) {
        cout << "Khong co phan tu nao thoa man\n";
    }
    output << "\n";
}

int main() {
    ofstream output("LOG.TXT");
    if (!output.is_open()) {
        cout << "Khong the mo tap tin LOG.TXT." << "\n";
    }
    int n;
    cout << "Nhap vao so phan tu cua mang: ";
    cin >> n;
    int* a = new int[n + 2];
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
    XuatMang(a, n);
    TongChuSoChan(a, n, output);
    ThemPhanTuDuong(a, n);
    cout << "Mang sau khi them phan tu: \n";
    XuatMang(a, n);
    for (int i = 0; i < n; i++) {
        output << a[i] << " ";
    }
    output << "\n";
    XoaPhanTu(a, n, output);
    delete[] a;
    output.close();
    return 1;
}

