#include "definitions.cpp"
#include "student.h"
#include "course.h"

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
class Input{

private:

int numTA;
int numCourses;

//vector <Student*> info;

public:

Input();

//input of txt files
vector <Student*> store_info(const char *);
vector <Course*> store_courseinfo(const char * file);

//course functions
vector <Course*> updateConstraintInfo(vector <Course*> course, vector <Student*> tainfo);


// help functions
int convert_int(string); // converts string to int

};

#endif//INPUT_H_INCLUDED
