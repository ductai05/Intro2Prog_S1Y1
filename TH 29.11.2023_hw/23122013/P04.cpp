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

void DoiXung(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] != a[n - i - 1]) {
			cout << "\nMang khong doi xung.\n";
			return;
		}
	}
	cout << "\nMang doi xung.\n";
}

void DanXen(int a[], int n) {
	int Dau = 1;
	if (a[0] < 0) {
		Dau = -1;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cout << "\nMang khong dan xen am duong vi co so 0\n";
			return;
		}
	}
	if (Dau == 1) {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0 && a[i] < 0) {
				cout << "\nMang khong dan xen am duong\n";
				return;
			}
			else if (i % 2 == 1 && a[i] > 0) {
				cout << "\nMang khong dan xen am duong\n";
				return;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0 && a[i] > 0) {
				cout << "\nMang khong dan xen am duong\n";
				return;
			}
			else if (i % 2 == 1 && a[i] < 0) {
				cout << "\nMang khong dan xen am duong\n";
				return;
			}
		}
	}
	cout << "\nMang dan xen am duong.\n";
}

void KhacCanh(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			cout << "\nMang co ton tai cap so canh nhau ma bang nhau.\n";
			return;
		}
	}
	cout << "\nMang co tat ca cac cap phan tu dung canh nhau deu co gia tri khac nhau.\n";
}

void CSC(int a[], int n) {
	if (n < 2) {
		cout << "Mang khong du phan tu nen khong thanh lap cap so cong.";
		return;
	}
	int d = a[1] - a[0];
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] != d) {
			cout << "\nMang khong thanh lap cap so cong\n";
			return;
		}
	}
	cout << "\nMang thanh lap cap so cong\n";
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int [n];
	NhapMang(a, n);
	XuatMang(a, n);
	DoiXung(a, n);
	DanXen(a, n);
	KhacCanh(a, n);
	CSC(a, n);
	delete[] a;
	return 0;
}
