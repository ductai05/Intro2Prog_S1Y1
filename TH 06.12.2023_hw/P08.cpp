//ciel_23122013 23TNT1 FIT@HCMUS
//TH_NMLT_hw 06.12.2023

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

string chuanHoaHoTen(string hoTen) {
    hoTen.erase(0, hoTen.find_first_not_of(" "));
    hoTen.erase(hoTen.find_last_not_of(" ") + 1);

    transform(hoTen.begin(), hoTen.end(), hoTen.begin(), [](unsigned char c) {
        return tolower(c);
        });
    hoTen[0] = toupper(hoTen[0]);
    for (size_t i = 1; i < hoTen.length(); i++) {
        if (hoTen[i - 1] == ' ') {
            hoTen[i] = toupper(hoTen[i]);
        }
    }

    return hoTen;
}

int main() {
    string hoTen;
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    string hoTenChuanHoa = chuanHoaHoTen(hoTen);
    cout << "Ho ten chuan hoa: " << hoTenChuanHoa << "\n";

    return 0;
}