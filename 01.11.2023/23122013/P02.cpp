//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

string DecToHex(int decimalNumber) {
    stringstream ss;
    ss << hex << decimalNumber;
    string hexadecimalNumber = ss.str();
    transform(hexadecimalNumber.begin(), hexadecimalNumber.end(), hexadecimalNumber.begin(), ::toupper);
    return hexadecimalNumber;
}

int HexToDec(string hexadecimalNumber) {
    transform(hexadecimalNumber.begin(), hexadecimalNumber.end(), hexadecimalNumber.begin(), ::tolower);
    int decimalNumber;
    stringstream ss;
    ss << hex << hexadecimalNumber;
    ss >> decimalNumber;
    return decimalNumber;
}

int main() {
    int decimalNumber;
    cout << "Nhap so thap phan: ";
    cin >> decimalNumber;

    string hexadecimalNumber = DecToHex(decimalNumber);
    cout << "So thap luc phan tuong ung: " << hexadecimalNumber << '\n';

    string hexadecimalInput;
    cout << "Nhap so thap luc phan: ";
    cin >> hexadecimalInput;

    int decimalInput = HexToDec(hexadecimalInput);
    cout << "So thap phan tuong ung: " << decimalInput << '\n';

    return 0;
}

