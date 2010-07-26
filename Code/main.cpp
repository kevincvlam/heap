#include "input.h"
#include "student.h"
#include "sorting.h"

//1. Takes the name of a file to view as the first command-line argument
int main(int argc, char* argv[]) {
    if (argc < 2) { cout << "Error: Use 1 Argument." << endl; return EXIT_FAILURE;}
    Input in;
    Sorting sort;
    vector <Student*> TAinfo;
    TAinfo = in.store_info(argv[1]); //reads in ta_stats
    vector <Student*> Courses[NUM_COURSES];  //Each course starts as an empty vector of students


    //Store an Initial List of Students, based on preference
    int j;
    for(j = 0; j < NUM_COURSES; j++)
    {
    Courses[j] = sort.storePref(TAinfo, Courses[j], j);
    Courses[j] = sort.bySeniority(Courses[j]); //sort the new list by seniority
    Courses[j] = sort.byPrevAppts(Courses[j], j);
    Courses[j] = sort.byTAshipsOwed(Courses[j]);
    }

    //test
    sort.printNames(Courses[1]);
    sort.printAssignment(Courses, 1);
    return 0;

}
