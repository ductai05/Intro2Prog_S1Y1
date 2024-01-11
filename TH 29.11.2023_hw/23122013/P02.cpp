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

void TongChinhPhuong(int a[], int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == int(sqrt(a[i])) * int(sqrt(a[i]))) {
			ans += a[i];
		}
	}
	cout << "\nTong cac so chinh phuong la: " << ans << "\n";
}

bool HoanChinh(int x) {
	long long temp = 0;
	for (int i = 1; i <= x / 2; i++) {
		if (x % i == 0) {
			temp += i;
		}
	}
	if (temp == x) {
		return true;
	}
	else {
		return false;
	}
}

void TongHoanChinh(int a[], int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (HoanChinh(a[i])) {
			ans += a[i];
		}
	}
	cout << "\nTong cac so hoan chinh la: " << ans << "\n";
}

bool NguyenTo(int x) {
	if (x < 2) {
		return false;
	}
	else {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}

void TongNguyenTo(int a[], int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (NguyenTo(a[i])) {
			ans += a[i];
		}
	}
	cout << "\nTong cac so nguyen to la: " << ans << "\n";
}

bool DoiXung(int x) {
	int orr = x;
	if (x < 0) {
		return false; 
	}

	int y = 0;
	while (x > 0) {
		y = y * 10 + x % 10;
		x /= 10;
	}

	return orr == y ;
}

void TongDoiXung(int a[], int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (DoiXung(a[i])) {
			ans += a[i];
		}
	}
	cout << "\nTong cac so doi xung la: " << ans << "\n";
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int [n];
	NhapMang(a, n);
	XuatMang(a, n);
	TongChinhPhuong(a, n);
	TongHoanChinh(a, n);
	TongNguyenTo(a, n);
	TongDoiXung(a, n);
	delete[] a;
	return 0;
}
