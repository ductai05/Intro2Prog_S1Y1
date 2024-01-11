//ciel_23122013 23TNTN1 FIT@HCMUS
// TH NMLT 01.01.2023

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string binaryToHexadecimal(string binary) {
    string hexadecimal = "";

    int padding = binary.length() % 4;
    if (padding > 0) {
        binary = string(4 - padding, '0') + binary;
    }

    for (int i = 0; i < binary.length(); i += 4) {
        string segment = binary.substr(i, 4);

        int decimal = 0;
        for (int j = 0; j < segment.length(); j++) {
            decimal = decimal * 2 + (segment[j] - '0');
        }

        if (decimal < 10) {
            hexadecimal += to_string(decimal);
        }
        else {
            char hexChar = 'A' + (decimal - 10);
            hexadecimal += hexChar;
        }
    }

    return hexadecimal;
}

string hexadecimalToBinary(string hexadecimal) {
    string binary = "";

    for (int i = 0; i < hexadecimal.length(); i++) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            int decimal = hexadecimal[i] - '0';

            string segment = "";
            while (decimal > 0) {
                segment = to_string(decimal % 2) + segment;
                decimal /= 2;
            }

            if (i > 0 && segment.length() < 4) {
                segment = string(4 - segment.length(), '0') + segment;
            }

            binary += segment;
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            int decimal = hexadecimal[i] - 'A' + 10;

            string segment = "";
            while (decimal > 0) {
                segment = to_string(decimal % 2) + segment;
                decimal /= 2;
            }

            if (i > 0 && segment.length() < 4) {
                segment = string(4 - segment.length(), '0') + segment;
            }

            binary += segment;
        }
    }

    return binary;
}

int main() {
    string binaryNumber;
    cout << "Nhap so nhi phan: ";
    cin >> binaryNumber;
    string hexadecimalResult = binaryToHexadecimal(binaryNumber);
    cout << "So thap luc phan tuong ung la: " << hexadecimalResult << '\n';

    string hexadecimalNumber;
    cout << "Nhap so thap luc phan: ";
    cin >> hexadecimalNumber;
    string binaryResult = hexadecimalToBinary(hexadecimalNumber);
    cout << "So nhi phan tuong ung la: " << binaryResult << '\n'; 

    return 0;
}