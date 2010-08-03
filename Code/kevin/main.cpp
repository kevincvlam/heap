#include "input.h"
#include "student.h"
#include "sorting.h"
#include "score.h"



int assign(vector <Student*> TAinfo, vector <Course*> courseinfo, vector <Student*> assignment[NUM_COURSES], int gHours)
{
    //Function Objects
    Input in;
    Sorting sort;
    Score score;

    if(score.assignment(TAinfo, courseinfo, assignment, gHours) < 500) {return 0;}

    else{return 1;}

    //check all possibilities

    //make an assignment
    //assign TA to most constrained course


    //remove TA from set of possibilities in that course

//    if(solve(assignment)
//    {
//        printAssignment
//        return 1;
//    }
    return 0;
}

//1. Takes the name of a file to view as the first command-line argument
int main(int argc, char* argv[]) {
    if (argc < 3) { cout << "Error: Use 1 Argument." << endl; return EXIT_FAILURE;}
    /** Initialization of Objects and Storing of Information **/

    //Function Objects
    Input in;
    Sorting sort;
    Score score;

    //Reference Objects
    vector <Student*> TAinfo;
    TAinfo = in.store_info(argv[1]);//reads in ta_stats
    vector <Course*> courseinfo = in.store_courseinfo(argv[2]); //store enrollment for each course
    courseinfo = in.updateConstraintInfo(courseinfo, TAinfo);
    int gHours = score.guaranteedHours(TAinfo);

    //Active Objects
    vector <Student*> assignment[courseinfo.size()];
    vector <Student*> candidates[courseinfo.size()];
    unsigned int l;
    unsigned int p;
    //create a full list of all TAs, coressponding to each Course
    for(l =0; l<courseinfo.size(); l++)
    {
        for(p =0; p <TAinfo.size(); p++)
        {
            candidates[l].push_back(TAinfo[p]);
        }
    }



   /** Prints out the Course Data **/
    unsigned int i;
    for(i =0; i< courseinfo.size(); i++)
    {
        cout << courseinfo[i]->id << ". " << courseinfo[i]->code << endl;
        cout << "Enrolled: " << courseinfo[i]->enrolled << " TAships: " << courseinfo[i]->TAships << endl;
        cout << "Freedom: " << courseinfo[i]->freedom << endl;
        cout << "numPref1st: " << courseinfo[i]->numPref1st << endl;
        cout << "Level: " << courseinfo[i]->level << endl;
    }

  /** Make a Dummy Assignment **/
//  unsigned int j;
//  unsigned int q;
//  unsigned int k = 0;
//  for(j =0; j < courseinfo.size(); j++)
//  {
//      for(q = 0; q <5; q++)
//      {
//          assignment[j].push_back(TAinfo[k++]);
//      }
//  }
//  sort.printAssignment(assignment, 0);
//  cout << "The fitness of this assignment is: " << score.assignment(TAinfo, courseinfo, assignment, gHours) << endl;





    return 0;
}
