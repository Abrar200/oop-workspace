#include "Student.h"

Student::Student(const std::string& name, int id) : Person(name), id(id) {}

int Student::getId() const {
    return id;
}