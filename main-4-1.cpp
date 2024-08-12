#include <iostream>


int* readNumbers();
int secondSmallestSum(int* numbers, int length);

int main() {
    int* numbers = readNumbers();
    
    int result = secondSmallestSum(numbers, 10);
    
    std::cout << "The second smallest sum is: " << result << std::endl;
    
    delete[] numbers;
    
    return 0;
}