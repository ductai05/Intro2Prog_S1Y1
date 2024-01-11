//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 06.12.2023

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}

void XuatMang(int a[], int n) {
	cout << "\nCac phan tu trong mang la:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n\n";
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void SapXep(int a[], int n) {
	cout << "\nTa sap xep cac phan tu trong mang la so nguyen to.\n";
    int* primes = new int[n];
    int primeCount = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            primes[primeCount] = a[i];
            primeCount++;
        }
    }

    std::sort(primes, primes + primeCount);

    int primeIndex = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            a[i] = primes[primeIndex];
            primeIndex++;
        }
    }

    delete[] primes;
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	SapXep(a, n);
	XuatMang(a, n);
	delete[] a;
	return 0;
}


