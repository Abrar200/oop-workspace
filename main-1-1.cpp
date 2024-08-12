#include <iostream>
#include "Person.h"

Person* createPersonArray(int n);

int main() {
    int n = 5;
    Person* people = createPersonArray(n);

    
    for (int i = 0; i < n; ++i) {
        std::cout << "Person " << i + 1 << ": " << people[i].name << ", " << people[i].age << std::endl;
    }

    
    delete[] people;

    return 0;
}