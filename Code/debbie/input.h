#include "definitions.cpp"
#include "student.h"

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
class Input{
      
private:

int numTA;

vector <Student*> info;

public:

Input();

void store_info(const char *);

// help functions
int convert_int(string); // converts string to int

};

#endif//INPUT_H_INCLUDED
