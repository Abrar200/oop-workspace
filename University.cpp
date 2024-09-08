#include "University.h"
#include <iostream>

University::University(const std::string& name, const std::string& location)
    : name(name), location(location) {}

University::~University() {
    for (auto course : courses) {
        delete course;
    }
}

void University::addCourse(int id, const std::string& name) {
    courses.push_back(new Course(id, name));
    std::cout << "Course added: " << name << std::endl;
}