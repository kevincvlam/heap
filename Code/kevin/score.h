#include "student.h"

#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
class Score{

private:
//student functions



public:
vector <Student*> studentforCourse(vector <Student*> Course, int code);
int assignment(vector <Student*> tainfo, vector <Course*> course, vector <Student*> assigment[NUM_COURSES], int hours);
int guaranteedHours(vector <Student*> student);


};

#endif//SCORE_H_INCLUDED


