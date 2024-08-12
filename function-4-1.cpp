#include <iostream>
#include <climits>
#include <algorithm>

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

int secondSmallestSum(int* numbers, int length) {
    if (length <= 1) {
        return INT_MAX;
    }

    long long smallest = LLONG_MAX;
    long long secondSmallest = LLONG_MAX;

    for (int start = 0; start < length; ++start) {
        long long sum = 0;
        for (int end = start; end < length; ++end) {
            sum += numbers[end];
            if (sum < smallest) {
                secondSmallest = smallest;
                smallest = sum;
            } else if (sum < secondSmallest && sum != smallest) {
                secondSmallest = sum;
            }
        }
    }

    return (secondSmallest == LLONG_MAX) ? smallest : secondSmallest;
}