//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double n;
	cout << "Nhap vao so thuc can lam tron: ";
	cin >> n;
	int k;
	cout << "Nhap so chu so phan thap phan sau khi lam tron: ";
	cin >> k;
	cout << "So thap phan sau khi lam tron: " << fixed << setprecision(k) << n;
	return 0;
}