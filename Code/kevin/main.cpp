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
        if(courseinfo[k]->freedom < min){
        min = courseinfo[k]->freedom;
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

// recursive assignment funcion
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
//    unsigned int i;
//    for(i =0; i< courseinfo.size(); i++)
//    {
//        cout << courseinfo[i]->id << ". " << courseinfo[i]->code << endl;
//        cout << "Enrolled: " << courseinfo[i]->enrolled << " TAships: " << courseinfo[i]->TAships << endl;
//        cout << "Freedom: " << courseinfo[i]->freedom << endl;
//        cout << "numPref1st: " << courseinfo[i]->numPref1st << endl;
//        cout << "Level: " << courseinfo[i]->level << endl;
//    }

  /** Make a Dummy Assignment **/
  unsigned int j;
  unsigned int q;
  unsigned int k = 0;
  for(j =0; j < courseinfo.size(); j++)
  {
      for(q = 0; q <6; q++)
      {
          assignment[j].push_back(TAinfo[k++]);
      }
  }
  assignment[0] = removeCandidate(assignment[0], TAinfo[0]->id);
  sort.printAssignment(assignment, 0);
  cout << "The fitness of this assignment is: " << score.assignment(TAinfo, courseinfo, assignment, gHours) << endl;


 //   int solve = assign(TAinfo, courseinfo, candidates, assignment, gHours);

    return 0;
}
