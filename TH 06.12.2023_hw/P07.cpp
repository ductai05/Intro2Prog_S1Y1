//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void check(string s) {
	int a[300];
	for (int i = 0; i < 300; i++) {
		a[i] = 0;
	}
	int size = s.size();
	int id;
	for (int i = 0; i < size; i++) {
		id = s[i];
		a[id] += 1;
	}
	int maxx = 0;
	for (int i = 0; i < 300; i++) {
		if (a[i] > maxx) {
			maxx = a[i];
			id = i;
		}
	}
	cout << "Ki tu xuat hien nhieu nhat va so lan xuat hien:\n";
	cout << "Ki tu: " << char(id) << "\nSo lan: " << maxx;
}


int main() {
	string s;
	cout << "Nhap vao chuoi ki tu: ";
	getline(cin, s);
	check(s);
	return 0;
}