#include "student.h"

#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
class Sorting{

private:
vector <Student*> pref(vector <Student*> TA, vector <Student*> Course, int Code, int preference); // see .cpp for details.
/*
vector <Student*> prefFirst(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefSecond(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefThird(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefWill(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> prefUnwill(vector <Student*> TA, vector <Student*> Course, int Code);
*/
vector <Student*> prefLeft(vector <Student*> TA, vector <Student*> Course, int Code);

public:

void printNames(vector<Student*> x);
vector <Student*> storePref(vector <Student*> TA, vector <Student*> Course, int Code);
vector <Student*> bySeniority(vector <Student*> Course);
vector <Student*> byPrevAppts(vector <Student*> Course, int code);
vector <Student*> byScore(vector <Student*> Course, int code);

void printAssignment(vector <Student*> Course[NUM_COURSES], int level);
vector <Student*> byTAshipsOwed(vector <Student*> Course);
};

#endif//SORTING_H_INCLUDED

