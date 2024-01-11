//N5 23TNT1 FIT@HCMUS
// LT NMLT 08.11.2023

#include <iostream>

using namespace std;

void Bai1() {
	long long n; double x;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	cout << "Nhap vao so thuc x: ";
	cin >> x;
	double S = 1;
	if (n == 0) {
		cout << "S = 1\n";
	}
	else {
		double temp = 1;
		for (long long i = 1; i <= n; i++) {
			temp *= x / i;
			S += temp;
		}
	}
	cout << "S = " << S << "\n";
	return;
}

void oneNumb(int x)
{
	string s[] = { "khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin" };
	cout << s[x];
}

void twoNumb(int x)
{
	string s[] = { "", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi" };
	cout << s[x / 10];
	if (x % 10 != 0)
	{
		if (x % 10 == 5)
			cout << " lam";
		else cout << " ", oneNumb(x % 10);
	}
}

void threeNumb(int x)
{
	string s[] = { "", "mot tram", "hai tram", "ba tram", "bon tram", "nam tram", "sau tram", "bay tram", "tam tram", "chin tram" };

	int tram = x / 100, chuc = x / 10 % 10, donvi = x % 10;
	cout << s[tram];
	if (chuc != 0 || donvi != 0)
	{
		if (chuc == 0)
		{
			cout << " linh ";
			oneNumb(donvi);
		}
		else
		{
			cout << " ";
			twoNumb(x % 100);
		}
	}
}

void Bai2() {
	int n = 0;
	// 
	cout << "Nhap so nguyen (1 chu so): ";
	cin >> n;
	oneNumb(n);
	cout << '\n';
	//
	cout << "Nhap so nguyen (2 chu so): ";
	cin >> n;
	twoNumb(n);
	cout << '\n';
	//
	cout << "Nhap so nguyen (3 chu so): ";
	cin >> n;
	threeNumb(n);
	cout << '\n';
}

int main() {
	Bai1();
	cout << '\n';
	Bai2();
	return 0;
}