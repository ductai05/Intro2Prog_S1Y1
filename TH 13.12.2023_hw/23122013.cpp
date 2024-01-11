//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 13.12.2023_homework

#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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

int FindMinPositive(int a[max_dong][max_cot], int m, int n)
{
	int minn = 2147483646;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (minn > a[i][j] && a[i][j] > 0) {
				minn = a[i][j];
			}
		}
	}
	return minn;
}

int FindMaxBien(int a[max_dong][max_cot], int m, int n)
{
	int maxx = a[0][0];
	for (int i = 0; i < m; i++) {
		if (maxx < a[i][0]) {
			maxx = a[i][0];
		}
		if (maxx < a[i][n - 1]) {
			maxx = a[i][n - 1];
		}
	}
	for (int j = 0; j < n; j++) {
		if (maxx < a[0][j]) {
			maxx = a[0][j];
		}
		if (maxx < a[m - 1][j]) {
			maxx = a[m - 1][j];
		}
	}
	return maxx;
}

void FindDongToanChan(int a[max_dong][max_cot], int m, int n)
{
	bool check, check2 = true;
	for (int i = 0; i < m; i++) {
		check = true;
		for (int j = 0; j < n; j++) {
			if (a[i][j] < 0) {
				//cout << a[i][j] << " ";
				check = false;
				break;
			}
		}
		if (check == true) {
			check2 = false;
			cout << i + 1 << " ";
		}
	}
	if (check2 == true) {
		cout << "\nKhong ton tai dong co toan bo la cac so chan.";
	}
	return;
}

bool DoiXung(int x) {
	string s = to_string(x);
	int s_size = s.size();
	for (int i = 0; i < s_size; i++) {
		if (s[i] != s[s_size - 1 - i]) {
			return false;
		}
	}
	return true;
}

int TongDuongDoiXung_CheoChinh(int a[max_dong][max_cot], int m, int n) 
{
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (DoiXung(a[i][i]))
			sum += a[i][i];
	}
	return sum;
}

int SoLuongDuongDoiXung_CheoPhu(int a[max_dong][max_cot], int m, int n) {
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		int j = n - 1 - i;
		if (DoiXung(a[i][j])) {
			count += 1;
		}
	}
	return count;
}

bool ChinhPhuong(int x) {
	int i = sqrt(x);
	if (i * i == x) {
		return true;
	}
	else {
		return false;
	}
}

int TongChinhPhuong_TrenCheoChinh(int a[max_dong][max_cot], int m, int n) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ChinhPhuong(a[i][j])) {
				sum += a[i][j];
			}
		}
	}
	return sum;
}

int TongChinhPhuong_DuoiCheoPhu(int a[max_dong][max_cot], int m, int n) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = n - i; j < n; j++) {
			if (ChinhPhuong(a[i][j])) {
				sum += a[i][j];
			}
		}
	}
	return sum;
}


int SoLuongYenNgua(int a[max_dong][max_cot], int m, int n) {
	int count = 0;
	vector<int> dong_m, cot_n;
	int maxx, minn;
	//YenNgua: lon nhat tren dong va nho nhat tren cot
	for (int i = 0; i < m; i++) {
		maxx = a[i][0];
		for (int j = 0; j < n; j++) {
			if (maxx < a[i][j]) {
				maxx = a[i][j];
			}
		}
		dong_m.push_back(maxx);
	}
	for (int j = 0; j < n; j++) {
		minn = a[0][j];
		for (int i = 0; i < m; i++) {
			if (minn > a[i][j]) {
				minn = a[i][j];
			}
		}
		cot_n.push_back(minn);
	}
	/*
	for (int i = 0; i < m; i++) {
		cout << dong_m[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << cot_n[i] << " ";
	}
	*/
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == dong_m[i] && a[i][j] == cot_n[j]) {
				count += 1;
			}
		}
	}
	return count;
}

bool KiemTraDuongCheo_HoangHau(int a[max_dong][max_cot], int m, int n, int i, int j) {
	const int I = i;
	const int J = j;
	// Hoang hau: lon nhat tren dong, tren cot, 2 duong cheo qua no
	// Kiem tra 2 duong cheo, di qua a[i][j]
	for (int x = I, y = J; y >= 0 && y >= 0; x--, y--) {
		if (a[x][y] > a[I][J]) {
			return false;
		}
	}
	for (int x = I, y = J; x < m && y < n; x++, y++) {
		if (a[x][y] > a[I][J]) {
			return false;
		}
	}
	for (int x = I, y = J; x < m && y >= 0; x++, y--) {
		if (a[x][y] > a[I][J]) {
			return false;
		}
	}
	for (int x = I, y = J; x >= 0 && y < n; x--, y++) {
		if (a[x][y] > a[I][J]) {
			return false;
		}
	}
	//cout << a[i][j] << " ";
	return true;
}

int SoLuongHoangHau(int a[max_dong][max_cot], int m, int n) {
	int count = 0;
	vector<int> dong_m, cot_n;
	int max1, max2;
	//  Hoang hau: lon nhat tren dong, tren cot, 2 duong cheo qua no
	for (int i = 0; i < m; i++) {
		max1 = a[i][0];
		for (int j = 0; j < n; j++) {
			if (max1 < a[i][j]) {
				max1 = a[i][j];
			}
		}
		dong_m.push_back(max1);
	}
	for (int j = 0; j < n; j++) {
		max2 = a[0][j];
		for (int i = 0; i < m; i++) {
			if (max2 < a[i][j]) {
				max2 = a[i][j];
			}
		}
		cot_n.push_back(max2);
	}
	/*
	for (int i = 0; i < m; i++) {
		cout << dong_m[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << cot_n[i] << " ";
	}
	*/

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == dong_m[i] && a[i][j] == cot_n[j]) {
				if (KiemTraDuongCheo_HoangHau(a, m, n, i, j)) {
					count++;
				}
			}
		}
	}
	return count;
}

bool CucTri(int a[max_dong][max_cot], int m, int n, int i, int j) {
	const int I = i; const int J = j;
	for (int x = I - 1; x <= I + 1; x++) {
		for (int y = J - 1; y <= J + 1; y++) {
			if (x >= 0 && x < m && y >= 0 && y < n) {
				if (a[i][j] < a[x][y]) {
					return false;
				}
			}
		}
	}
	return true;
}

int TongCacCucTri(int a[max_dong][max_cot], int m, int n) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (CucTri(a, m, n, i, j)) {
				//cout << a[i][j] << " ";
				count++;
			}
		}
	}
	return count;
}

int TanSuatCaoNhat(int a[max_dong][max_cot], int m, int n) {
	int count = 0;
	vector <int> v, ts; bool check1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			check1 = false; //chua co trong vector v
			for (auto ex : v) {
				if (ex == a[i][j]) {
					check1 = true;
					break;
				}
			}
			if (check1 == false) {
				v.push_back(a[i][j]);
				ts.push_back(0);
			}
		}
	}
	int v_size = v.size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < v_size; k++) {
				if (a[i][j] == v[k]) {
					ts[k] += 1;
				}
			}
		}
	}
	int maxx = 0, id = 0;
	for (int k = 0; k < v_size; k++) {
		if (maxx < ts[k]) {
			maxx = ts[k];
			id = k;
		}
	}
	return v[id];
}

void Swap(int& x, int& y) {
	int temp = 0;
	temp = x; 	
	x = y; 
	y = temp;
}

void Sort_TangDanDuoiLen_CheoPhu(int a[max_dong][max_cot], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		int j = n - 1 - i;
		for (int x = i + 1; x < m; x++) {
			int y = n - 1 - x;
			if (a[i][j] < a[x][y]) {
				Swap(a[i][j], a[x][y]);
			}
		}
	}
	cout << "Mang sau khi sap xep tang dan tu duoi huong len, tren duong cheo phu:\n";
	XuatMaTran(a, m, n);
	cout << "\n";
	return;
}

void Sort_GiamDanDuoiLen_CheoPhu(int a[max_dong][max_cot], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		int j = n - 1 - i;
		for (int x = i + 1; x < m; x++) {
			int y = n - 1 - x;
			if (a[i][j] > a[x][y]) {
				Swap(a[i][j], a[x][y]);
			}
		}
	}
	cout << "Mang sau khi sap xep giam dan tu duoi huong len, tren duong cheo phu:\n";
	XuatMaTran(a, m, n);
	cout << "\n";
	return;
}
/*
	for (int i = 0; i < n; i++) {
		a[0][i];
	}
	for (int i = 1; i < m - 1; i++) {
		a[i][n - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		a[m - 1][i];
	}
	for (int i = m - 1; i >= 1; i--) {
		a[i][0];
	}
*/

void Sort_KimDongHo_Bien(int a[max_dong][max_cot], int m, int n) {

	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(a[0][i]);
	}
	for (int i = 1; i < m - 1; i++) {
		v.push_back(a[i][n - 1]);
	}
	for (int i = n - 1; i >= 0; i--) {
		v.push_back(a[m - 1][i]);
	}
	for (int i = m - 1; i >= 1; i--) {
		v.push_back(a[i][0]);
	}

	sort(v.begin(), v.end());

	int id = 0;
	for (int i = 0; i < n; i++) {
		a[0][i] = v[id];
		id++;
	}
	for (int i = 1; i < m - 1; i++) {
		a[i][n - 1] = v[id];
		id++;
	}
	for (int i = n - 1; i >= 0; i--) {
		a[m - 1][i] = v[id];
		id++;
	}
	for (int i = m - 1; i >= 1; i--) {
		a[i][0] = v[id];
		id++;
	}

	cout << "Mang sau khi sap xep cac gia tri nam tren bien ma tran tang dan" 
		 << " theo chieu kim dong ho : \n";
	XuatMaTran(a, m, n);
	return;
}

void CopyMang(int a[max_dong][max_cot], int og[max_dong][max_cot], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			og[i][j] = a[i][j];
		}
	}
}

int main()
{
	int m, n;
	int a[max_dong][max_cot];
	int og[max_dong][max_cot];
	cout << "Nhap so dong: m = ";
	cin >> m;
	cout << "Nhap so cot: n = ";
	cin >> n;
	NhapMaTran(a, m, n);
	CopyMang(a, og, m, n);
	XuatMaTran(a, m, n);
	//1 Tìm số dương nhỏ nhất trong ma trận
	cout << "\n" << "So duong nho nhat trong ma tran: " << FindMinPositive(a, m, n);
	//2 Tìm số lớn nhất trên biên ma trận
	cout << "\n" << "So lon nhat tren bien ma tran: " << FindMaxBien(a, m, n);
	//3 Liệt kê các dòng chứa toàn số chẵn trong ma trận
	cout << "\n" << "Cac dong chua toan so chan trong ma tran: ";
	FindDongToanChan(a, m, n);
	cout << "\n";
	//4 Tính tổng các phần tử là số dương đối xứng nằm trên đường chéo chính
	cout << "\n" << "Tong cac phan tu la so duong doi xung nam tren duong cheo chinh: " 
		 << TongDuongDoiXung_CheoChinh(a, m, n);
	//5 Đếm số lượng phần tử là số dương đối xứng nằm trên đường chéo phụ. 
	cout << "\n" << "So luong cac phan tu la so duong doi xung nam tren duong cheo phu: "
		<< SoLuongDuongDoiXung_CheoPhu(a, m, n);
	//6 Tính tổng các phần tử là: 
	//   số chính phương nằm phía trên đường chéo chính.  
	cout << "\n" << "Tong cac phan tu la so chinh phuong tren duong cheo chinh: "
		<< TongChinhPhuong_TrenCheoChinh(a, m, n);
	//   số chính phương nằm phía dưới đường chéo phụ. 
	cout << "\n" << "Tong cac phan tu la so chinh phuong duoi duong cheo phu: "
		<< TongChinhPhuong_DuoiCheoPhu(a, m, n);
	//7 Đếm số lượng giá trị “Yên ngựa” trên ma trận. Một phần tử được gọi là 
	//  “yên  ngựa” khi nó lớn nhất trên dòng và nhỏ nhất trên cột. 
	cout << "\n" << "So luong yen ngua: "
		<< SoLuongYenNgua(a, m, n);
	//8 Đếm số lượng giá trị “Hoàng hậu” trên ma trận. Một phần tử được gọi là
	//  hoàng hậu khi nó lớn nhất trên dòng, trên cột và hai đường chéo đi qua nó.   
	cout << "\n" << "So luong hoang hau: "
		<< SoLuongHoangHau(a, m, n);
	//9 Tính tổng các phần tử cực trị trong ma trận. Một phần tử gọi là cực trị
	//  khi nó lớn hơn các phần tử xung quanh hoặc nhỏ hơn các phần tử xung quanh
	cout << "\n" << "Tong cac phan tu cuc tri: "
		<< TongCacCucTri(a, m, n);
	//10 Tìm giá trị xuất hiện nhiều nhất trong ma trận số nguyên
	cout << "\n" << "Gia tri xuat hien nhieu nhat trong ma tran so nguyen: "
		<< TanSuatCaoNhat(a, m, n);
	cout << "\n\n";
	//11 Sắp xếp các phần tử trên đường chéo phụ theo thứ tự: 
	// tăng dần từ dưới hướng lên
	Sort_TangDanDuoiLen_CheoPhu(a, m, n);
	//giảm dần từ dưới hướng lên
	Sort_GiamDanDuoiLen_CheoPhu(a, m, n);
	//12 Sắp xếp các giá trị nằm trên biên ma trận tăng dần theo chiều kim đồng hồ. 
	Sort_KimDongHo_Bien(og, m, n);
	return 0;
}

//ciel_23TNT1