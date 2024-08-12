#include <iostream>


int* readNumbers();
int* reverseArray(int* numbers1, int length);
bool equalsArray(int* numbers1, int* numbers2, int length);

int main() {
    int* numbers = readNumbers();
    int* reversed = reverseArray(numbers, 10);
    
    bool result = equalsArray(numbers, reversed, 10);
    
    std::cout << (result ? "true" : "false") << std::endl;
    
    delete[] numbers;
    delete[] reversed;
    
    return 0;
}