#include "input.h"
#include "student.h"
#include "sorting.h"
#include "score.h"
#include "assign.h"

//1. Takes the name of a file to view as the first command-line argument
int main(int argc, char* argv[]) {
    if (argc < 3) { cout << "Error: Use 2 Arguments." << endl; return EXIT_FAILURE;}
    Input in;
    Sorting sort;
    Score score;
    Assign assign;
    vector <Student*> TAinfo;
    TAinfo = in.store_info(argv[1]);//reads in ta_stats
    vector <int> TAships = in.store_courseinfo(argv[2]); //store enrollment for each course

    vector <Student*> Courses[NUM_COURSES];  //Each course starts as an empty vector of students


    //Store an Initial List of Students, based on preference

    sort.sort(TAinfo, Courses);
    assign.assign(Courses, TAinfo, TAships);

//    int j;
//    for(j = 0; j < NUM_COURSES; j++)
//    {
//       sort.storePref(TAinfo, Courses[j], j);
//       sort.bySeniority(Courses[j], j);
//       sort.byPrevAppts(Courses[j], j);
//       sort.byScore(Courses[j], j);
//       sort.byOwed(Courses[j]);
//    }
//    sort.printAssignment(Courses, 0);


//    //test
//   // sort.printNames(Courses[1]);
//    //sort.printAssignment(Courses, 0);
//    unsigned int k;
//    for(k=0; k < TAships.size(); k++)
//    {
//        printf("%d\n", TAships[k]);
//    }

    return 0;
}

//Potential Next Steps:
//     - make list of priority of courses (perhaps by year of study?)
//     - view TA rankings for courses in the order of list above
//       - for every course, take the first TAships[code] number of TAs
//             - for every TA that is taken for the course, subtract 54 hours from TAshipsOwed
//             - update rankings based on TAs that have been taken for the course
//     - if courses all have at least TAships[code] number of TAs
//       - [option 1] look at the course with the smallest TA:enrolment ratio and see if the next TA in rank has a guarantee
//              - if they do, assign them
//              - if not, continue to course with next lowest TA:enrolment, (TA:enrolment must be recaculated after every assignment)
//       - [option 2] for every TA who still has a guarantee after this
//              - look at the top 3 preferences, and assign them to the course out of those three that have the lowest TA:enrolment
//     - if all TAs with guarantees have been assigned and maxTA:enrolment > 2*minTA:enrolment
//              - while maxTA:enrolment > 2*minTA:enrolment, assign next TA in ranking for the course with minTA:enrolment
