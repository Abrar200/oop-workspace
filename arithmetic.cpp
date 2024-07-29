#include <iostream>
#include <string>
#include <algorithm>

// Function to add two binary numbers
std::string addBinary(const std::string &a, const std::string &b) {
    std::string result = "";
    int s = 0;          // Sum of digits
    int i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || s == 1) {
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);
        
        result = char(s % 2 + '0') + result;
        s /= 2;
        i--; j--;
    }
    
    return result;
}

// Function to subtract two binary numbers (a - b)
std::string subtractBinary(const std::string &a, const std::string &b) {
    std::string result = "";
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0) {
        int sub = ((i >= 0) ? a[i] - '0' : 0) - ((j >= 0) ? b[j] - '0' : 0) - borrow;
        
        if (sub < 0) {
            sub += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result = char(sub + '0') + result;
        i--; j--;
    }
    
    return result;
}

// Function to perform a left shift on a binary number
std::string leftShift(const std::string &a, int positions) {
    return a + std::string(positions, '0');
}

// Function to perform a right shift on a binary number
std::string rightShift(const std::string &a, int positions) {
    if (positions >= a.size()) return "0";
    return a.substr(0, a.size() - positions);
}

int main() {
    std::string a, b;
    int shift;
    
    std::cout << "Enter first binary number: ";
    std::cin >> a;
    std::cout << "Enter second binary number: ";
    std::cin >> b;
    
    std::string sum = addBinary(a, b);
    std::string difference = subtractBinary(a, b);
    
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    
    std::cout << "Enter shift amount: ";
    std::cin >> shift;
    
    std::string left_shifted = leftShift(a, shift);
    std::string right_shifted = rightShift(a, shift);
    
    std::cout << "Left Shift: " << left_shifted << std::endl;
    std::cout << "Right Shift: " << right_shifted << std::endl;

    return 0;
}
