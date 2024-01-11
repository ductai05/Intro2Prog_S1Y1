//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 13.12.2023

#include <time.h>
#include <iostream>
#define max_dong 50
#define max_cot 50
using namespace std;

void NhapMaTran(int a[max_dong][max_cot], int m, int n)
{
	srand((unsigned int)time(NULL));
	cout << endl << "Random:" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 201 - 100; 
}

void XuatMaTran(int a[max_dong][max_cot], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << " " << a[i][j];
		cout << endl;
	}
}

int FindSum(int a[max_dong][max_cot], int m, int n)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
				sum += a[i][j];
	return sum;
}

bool isPrime(int x) 
{
	if (x < 2) {
		return false;
	}
	else if (x == 2){
		return true;
	}
	else {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int FindSNT(int a[max_dong][max_cot], int m, int n)
{
	int count = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (isPrime(a[i][j])) {
				count += 1;
			}
	return count;
}

void FindSoAm(int a[max_dong][max_cot], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] < 0) {
				cout << i + 1 << " ";
				break;
			}

	return;
}

int MaxChinh(int a[max_dong][max_cot], int m, int n)
{
	int max = a[0][0];
	for (int i = 0; i < m; i++) {
		if (max < a[i][i])
			max = a[i][i];
	}

	return max;
}

int MaxPhu(int a[max_dong][max_cot], int m, int n)
{
	int max = a[0][n - 1];
	for (int i = 0; i < m; i++)
	{
		int j = n - 1 - i;
		if (max < a[i][j])
			max = a[i][j];
	}
	return max;
}

void SortA(int a[max_dong][max_cot], int m, int n)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (a[i][i] > a[j][j])
			{
				int temp = a[i][i];
				a[i][i] = a[j][j];
				a[j][j] = temp;
			}
		}
	}
}

void SortB(int a[max_dong][max_cot], int m, int n)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (a[i][i] < a[j][j])
			{
				int temp = a[i][i];
				a[i][i] = a[j][j];
				a[j][j] = temp;
			}
		}
	}
}

int main()
{
	int m, n;
	int a[max_dong][max_cot];
	cout << "Nhap so dong: m = ";
	cin >> m;
	cout << "Nhap so cot: n = ";
	cin >> n;
	NhapMaTran(a, m, n);
	XuatMaTran(a, m, n);
	cout << "\n" << "Tong cac phan tu duong: " << FindSum(a, m, n) << "\n";
	cout << "\n" << "So cac so nguyen to: " << FindSNT(a, m, n) << "\n";
	cout << "\n" << "Cac dong co gia tri am: "; FindSoAm(a, m, n); cout << "\n";
	cout << "\n" << "Phan tu lon nhat tren duong cheo chinh: "; cout << MaxChinh(a, m, n) << "\n";
	cout << "\n" << "Phan tu lon nhat tren duong cheo phu: "; cout << MaxPhu(a, m, n) << "\n";

	SortA(a, m, n);
	cout << "\n\nMa tran sau khi sap xep tang dan tu tren huong xuong tren duong cheo chinh:\n";
	XuatMaTran(a, m, n);

	SortB(a, m, n);
	cout << "\n\nMa tran sau khi sap xep giam dan tu tren huong xuong tren duong cheo chinh:\n";
	XuatMaTran(a, m, n);
	return 0;
}

