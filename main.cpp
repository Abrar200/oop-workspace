#include <iostream>
#include "University.h"
#include "Course.h"
#include "Student.h"
#include "Instructor.h"
#include "Gradebook.h"

int main() {
    University myUniversity("Adelaide University", "Adelaide, Australia");

    myUniversity.addCourse(101, "Introduction to Computer Science");

    Student* student = new Student("John Doe", 1001);
    Course* course = new Course(101, "Introduction to Computer Science");
    course->addPerson(student);

    Gradebook gradebook;
    gradebook.addGrade(1001, 101, "Midterm Exam", 85);

    delete student;
    delete course;

    return 0;
}