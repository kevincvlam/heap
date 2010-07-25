#include "input.h"
#include "student.h"
#include "sorting.h"

///*First Iteration of Sorting of TAs for each Course*/
//
//Sort by Guarantees Highest Hours to Lowest
//Sort by Preference 1st 2nd 3rd will unwill
//Sort by seniority
//
//Work from upper year courses down

void Sorting::printNames(vector<Student*> x, int i)
{
    int j;
    for(j =0; j < x.size(); j++)
    cout << i << ". " << x[i]->firstName;
}

void Sorting::storePrefTA(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] == FIRST)
        {
            Course.push_back(TA[i]);
        }
    }

}

