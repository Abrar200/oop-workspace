#include "Grade.h"

Grade::Grade(int stud_id, int course_id, const std::string& assignment, int value)
    : student_id(stud_id), course_id(course_id), assignment(assignment), value(value) {}