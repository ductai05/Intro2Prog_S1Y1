//ciel_23122013 23TNT1 FIT@HCMUS
// TH NMLT_hw 29.11.2023

#include <iostream>
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

void KiemTraX(int a[], int n) {
	int x;
	cout << "Nhap vao phan tu X = ";
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << "\nCo ton tai so X trong mang da cho.\n";
			return;
		}
	}
	cout << "\nKhong ton tai so X trong mang.\n";
	cout << "Ta se chen so X vao sau phan tu dau tien\n";
	for (int i = n; i > 1; i--) {
		a[i] = a[i - 1];
	}
	a[1] = x; n += 1;
	cout << "Mang sau khi sap xep la:\n";
	XuatMang(a, n);
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int [n + 2];
	NhapMang(a, n);
	XuatMang(a, n);
	KiemTraX(a, n);

	delete[] a;
	return 0;
}
