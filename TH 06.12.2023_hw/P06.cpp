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

void MangCon(int a[], int n) {
	if (n <= 1) {
		cout << "Mang khong co mang con tang dan hoac giam dan.\n";
		return;
	}
	int* b = new int [n + 2];
	int len = 0;
	bool check, test = false;
	int X = 0, Y = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			check = true;
			for (int k = i; k < j; k++) {
				if (a[k] > a[k + 1]) {
					check = false;
					break;
				}
			}
			if (check && j - i > len) {
				test = true;
				X = i; Y = j;
				len = Y - X;
			}
		}
	}
	if (test) {
		cout << "Mang con tang dan dai nhat la: \n";
		for (int i = X; i <= Y; i++) {
			cout << a[i] << " ";
		}
	} else {
		cout << "Khong co mang con tang dan";
	}
}

int main() {
	int N;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> N;
	int* a = new int[N + 2];
	NhapMang(a, N);
	XuatMang(a, N);

	MangCon(a, N);
	delete[] a;
	return 0;
}
