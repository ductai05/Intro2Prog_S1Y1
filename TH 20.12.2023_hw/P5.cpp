#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void GiaiPT(double a, double b, double c, ofstream& output) {
    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);

        output << a << "x^2 + " << b << "x + " << c << " = 0; x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
    else if (delta == 0) {
        double x = -b / (2 * a);

        output << a << "x^2 + " << b << "x + " << c << " = 0; x = " << x << "\n";
    }
    else {
        output << a << "x^2 + " << b << "x + " << c << " = 0; VO NGHIEM" << "\n";
    }
}

int main() {
    ifstream input("PTB2.TXT");
    ofstream output("GIAIPTB2.TXT");

    if (!input.is_open()) {
        cout << "Khong the mo tap tin PTB2.TXT." << "\n";
        return 0;
    }

    if (!output.is_open()) {
        cout << "Khong the mo tap tin GIAIPTB2.TXT." << "\n";
        return 0;
    }

    int n;
    input >> n;

    for (int i = 0; i < n; i++) {
        double a, b, c;
        input >> a >> b >> c;

        GiaiPT(a, b, c, output);
    }

    input.close();
    output.close();

    return 0;
}