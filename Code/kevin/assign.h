#include "definitions.cpp"
#include "student.h"

#ifndef ASSIGN_H_INCLUDED
#define ASSIGN_H_INCLUDED
class Assign{

private:

Assign(vector <Student*> Courses[NUM_COURSES], vector <Student*> TA, vector <int> TAships);

bool constraint_guarantee(vector <Student*> Courses[NUM_COURSES]);
bool constraint_course(vector <Student*> Courses[NUM_COURSES], vector <int> TAships);

public:


};

#endif//ASSIGN_H_INCLUDED
