//ciel_23122013 23TNT1 FIT@HCMUS
// TH NMLT_hw 29.11.2023

#include <iostream>
#include <algorithm>

using namespace std;

void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao phan tu (nguyen duong) thu " << i + 1 << ": ";
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

void KiemTraSoDuong(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			cout << "\nMang co chua so duong.\n";
			return;
		}
	}
	cout << "\nMang khong chua so duong.\n";
	return;
}

void SoDuongThanhSoAm(int a[], int n) {
	cout << "Ta se doi so duong thanh so am.\n";
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			a[i] *= -1;
		}
	}
	XuatMang(a, n);
}

void KiemTraToanSoDuong(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] <= 0) {
			cout << "\nMang co ton tai so khong duong.\n";
			SoDuongThanhSoAm(a, n);
			return;
		}
	}
	cout << "\nMang chua toan so duong.\n";
	return;
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int [n];
	NhapMang(a, n);
	XuatMang(a, n);
	KiemTraSoDuong(a, n);
	KiemTraToanSoDuong(a, n);
	delete[] a;
	return 0;
}
