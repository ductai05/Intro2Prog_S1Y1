//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, k;
	NhapLai:
	cout << "Nhap so nguyen duong n, so nguyen k: ";
	cin >> n >> k;
	if (n < k || n < 0 || k < 0) {
		cout << "Du lieu dau vao sai! Nhap lai.\n";
		goto NhapLai;
	}
	n /= pow(10, k - 1);
	cout << n % 10;
	return 0;
}