//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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

void TanSuat(int a[], int n) {
	cout << "Phan tu  - Tan suat\n";
	sort(a, a + n);
	int ts = 0;
	int id = a[0];
	for (int i = 0; i < n; i++) {
		if (id != a[i]) {
			cout << id << "           " << ts << "\n";
			id = a[i];
			ts = 0;
			i--;
		}
		else {
			ts += 1;
		}
	}
	cout << id << "           " << ts << "\n";
}

int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);
	TanSuat(a, n);
	delete[] a;
	return 0;
}