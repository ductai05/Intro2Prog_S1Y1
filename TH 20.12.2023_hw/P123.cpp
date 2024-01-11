#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct PHANSO{
	int tu;
	int mau;
};

typedef struct POINT {
	int x;
	int y;
};

void NhapPhanSo(PHANSO& p) {
	int a, b;
	NhapLai:
	cout << "Nhap tu so: ";
	cin >> a;
	cout << "Nhap mau so: ";
	cin >> b;
	if (b == 0) {
		cout << "\nNhap lai!\n";
		goto NhapLai;
	}
	p.tu = a;
	p.mau = b;
}

void XuatPhanSo(PHANSO& p) {
	cout << p.tu << " / " << p.mau << " ";
}

void NhapDiem(POINT& p) {
	int a, b;
	cout << "Nhap hoanh do: x = ";
	cin >> a;
	cout << "Nhap tung do: y = ";
	cin >> b;
	p.x = a;
	p.y = b;
}

void XuatDiem(POINT& p) {
	cout << "(" << p.x << " ; " << p.y << ") ";
}

int GCD(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

PHANSO RutGon(PHANSO& phanso) {
	int gcd = GCD(phanso.tu, phanso.mau);
	phanso.tu /= gcd;
	phanso.mau /= gcd;
	if (phanso.tu * phanso.mau < 0) {
		phanso.tu = abs(phanso.tu) * (-1);
		phanso.mau = abs(phanso.mau);
	}
	return phanso;
}

int AmDuong(PHANSO phanso) {
	phanso = RutGon(phanso);
	if (phanso.tu == 0) {
		return 0;
	}
	if (phanso.tu > 0 && phanso.mau > 0) {
		return 1;
	}
	else if (phanso.tu < 0 && phanso.mau < 0) {

	}
	else {
		return -1;
	}
}

int SoSanh(PHANSO phanso1, PHANSO phanso2) {
	RutGon(phanso1);
	RutGon(phanso2);

	if (AmDuong(phanso1) < AmDuong(phanso2)) {
		return -1;
	}
	else if (AmDuong(phanso1) > AmDuong(phanso2)) {
		return 1;
	}
	// Cung tinh am duong

	if (phanso1.tu * phanso2.mau > phanso2.tu * phanso1.mau) {
		return 1;
	}
	else if (phanso1.tu * phanso2.mau < phanso2.tu * phanso1.mau) {
		return -1;
	}
	else {
		return 0;
	}
}


void ToiGianMang(PHANSO mphanso[], int so_luong) {
	int n = so_luong;
	for (int i = 0; i < n; i++) {
		mphanso[i] = RutGon(mphanso[i]);
	}
}

PHANSO PSDuongNhoNhat(PHANSO mphanso[], int so_luong) {
	int n = so_luong;
	PHANSO Min;
	Min.tu = 10000;
	Min.mau = 1;
	for (int i = 0; i < n; i++) {
		if (AmDuong(mphanso[i]) == 1) {
			mphanso[i] = RutGon(mphanso[i]);
			if (SoSanh(Min, mphanso[i]) == 1) {
				Min = mphanso[i];
			}
		}
	}
	return Min;
}

PHANSO PSAmLonNhat(PHANSO mphanso[], int so_luong) {
	int n = so_luong;
	PHANSO Max;
	Max.tu = -10000;
	Max.mau = 1;
	for (int i = 0; i < n; i++) {
		if (AmDuong(mphanso[i]) == -1) {
			mphanso[i] = RutGon(mphanso[i]);
			if (SoSanh(mphanso[i], Max) == 1) {
				Max = mphanso[i];
			}
		}
	}
	return Max;
}

void MauSoGiamDan(PHANSO mphanso[], int so_luong) {
	int n = so_luong;
	PHANSO temp;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (mphanso[i].mau < mphanso[j].mau) {
				temp = mphanso[i];
				mphanso[i] = mphanso[j];
				mphanso[j] = temp;
			}
		}
	}
}

int SoDiemHoanhDoDuong(POINT mpoint[], int so_luong) {
	int n = so_luong;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (mpoint[i].x > 0) {
			ans++;
		}
	}
	return ans;
}

POINT TungDoLonNhat(POINT mpoint[], int so_luong) {
	int n = so_luong;
	POINT ans = mpoint[0];
	for (int i = 0; i < n; i++) {
		if (mpoint[i].y > ans.y) {
			ans = mpoint[i];
		}
	}
	return ans;
}

POINT GanGocToaDo(POINT mpoint[], int so_luong) {
	int n = so_luong;
	POINT ans = mpoint[0];
	double d = sqrt(mpoint[0].x * mpoint[0].x + mpoint[0].y * mpoint[0].y);
	for (int i = 0; i < n; i++) {
		if (sqrt(mpoint[i].x * mpoint[i].x + mpoint[i].y * mpoint[i].y) < d) {
			ans = mpoint[i];
		}
	}
	return ans;
}

void HaiDiemGanNhat(POINT mpoint[], int so_luong, POINT& A, POINT& B) {
	int n = so_luong;
	A = mpoint[0];
	B = mpoint[1];
	double d = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	double dis = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dis = sqrt((mpoint[i].x - mpoint[j].x) * (mpoint[i].x - mpoint[j].x)
				+ (mpoint[i].y - mpoint[j].y) * (mpoint[i].y - mpoint[j].y));
			if (dis < d) {
				A = mpoint[i];
				B = mpoint[j];
				d = dis;
			}
		}
	}
}

void HaiDiemXaNhat(POINT mpoint[], int so_luong, POINT& A, POINT& B) {
	int n = so_luong;
	A = mpoint[0];
	B = mpoint[1];
	double d = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
	double dis = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dis = sqrt((mpoint[i].x - mpoint[j].x) * (mpoint[i].x - mpoint[j].x)
				+ (mpoint[i].y - mpoint[j].y) * (mpoint[i].y - mpoint[j].y));
			if (dis > d) {
				A = mpoint[i];
				B = mpoint[j];
				d = dis;
			}
		}
	}
}

void Cau1() {
	PHANSO p1, p2;
	cout << "Nhap vao 2 phan so: \n";
	NhapPhanSo(p1);
	NhapPhanSo(p2);
	p1 = RutGon(p1); p2 = RutGon(p2);
	cout << "2 phan so sau khi rut gon:\n";
	XuatPhanSo(p1); cout << " va ";
	XuatPhanSo(p2); cout << "\n";
	if (AmDuong(p1) == -1) {
		cout << "Phan so thu nhat am\n";
	}
	else if (AmDuong(p1) == 1) {
		cout << "Phan so thu nhat duong\n";
	}
	else {
		cout << "Phan so thu nhat bang 0\n";
	}
	if (AmDuong(p2) == -1) {
		cout << "Phan so hai nhat am\n";
	}
	else if (AmDuong(p2) == 1) {
		cout << "Phan so hai nhat duong\n";
	}
	else {
		cout << "Phan so hai nhat bang 0\n";
	}
	cout << "\n";
	return;
}

void Cau2() {
	int n;
	cout << "Nhap vao so phan tu trong mang: ";
	cin >> n;
	PHANSO temp;
	PHANSO* mphanso = new PHANSO[n + 1];
	
	for (int i = 0; i < n; i++) {
		cout << "Phan so thu " << i + 1 << ": \n";
		NhapPhanSo(mphanso[i]);
	}

	bool CoDuong = false, CoAm = false;
	for (int i = 0; i < n; i++) {
		if (AmDuong(mphanso[i]) == 1) {
			CoDuong = true;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (AmDuong(mphanso[i]) == -1) {
			CoAm = true;
			break;
		}
	}

	cout << "Cac phan so da nhap:\n";
	for (int i = 0; i < n; i++) {
		XuatPhanSo(mphanso[i]);
		cout << "; ";
	}
	for (int i = 0; i < n; i++) {
		RutGon(mphanso[i]);
	}
	cout << "\nRut gon tat ca phan so.\n";
	for (int i = 0; i < n; i++) {
		XuatPhanSo(mphanso[i]);
		cout << "; ";
	}
	cout << "\nPhan so duong nho nhat:\n";
	if (CoDuong) {
		temp = PSDuongNhoNhat(mphanso, n);
		XuatPhanSo(temp);
	}
	else {
		cout << "Khong ton tai phan so duong.\n";
	}
	cout << "\nPhan so am lon nhat:\n";
	if (CoAm) {
		temp = PSAmLonNhat(mphanso, n);
		XuatPhanSo(temp);
	}
	else {
		cout << "Khong ton tai phan so am.\n";
	}
	cout << "\nSap xep cac phan so theo thu tu mau so giam dan:\n";
	MauSoGiamDan(mphanso, n);
	for (int i = 0; i < n; i++) {
		XuatPhanSo(mphanso[i]);
		cout << "; ";
	}
	cout << "\n";
	delete[] mphanso;
	return;
}

void Cau3() {
	int n;
	cout << "Nhap vao so diem tren mat phang: ";
	cin >> n;
	POINT temp, temp1, temp2;
	POINT* mp = new POINT[n + 1];
	for (int i = 0; i < n; i++) {
		cout << "Diem thu " << i + 1 << ": \n";
		NhapDiem(mp[i]);
	}
	cout << "Cac diem da nhap:\n";
	for (int i = 0; i < n; i++) {
		XuatDiem(mp[i]);
	}
	cout << "\nSo luong diem co hoanh do duong: " << SoDiemHoanhDoDuong(mp, n) << " \n";
	cout << "Diem co tung do lon nhat: \n";
	temp = TungDoLonNhat(mp, n);
	XuatDiem(temp);
	cout << "\nDiem gan goc toa do (0;0) nhat: \n";
	temp = GanGocToaDo(mp, n);
	XuatDiem(temp);
	HaiDiemGanNhat(mp, n, temp1, temp2);
	cout << "\nDiem gan nhau nhat: \n";
	XuatDiem(temp1); cout << " va "; XuatDiem(temp2);
	HaiDiemXaNhat(mp, n, temp1, temp2);
	cout << "\nDiem xa nhau nhat: \n";
	XuatDiem(temp1); cout << " va "; XuatDiem(temp2);
	return;
}

int main() {
	cout << "Cau 1:\n";
	Cau1();
	cout << "Cau 2:\n";
	Cau2();
	cout << "Cau 3:\n";
	Cau3();
	return 0;
}