#include "input.h"
#include "student.h"
#include "sorting.h"
//
/////*First Iteration of Sorting of TAs for each Course*/
////
////Sort by Guarantees Highest Hours to Lowest
////Sort by Preference 1st 2nd 3rd will unwill
////Sort by seniority
////
////Work from upper year courses down
//
//void printNames(vector<Student*> x, int i)
//{
//    int j;
//    for(j =0; j < x.size(); j++)
//    cout << i << ". " << x[i]->firstName;
//}
//
//void storePrefTA(vector <Student*> TA, vector <Student*> Course, int Code)
//{
//    //for every TA, if he/she ranks the course as 1st, append that TA to Course
//    int i;
//    for(i =0; i< TA.size(); i++)
//    {
//        if(TA[i]->pref[Code] == FIRST)
//        {
//            Course.push_back(TA[i]);
//        }
//    }
//
//}

//1. Takes the name of a file to view as the first command-line argument
int main(int argc, char* argv[]) {
    if (argc < 2) { cout << "Error: Use 1 Argument." << endl; return EXIT_FAILURE;}
    Input in;
    Sorting sort;
    vector <Student*> TAinfo;
    TAinfo = in.store_info(argv[1]);

    vector <Student*> Courses[NUM_COURSES];
    //Each course starts as an empty vector of students, and is populated with prioritized list of candidates
    Courses[CSC108H].push_back(TAinfo[0]);
    sort.printNames(Courses[CSC108H], 0);


    return 0;

}
