#include <iostream>
#include <iomanip>

int* readNumbers() {
    int* numbers = new int[10];
    for (int i = 0; i < 10; ++i) {
        std::cin >> numbers[i];
    }
    return numbers;
}

void printNumbers(int* numbers, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << i << " " << numbers[i] << std::endl;
    }
}

void hexDigits(int* numbers, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << i << " " << numbers[i] << " ";
        switch (numbers[i]) {
            case 0: std::cout << "0"; break;
            case 1: std::cout << "1"; break;
            case 2: std::cout << "2"; break;
            case 3: std::cout << "3"; break;
            case 4: std::cout << "4"; break;
            case 5: std::cout << "5"; break;
            case 6: std::cout << "6"; break;
            case 7: std::cout << "7"; break;
            case 8: std::cout << "8"; break;
            case 9: std::cout << "9"; break;
            case 10: std::cout << "A"; break;
            case 11: std::cout << "B"; break;
            case 12: std::cout << "C"; break;
            case 13: std::cout << "D"; break;
            case 14: std::cout << "E"; break;
            case 15: std::cout << "F"; break;
            default: std::cout << "Invalid input";
        }
        std::cout << std::endl;
    }
}