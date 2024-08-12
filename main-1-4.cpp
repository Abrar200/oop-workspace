#include <iostream>
#include "Person.h"

PersonList createPersonList(int n);
PersonList shallowCopyPersonList(PersonList pl);

int main() {
    int n = 3;
    PersonList originalList = createPersonList(n);
    
    std::cout << "Original list:" << std::endl;
    for (int i = 0; i < originalList.numPeople; ++i) {
        std::cout << "Person " << i + 1 << ": " << originalList.people[i].name << ", " << originalList.people[i].age << " years old" << std::endl;
    }
    
    PersonList copiedList = shallowCopyPersonList(originalList);
    
    std::cout << "\nCopied list:" << std::endl;
    for (int i = 0; i < copiedList.numPeople; ++i) {
        std::cout << "Person " << i + 1 << ": " << copiedList.people[i].name << ", " << copiedList.people[i].age << " years old" << std::endl;
    }
    
    originalList.people[0].name = "Modified Jane";
    originalList.people[0].age = 30;
    
    std::cout << "\nAfter modifying original list:" << std::endl;
    std::cout << "Original list, first person: " << originalList.people[0].name << ", " << originalList.people[0].age << " years old" << std::endl;
    std::cout << "Copied list, first person: " << copiedList.people[0].name << ", " << copiedList.people[0].age << " years old" << std::endl;
    
    delete[] originalList.people;
    
    return 0;
}