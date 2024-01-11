//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT_hw 06.12.2023

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

void XoaPhanTu(int a[], int n, int N, int k) {
	if (n < N - k) {
		for (int i = k - 1; i < N - n; i++) {
			a[i] = a[i + 1];
		}
		N -= n;
	}
	else {
		N -= N - k + 1;
	}
	
	XuatMang(a, N);
}

int main() {
	int N, n, x, k;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> N;
	int* a = new int[N + 2];
	NhapMang(a, N);
	XuatMang(a, N);

	Nhaplai1:
	cout << "Nhap vao so phan tu can xoa. n = ";
	cin >> n;
	if (n > N) {
		cout << "Nhap lai!\n";
		goto Nhaplai1;
	}

	Nhaplai2:
	cout << "Nhap vao vi tri phan tu bat dau can xoa. k = ";
	cin >> k;
	if (k > N) {
		cout << "Nhap lai!\n";
		goto Nhaplai2;
	}

	XoaPhanTu(a, n, N, k);
	delete[] a;
	return 0;
}
