#include <iostream>
#include "Person.h"

PersonList createPersonList(int n);

int main() {
    int n = 5;
    PersonList list = createPersonList(n);

    for (int i = 0; i < list.numPeople; ++i) {
        std::cout << "Person " << i + 1 << ": " << list.people[i].name << ", " << list.people[i].age << " years old" << std::endl;
    }

    delete[] list.people;

    return 0;
}