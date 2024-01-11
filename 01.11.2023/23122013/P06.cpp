//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	long long ans = 1;
	NhapLai:
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	if (n <= 0) {
		cout << "Xin nhap lai!\n";
		goto NhapLai;
	}
	if (n % 2 == 1) {
		for (int i = 1; i <= n; i += 2) {
			ans *= i;
		}
	}
	else {
		for (int i = 2; i <= n; i += 2) {
			ans *= i;
		}
	}
	cout << "n!! = " << ans << '\n';
	return 0;
}