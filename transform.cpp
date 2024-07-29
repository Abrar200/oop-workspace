#include <iostream>
#include <vector>
#include <algorithm>

// Function to convert a decimal number to binary
std::string decimalToBinary(int num) {
    if (num == 0) return "0";
    
    std::vector<int> binary_digits;
    
    while (num > 0) {
        int remainder = num % 2;
        binary_digits.push_back(remainder);
        num /= 2;
    }
    
    // Reverse the digits to get the correct binary representation
    std::reverse(binary_digits.begin(), binary_digits.end());
    
    // Convert the vector to a string
    std::string binary_str;
    for (int digit : binary_digits) {
        binary_str += std::to_string(digit);
    }
    
    return binary_str;
}

int main() {
    int num;
    std::cout << "Enter a decimal number: ";
    std::cin >> num;
    
    std::string binary = decimalToBinary(num);
    std::cout << "Binary representation: " << binary << std::endl;
    
    return 0;
}
