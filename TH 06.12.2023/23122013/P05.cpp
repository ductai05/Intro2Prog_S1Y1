//ciel_23122013 23TNT1 FIT@HCMUS
//TH NMLT 06.12.2023

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string thuong(string chuoi) {
    transform(chuoi.begin(), chuoi.end(), chuoi.begin(), ::tolower);
    return chuoi;
}

string hoa(string chuoi) {
    transform(chuoi.begin(), chuoi.end(), chuoi.begin(), ::toupper);
    return chuoi;
}

string title(string chuoi) {
    bool space = true;
    for (size_t i = 0; i < chuoi.length(); i++) {
        if (space && isalpha(chuoi[i])) {
            chuoi[i] = toupper(chuoi[i]);
            space = false;
        }
        else if (isspace(chuoi[i])) {
            space = true;
        }
        else {
            chuoi[i] = tolower(chuoi[i]);
        }
    }
    return chuoi;
}

int main() {
	cout << "Nhap vao 1 chuoi: ";
	string chuoi;
    getline(cin, chuoi);

	string chuoi_thuong = thuong(chuoi);
    cout << chuoi_thuong << "\n";

	string chuoi_hoa = hoa(chuoi);
    cout << chuoi_hoa << "\n";

	string title_case = title(chuoi);
    cout << title_case << "\n";
	return 0;
}
