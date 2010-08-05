#include "input.h"
#include "student.h"
#include "sorting.h"
#include "score.h"

// finds course with lowest freedom (= most constrained)
int mostConstrainedCourse(vector <Course*> courseinfo)
{
    unsigned int k;
    int min = 999999999;
    int minid = 0;
    for(k=0; k< courseinfo.size(); k++)
    {
        if(courseinfo[k]->constraints < min){
        min = courseinfo[k]->constraints;
        minid = courseinfo[k]->id;}
    }
    return minid;
}

//removes candidate from vector and returns removed candidate
vector <Student*> removeCandidate(vector <Student*> candidates, unsigned int id)
{
    unsigned int k;
    for(k = 0; k< candidates.size(); k++)
    {
        if(id == candidates[k]->id)
        {
            candidates.erase(candidates.begin()+k);
        }
    }
    return candidates;
}

int coursesStillNeedTAS(vector <Course*> courseinfo)
{
    unsigned int i;
    for(i=0; i<courseinfo.size(); i++)
    {
        if(courseinfo[i]->TAships != 0)
        return 1;
    }
    return 0;
}

// recursive assignment funcion
// returns 1 if success, 0 if fail
int assign(vector <Student*> TAinfo, vector <Course*> courseinfo, vector <Student*> candidates[NUM_COURSES], vector <Student*> assignment[NUM_COURSES], int gHours)
{
    //Function Objects
    Input in;
    Sorting sort;
    Score score;

    //check all possibilities
    //make an assignment
    //assign TA to most constrained course
    //remove TA from set of possibilities in that course
    unsigned int i;
    unsigned int id = mostConstrainedCourse(courseinfo);

    //if no candidates break;
    if(candidates[id].size() == 0)
    { return 0; }

    //if score is > 500 return 1;
    else if(score.assignment(TAinfo, courseinfo, assignment, gHours) > 500) {return 1;}

    for(i=0; i< candidates[id].size(); i++)
    {
        assignment[id].push_back(TAinfo[i]);
        candidates[id] = removeCandidate(candidates[id], TAinfo[i]->id);
        courseinfo[id]->TAships--;
        courseinfo = in.updateConstraintInfo(courseinfo, TAinfo);
        TAinfo[i]->TAhoursOwed -= 54;

        if(assign(TAinfo, courseinfo, candidates, assignment, gHours))
        {
        sort.printAssignment(assignment, 0);
        return 1;
        }
    }


    return 0;
}

//1. Takes the name of a file to view as the first command-line argument
int main(int argc, char* argv[]) {
    if (argc < 3) { cout << "Error: Use 2 Argument." << endl; return EXIT_FAILURE;}
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
    int gHours = score.guaranteedHours(TAinfo); // hours owed to students in deparatment

    //Active Objects
    vector <Student*> assignment[courseinfo.size()]; // final assignment
    vector <Student*> candidates[courseinfo.size()]; // ranked list of candidates
    unsigned int l;
    unsigned int p;
    unsigned int k;
    //create a full list of all TAs, coressponding to each Course
    for(k = 0; k < NUM_COURSES; k++)
    {
       sort.storePref(TAinfo, candidates[k], k);
       sort.bySeniority(candidates[k], k);
       sort.byPrevAppts(candidates[k], k);
       sort.byScore(candidates[k], k);
       sort.byOwed(candidates[k]);

    }


   /** Prints out the Course Data **/
//    unsigned int i;
//    for(i =0; i< courseinfo.size(); i++)
//    {
//        cout << courseinfo[i]->id << ". " << courseinfo[i]->code << endl;
//        cout << "Enrolled: " << courseinfo[i]->enrolled << " TAships: " << courseinfo[i]->TAships << endl;
//        cout << "Constraint: " << courseinfo[i]->constraints << endl;
//        cout << "numPref1st: " << courseinfo[i]->numPref1st << endl;
//        cout << "Level: " << courseinfo[i]->level << endl;
//    }

  /** Make a Dummy Assignment **/
//  unsigned int j;
//  unsigned int q;
//  for(j =0; j < courseinfo.size(); j++)
//  {
//      for(q = 0; q <6; q++)
//      {
//          assignment[j].push_back(TAinfo[k++]);
//      }
//  }
//  assignment[0] = removeCandidate(assignment[0], TAinfo[0]->id);
//  sort.printAssignment(assignment, 0);
//  cout << "The fitness of this assignment is: " << score.assignment(TAinfo, courseinfo, assignment, gHours) << endl;


 //   int solve = assign(TAinfo, courseinfo, candidates, assignment, gHours);

// for the most constrained course
//   take top candidates
//   assign
//   if(has more than one taship) taships--
//   else remove from all the other lists
//
//   recalculate constraint
    /**Create a baseline assignemnt **/
    unsigned int mc;

    while(coursesStillNeedTAS(courseinfo))
    {
    mc = mostConstrainedCourse(courseinfo);

    assignment[mc].push_back(candidates[mc][0]);
    if(TAinfo[candidates[mc][0]->id]->TAhoursOwed > 54)
    {
    TAinfo[candidates[mc][0]->id]->TAhoursOwed -= 54;
    candidates[mc] = removeCandidate(candidates[mc], candidates[mc][0]->id);
    }
    else
    {
      for(k = 0; k < NUM_COURSES; k++)
      {
      candidates[k] = removeCandidate(candidates[k], candidates[mc][0]->id);
      }
    }
    courseinfo[mc]->TAships--;
    courseinfo[mc]->freedom = 0;
    courseinfo[mc]->constraints = 0;
    courseinfo = in.updateConstraintInfo(courseinfo, candidates[mc]);


    //resort candidate lists
    for(k = 0; k < NUM_COURSES; k++)
    {
    sort.bySeniority(candidates[k], k);
    sort.byPrevAppts(candidates[k], k);
    sort.byScore(candidates[k], k);
    sort.byOwed(candidates[k]);
    }
    }

    sort.printAssignment(assignment, 0);
    cout << "The fitness of this assignment is: " << score.assignment(TAinfo, courseinfo, assignment, gHours) << endl;

    return 0;
}
