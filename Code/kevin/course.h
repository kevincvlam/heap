#include "definitions.cpp"

#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

struct Course{

//course descriptors
string code;
unsigned int id;
unsigned int TAships;
unsigned int enrolled;
unsigned int level;

//constraint determiners
unsigned int numPref1st; // number of tas who have put 1st preference on this course
unsigned int numPref2nd;
unsigned int numPref3rd;
unsigned int numPrefPref;
unsigned int numPrefWill;
unsigned int numPrefUnwill;
unsigned int constraints;

int freedom; //the constraint score of the course, lower fredom = more constraint; higher freedom = less constrainted



       Course (){
           TAships = 4;
           enrolled = 0;
           numPref1st = 0;
           numPref2nd = 0;
           numPref3rd = 0;
           numPrefPref = 0;
           numPrefWill = 0;
           numPrefUnwill = 0;
           constraints = 0;
           freedom = 0;
       }
};


#endif//COURSE_H_INCLUDED

