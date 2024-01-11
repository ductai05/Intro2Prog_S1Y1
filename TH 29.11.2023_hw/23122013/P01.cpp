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

void TinhTongKhongAm(int a[], int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			ans += a[i];
		}
	}
	cout << "\nTong cac phan tu khong am cua mang la: " << ans << "\n";
}

void TinhTongMod3(int a[], int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 3 == 0) {
			ans += a[i];
		}
	}
	cout << "\nTong cac phan tu chia het cho 3 cua mang la: " << ans << "\n";
}

bool LeDau(int x) {
	if (x == 0) {
		return false;
	}
	else if (x < 0) {
		x = -x;
	}
	int ans = 0;
	while (x != 0) {
		ans = x % 10;
		x -= x % 10;
		x /= 10;
		if (x == 0) {
			if (ans % 2 == 0) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}

void TinhTongLeDau(int a[], int n) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (LeDau(a[i])) {
			ans += a[i];
		}
	}
	cout << "\nTong cac phan tu co chu so dau la so le cua mang la: " << ans << "\n";
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int [n];
	NhapMang(a, n);
	XuatMang(a, n);
	TinhTongKhongAm(a, n);
	TinhTongMod3(a, n);
	TinhTongLeDau(a, n);
	delete[] a;
	return 0;
}
