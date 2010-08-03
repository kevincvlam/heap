#include "student.h"

#ifndef ASSIGN_H_INCLUDED
#define ASSIGN_H_INCLUDED
class Assign{

private:


public:

friend class Sorting;

void assign(vector <Student*> Courses[NUM_COURSES], vector <Student*> TA, vector <int> TAships);

bool constraint_guarantee(vector <Student*> Courses[NUM_COURSES]);
bool constraint_course(vector <Student*> Courses[NUM_COURSES], vector <int> TAships);

};

#endif//ASSIGN_H_INCLUDED
