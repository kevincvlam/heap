#include "definitions.cpp"

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct Student{
       string firstName;
       string middleName;
       string lastName;
       string levelOfStudy;
       int reading;
       int writing;
       int conversation;
       int java;
       int C;
       int Cplusplus;
       int BASIC;
       int lispScheme;
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
       int Linux;
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
       int compliers;
       int statistics;
       int simulations;
       int systemsModelling;
       int numMethods;
       int business;
       int pastTAships;
       int TAshipsOwed ;
       int TAshipsWanted;
       int minWilling;
       int maxWilling;
       /* naming system gives errors here
       int HLP101H;
       string HLP101H;
       int HLP101HTAH;
       string HLP101HTAH;
       int CSC108H;
       string CSC108H;
       int CSC148H;
       string CSC148H;
       int CSC165H;
       string CSC165H;
       int CSC207H;
       string CSC207H;
       int CSC209H;
       string CSC209H;
       int CSC324H;
       string CSC324H;
       int CSC373H;
       string CSC373H;
       */
       int courses[/*NUM_COURSES*/];
};


#endif//STUDENT_H_INCLUDED
