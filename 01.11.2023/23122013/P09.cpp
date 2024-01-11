#include <iostream>
#include <cmath>

using namespace std;

double Tinh(int n, double x) {
    double S = 0;
    double giaithua = 1;
    int id = 1;
    for (int i = 0; i <= n; i++) {
        cout << giaithua << '\n';
        S += pow(-1, i) * pow(x, 2 * i + 1) / giaithua;
        giaithua = giaithua* (id + 1)* (id + 2);
        id += 2;
    }
    return S;
}

int main()
{
    int n; double x;
    NhapLai:
    cout << "Nhap so nguyen duong n va so thuc x: ";
    cin >> n >> x;
    if (n <= 0) {
        cout << "n khong phai so nguyen duong! Nhap lai!\n";
        goto NhapLai;
    }
    double S = 0;
    S = Tinh(n, x);
    cout << "S = " << S;

    return 0;
}

