#include <iostream>

void changeValue(double* ptr) {
    *ptr = 42;
}

void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

double arrayMax(double* arr, int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}



double* dynamicArray(int N, double M) {
    double* arr = new double[N];
    for (int i = 0; i < N; i++) {
        arr[i] = M;
    }
    return arr;
}
