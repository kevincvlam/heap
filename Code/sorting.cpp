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

/*Helper Functions*/
void Sorting::printNames(vector<Student*> x)
{
    int j;
    for(j =0; j < x.size(); j++)
    cout << j << ". " << x[j]->firstName << endl;
}

/**Private Functions **/

vector <Student*> Sorting::prefFirst(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] == FIRST)
        {
           // cout << TA[i]->firstName << endl;
            Course.push_back(TA[i]);
        }
    }
    return Course;
}

vector <Student*> Sorting::prefSecond(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] == SECOND)
        {
            Course.push_back(TA[i]);
        }
    }
    return Course;
}

vector <Student*> Sorting::prefThird(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] == THIRD)
        {
            Course.push_back(TA[i]);
        }
    }
    return Course;

}

vector <Student*> Sorting::prefWill(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] == WILL)
        {
            Course.push_back(TA[i]);
        }
    }
    return Course;
}


vector <Student*> Sorting::prefUnwill(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] == UNWILL)
        {
            Course.push_back(TA[i]);
        }
    }
    return Course;
}

vector <Student*> Sorting::prefLeft(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] != UNWILL
        && TA[i]->pref[Code] != WILL
        && TA[i]->pref[Code] != FIRST
        && TA[i]->pref[Code] != SECOND
        && TA[i]->pref[Code] != THIRD)
        {
            Course.push_back(TA[i]);
        }
    }
    return Course;
}

/** Public Functions **/

vector <Student*> Sorting::storePref(vector <Student*> TA, vector <Student*> Course, int Code)
{
    Course = prefFirst(TA, Course, Code);
    Course = prefSecond(TA, Course, Code);
    Course = prefThird(TA, Course, Code);
    Course = prefWill(TA, Course, Code);
    Course = prefUnwill(TA, Course, Code);
    Course = prefLeft(TA, Course, Code);
    return Course;
}

