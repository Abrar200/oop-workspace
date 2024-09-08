#include "Gradebook.h"
#include <iostream>

Gradebook::Gradebook() {}

Gradebook::~Gradebook() {
    for (auto grade : grades) {
        delete grade;
    }
}

void Gradebook::addGrade(int stud_id, int course_id, const std::string& assignment, int value) {
    grades.push_back(new Grade(stud_id, course_id, assignment, value));
    std::cout << "Grade added for student ID " << stud_id << " in course ID " << course_id << std::endl;
}