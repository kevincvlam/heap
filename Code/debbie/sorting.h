#include "student.h"

#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
class Sorting{

private:
void pref(vector <Student*> TA, vector <Student*> (&Course), int code, int preference);

public:

//vector <Student*>[NUM_COURSES] sort(vector <Student*> &TAinfo, vector <Student*> Courses[NUM_COURSES]);

void sort(vector <Student*> (&TAinfo), vector <Student*> (&Courses)[NUM_COURSES]);

void printNames(vector<Student*> x);
void storePref(vector <Student*> TA, vector <Student*> (&Course), int code);
void bySeniority(vector <Student*> (&Course), int code);
void byPrevAppts(vector <Student*> (&Course), int code);
void byScore(vector <Student*> (&Course), int code);
void byOwed(vector <Student*> (&Course));

void printAssignment(vector <Student*> Course[NUM_COURSES], int level);
vector <Student*> byTAshipsOwed(vector <Student*> Course);

friend class Assign;

void assign(vector <Student*> Courses[NUM_COURSES], vector <Student*> TA, vector <int> TAships);

bool constraint_guarantee(vector <Student*> Courses[NUM_COURSES]);
bool constraint_course(vector <Student*> Courses[NUM_COURSES], vector <int> TAships);


};

#endif//SORTING_H_INCLUDED

