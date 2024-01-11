//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>
#include <cmath>
using namespace std;

bool isBinaryNumber(long long bin) {
    while (bin != 0) {
        int digit = bin % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        bin /= 10;
    }
    return true;
}

long long DecToBin(int dec) {
    long long bin = 0;
    int temp, i = 1;

    while (dec != 0) {
        temp = dec % 2;
        dec /= 2;
        bin += temp * i;
        i *= 10;
    }

    return bin;
}

int BinToDec(long long bin) {
    int dec = 0, i = 0, temp;

    while (bin != 0) {
        temp = bin % 10;
        bin /= 10;
        dec += temp * pow(2, i);
        ++i;
    }

    return dec;
}

int main() {
    int dec;
    cout << "Nhap so thap phan: ";
    cin >> dec;

    long long ans1 = DecToBin(dec);
    cout << "So nhi phan tuong ung: " << ans1 << '\n';

    long long bin;
    NhapLai:
    cout << "Nhap so nhi phan: ";
    cin >> bin;
    if (!isBinaryNumber(bin)) {
        cout << "So nhap vao khong phai so nhi phan. Hay nhap lai!\n";
        goto NhapLai;
    }

    int ans2 = BinToDec(bin);
    cout << "So thap phan tuong ung: " << ans2 << '\n';

    return 0;
}



