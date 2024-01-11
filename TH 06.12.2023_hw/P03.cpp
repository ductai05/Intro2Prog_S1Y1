//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

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

void Tron(int a[], int b[], int c[], int n) {
	cout << "Ta se tron 2 mang A, B thanh mang C voi tong 2 phan tu tuong ung cua A va B.\n";
	for (int i = 0; i < n; i++) {
		c[i] = a[i] + b[i];
	}
	cout << "Ta duoc mang C.\n";
	XuatMang(c, n);
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n + 2];
	int* b = new int[n + 2];
	int* c = new int[n + 2];
	cout << "Nhap vao cac phan tu cua mang A.\n";
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "Nhap vao cac phan tu cua mang B.\n";
	NhapMang(b, n);
	XuatMang(b, n);
	Tron(a, b, c, n);
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}
