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

void XoaPhanTu(int a[], int& N, int k) {
	// Mang a[], so phan tu can xoa = 1, so phan tu mang A la N, k la vi tri.
	for (int i = k; i < N - 1; i++) {
		a[i] = a[i + 1];
	}
	N -= 1;
}

void Xoa(int a[], int b[], int c[], int x, int y, int n) {
	int idc = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (a[i] == b[j]) {
				c[idc] = a[i];
				idc += 1;
			}
		}
	}
	sort(c, c + idc);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < idc; j++) {
			if (a[i] == c[j]) {
				//cout << "Xoa a tai" << i << "  " << j << '\n';
				XoaPhanTu(a, x, i);
			}
		}
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < idc; j++) {
			if (b[i] == c[j]) {
				//cout << "Xoa b tai " << i << "  " << j << '\n';
				//cout << "b[i] == c[j] " << b[i] << " == " << c[j] << '\n';
				XoaPhanTu(b, y, i);
			}
		}
	}
	cout << "Mang C:\n";
	XuatMang(c, idc);
	cout << "Ta se xoa cac phan tu trung nhau tren 2 mang A,B.\n";
	cout << "Mang A sau khi chinh sua la:\n";
	XuatMang(a, x);
	cout << "Mang B sau khi chinh sua la:\n";
	//cout << x << " " << y << "\n";
	XuatMang(b, y);
}

int main() {
	int x;
	cout << "Nhap vao so phan tu cua mang A. x = ";
	cin >> x;

	int y;
	cout << "Nhap vao so phan tu cua mang B. y = ";
	cin >> y;

	int n = max(x, y);
	int* a = new int[x + 2];
	int* b = new int[y + 2];
	int* c = new int[n + 2];

	cout << "Nhap vao cac phan tu cua mang A.\n";
	NhapMang(a, x);
	XuatMang(a, x);
	cout << "Nhap vao cac phan tu cua mang B.\n";
	NhapMang(b, y);
	XuatMang(b, y);
	Xoa(a, b, c, x, y, n);
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}
