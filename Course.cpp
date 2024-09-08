#include "Course.h"
#include <iostream>

Course::Course(int id, const std::string& name)
    : id(id), name(name), personCount(0), maxPersons(30) {
    persons = new Person*[maxPersons];
}

Course::~Course() {
    delete[] persons;
}

void Course::addPerson(Person* p) {
    if (personCount < maxPersons) {
        persons[personCount++] = p;
        std::cout << "Person added to course: " << p->getName() << std::endl;
    } else {
        std::cout << "Cannot add more persons. Maximum limit reached." << std::endl;
    }
}