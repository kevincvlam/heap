#include "definitions.cpp"

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct Student{

       string firstName;
       string middleName;
       string lastName;

       int level; // changed to int for comparability.

       int reading;
       int writing;
       int conversation;
       int Java;
       int C;
       int Cpp;
       int BASIC;
       int Prolog;
       int LispScheme;
       int ML;
       int CVS;
       int CSim;
       int Maple;
       int Matlab;
       int RCS;
       int Perl;
       int Python;
       int HTML;
       int UML;
       int UnixLinux;
       int tools;
       int shell;
       int make;
       int assembly;
       int logicDesign;
       int digitalCircuits;
       int graphics;
       int webProgramming;
       int infoTheory;
       int interfaceDesign;
       int databases;
       int concurrency;
       int networks;
       int compilers;
       int statistics;
       int simulations;
       int systemsModelling;
       int numMethods;
       int business;

       int pastTAships;
       int TAhoursOwed ;
       int TAshipsWanted;
       int minWilling;
       int maxWilling;
       int minTA;
       int maxTA;

       // THESE TABLES ARE GLITCHY.  code for index 0 and 1 but not beyond ...

       int pref[NUM_COURSES]; //pref[COURSECODE] = preference for COURSECODE
       int prevAppts[NUM_COURSES]; // prevAppts[COUSECODE] = prev. appts. for COURSECODE

       /*option 1:
       vector <string> taken; // vector of taken courses
       // allows addition of courses that are not included in pool of defined courses
       */

       //option 2:
       int taken[NUM_COURSES]; // taken[COURSECODE] = grade for COURSECODE; -1 if course was not taken

       Student(){
          int i;
          for (i=0; i<NUM_COURSES; i++)    taken[i] = -1;
       }
};


#endif//STUDENT_H_INCLUDED
