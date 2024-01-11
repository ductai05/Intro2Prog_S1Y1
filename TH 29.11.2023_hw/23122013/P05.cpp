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

void KiemTraTangGiam(int a[], int n) {
	if (n == 1) {
		cout << "\nMang chi co 1 phan tu. Khong xet duoc tinh tang/giam.\n";
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			cout << "\nCo 2 phan tu lien tiep bang nhau. Mang khong tang hoac giam nghiem ngat\n";
			break;
		}
	}

	bool tang = true, giam = true;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			tang = false;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) {
			giam = false;
		}
	}
	if (tang == false && giam == false) {
		cout << "\nMang khong co thu tu. Sap xep lai theo thu tu tang dan:\n";
		sort(a, a + n);
		XuatMang(a, n);
	}
	else if (tang == true && giam == false) {
		cout << "\nMang co thu tu tang dan\n";
	}
	else if (giam == true && tang == false) {
		cout << "\nMang co thu tu giam dan\n";
	}
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int [n];
	NhapMang(a, n);
	XuatMang(a, n);
	KiemTraTangGiam(a, n);

	delete[] a;
	return 0;
}
