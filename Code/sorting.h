#include "student.h"

#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
class Sorting{

private:
vector <Student*> prefFirst(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefSecond(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefThird(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefWill(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefUnwill(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefLeft(vector <Student*> TA, vector <Student*> Course, int Code);
public:





void printNames(vector<Student*> x);
vector <Student*> storePref(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> bySeniority(vector <Student*> Course);
vector <Student*> byPrevAppts(vector <Student*> Course, int code);
void printAssignment(vector <Student*> Course[NUM_COURSES], int level);
};

#endif//SORTING_H_INCLUDED

