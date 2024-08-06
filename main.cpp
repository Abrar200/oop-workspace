#include <iostream>

void changeValue(double* ptr);
void printArray(double* arr, int size);
double arrayMax(double* arr, int size);
double* dynamicArray(int N, double M);

int main() {
    double num = 10.5;
    std::cout << "Before changeValue: " << num << std::endl;
    changeValue(&num);
    std::cout << "After changeValue: " << num << std::endl;

    double staticArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int staticSize = sizeof(staticArray) / sizeof(staticArray[0]);
    std::cout << "Static array contents: ";
    printArray(staticArray, staticSize);

    std::cout << "Maximum value in static array: " << arrayMax(staticArray, staticSize) << std::endl;

    int dynamicSize = 5;
    double initValue = 3.14;
    double* dynamicArr = dynamicArray(dynamicSize, initValue);
    
    std::cout << "Dynamic array contents: ";
    printArray(dynamicArr, dynamicSize);
    
    std::cout << "Maximum value in dynamic array: " << arrayMax(dynamicArr, dynamicSize) << std::endl;

    delete[] dynamicArr;

    return 0;
}

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
