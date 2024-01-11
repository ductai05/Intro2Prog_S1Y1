//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 29.11.2023

#include<iostream>

using namespace std;

void NhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}
void XuatMang(int a[], int n) {
	cout << "Cac phan tu trong mang la:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void TimKiem(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << "Vi tri phan tu dang tim kiem la: " << i + 1 << "\n";
			return;
		}
	}
	cout << "Khong tim thay phan tu x trong mang.\n";
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n + 1];
	NhapMang(a, n);
	XuatMang(a, n);
	int x;
	cout << "Nhap vao phan tu x: ";
	cin >> x;
	TimKiem(a, n, x);
	delete[] a;
	return 0;
}