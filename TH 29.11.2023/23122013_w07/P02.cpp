//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 29.11.2023

#include<iostream>
#include<algorithm>

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

double Avg(int a[], int n) {
	double x = 0;
	for (int i = 0; i < n; i++) {
		x += a[i];
	}
	x /= n;
	return x;
}

int Max1(int a[], int n) {
	int x = a[0];
	for (int i = 0; i < n; i++) {
		if (x < a[i]) {
			x = a[i];
		}
	}
	return x;
}

int Max2(int a[], int n) {
	int max1 = a[0];
	int max2 = a[0];
	for (int i = 0; i < n; i++) {
		if (max1 < a[i]) {
			max2 = max1;
			max1 = a[i];
		}
	}
	return max2;
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n + 1];
	NhapMang(a, n);
	XuatMang(a, n);
	sort(a, a + n);
	double x = Avg(a, n);
	int max1 = Max1(a, n);
	int max2 = Max2(a, n);
	cout << "avg = " << x << "\n";
	cout << "Max1 = " << max1 << "\n";
	cout << "Max2 = " << max2 << "\n";
	delete[] a;
	return 0;
}