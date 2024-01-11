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

void XoaPhanTu(int a[], int n) {
	int k;
	NhapLai:
	cout << "\nNhap vao vi tri k: ";
	cin >> k;
	if (k < 1 || k > n) {
		cout << "Nhap lai vi tri k.\n";
		goto NhapLai;
	}
	cout << "Ta xoa phan tu tai vi tri k.\n";
	for (int i = k - 1; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n -= 1;
	XuatMang(a, n);
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n + 2];
	NhapMang(a, n);
	XuatMang(a, n);
	XoaPhanTu(a, n);
	delete[] a;
	return 0;
}
