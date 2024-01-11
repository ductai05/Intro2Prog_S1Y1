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

void TimMaxMin(int a[], int n) {
	int maxx = 1, minn = 1;
	for (int i = 0; i < n; i++) {
		if (a[maxx - 1] < a[i]) {
			maxx = i + 1;
		}
		if (a[minn - 1] > a[i]) {
			minn = i + 1;
		}
	}
	cout << "\nVi tri cua phan tu lon nhat la: " << maxx;
	cout << "\nVi tri cua phan tu nho nhat la: " << minn << "\n";

}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	TimMaxMin(a, n);
	delete[] a;
	return 0;
}
