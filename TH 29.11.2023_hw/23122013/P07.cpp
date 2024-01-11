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

void XuatMangA(int a[], int n) {
	cout << "\nCac phan tu trong mang A la:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n\n";
}

void XuatMangB(int a[], int n) {
	cout << "\nCac phan tu trong mang B la:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n\n";
}

void XuatMangC(int a[], int n) {
	cout << "\nCac phan tu trong mang C la:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n\n";
}

void TronMang(int a[], int b[], int c[], int n) {
	for (int i = 0; i < n; i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < n; i++) {
		c[i + n] = b[i];
	}
	sort(c, c + 2 * n);
}

void TangDanA(int a[], int n) {
	bool tang = true;
	if (n == 1) {
		cout << "\nMang A chi co 1 phan tu.\n";
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			tang = false;
			break;
		}
	}
	if (tang) {
		cout << "\nMang A tang dan.\n";
	}
	else {
		cout << "\nMang A khong tang dan. Sap xep mang A tang dan:\n";
		sort(a, a + n);
		XuatMangA(a, n);
	}
}

void TangDanB(int a[], int n) {
	bool tang = true;
	if (n == 1) {
		cout << "\nMang B chi co 1 phan tu.\n";
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			tang = false;
			break;
		}
	}
	if (tang) {
		cout << "\nMang B tang dan.\n";
	}
	else {
		cout << "\nMang B khong tang dan. Sap xep mang B tang dan:\n";
		sort(a, a + n);
		XuatMangB(a, n);
	}
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n + 2];
	int* b = new int[n + 2];
	int* c = new int[2 * n + 2];

	cout << "\nNhap cac phan tu cho mang A:\n";
	NhapMang(a, n);
	XuatMangA(a, n);

	cout << "\nNhap cac phan tu cho mang B:\n";
	NhapMang(b, n);
	XuatMangB(b, n);

	TangDanA(a, n);
	TangDanB(b, n);

	cout << "\nTa se tron 2 mang A, B de duoc mang C co thu tu tang dan:\n";
	TronMang(a, b, c, n);
	XuatMangC(c, 2 * n);
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}
