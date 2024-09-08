#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "Grade.h"
#include <vector>

class Gradebook {
private:
    std::vector<Grade*> grades;

public:
    Gradebook();
    ~Gradebook();
    void addGrade(int stud_id, int course_id, const std::string& assignment, int value);
};

#endif