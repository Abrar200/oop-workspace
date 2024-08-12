#include <iostream>


int* readNumbers();
void hexDigits(int* numbers, int length);

int main() {
    int* numbers = readNumbers();
    hexDigits(numbers, 10);
    delete[] numbers;
    return 0;
}