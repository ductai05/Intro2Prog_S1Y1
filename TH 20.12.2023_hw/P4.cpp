#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

int main() {
    std::ifstream inputFile("MANG.TXT");

    if (!inputFile.is_open()) {
        std::cout << "Khong the mo MANG.TXT" << std::endl;
        return 0;
    }

    int n;
    inputFile >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        inputFile >> arr[i];
    }

    inputFile.close();

    int countSquare = 0;
    int minSquare = std::numeric_limits<int>::max();

    for (int i = 0; i < n; i++) {
        if (std::sqrt(arr[i]) == std::floor(std::sqrt(arr[i]))) {
            countSquare++;

            if (arr[i] < minSquare) {
                minSquare = arr[i];
            }
        }
    }

    std::cout << "So chinh phuong co trong mang: " << countSquare << std::endl;

    if (countSquare == 0) {
        std::cout << "Khong co so chinh phuong trong mang." << std::endl;
    }
    else {
        std::cout << "So chinh phuong nho nhat trong mang: " << minSquare << std::endl;
    }

    delete[] arr;

    return 0;
}