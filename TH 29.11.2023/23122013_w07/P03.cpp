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

void TachMang_Chan(int a[], int* b, int n, int& b_size) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			b[j] = a[i];
			j++;
			b_size += 1;
		}
	}
}
void TachMang_Le(int a[], int* c, int n, int& c_size) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			c[j] = a[i];
			j++;
			c_size += 1;
		}
	}
}


int main() {
	int n;
	cout << "Nhap vao so phan tu cua mang. N = ";
	cin >> n;
	int* a = new int[n + 1];
	int* b = new int[n + 1];
	int* c = new int[n + 1];
	NhapMang(a, n);
	XuatMang(a, n);
	cout << "Sau khi sap xep mang A tang dan: \n";
	sort(a, a + n);
	XuatMang(a, n);
	cout << "\n";

	int b_size = 0, c_size = 0;
	TachMang_Chan(a, b, n, b_size);
	TachMang_Le(a, c, n, c_size);

	cout << "Voi mang cac so chan:\n";
	XuatMang(b, b_size);
	cout << "\n";

	cout << "Voi mang cac so le:\n";
	XuatMang(c, c_size);
	cout << "\n";

	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}