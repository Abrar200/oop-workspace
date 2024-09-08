#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Person.h"

class Course {
private:
    std::string name;
    int id;
    Person** persons;
    int personCount;
    int maxPersons;

public:
    Course(int id, const std::string& name);
    ~Course();
    void addPerson(Person* p);
};

#endif