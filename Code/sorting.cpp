#include "input.h"
#include "student.h"
#include "sorting.h"

///*First Iteration of Sorting of TAs for each Course*/
//
//Sort by Guarantees Highest Hours to Lowest
//Sort by Preference 1st 2nd 3rd will unwill
//Sort by seniority
//Sort by Prev Appts
//Work from upper year courses down

/**Printing Functions**/
void Sorting::printNames(vector<Student*> x)
{
    unsigned int j;
    for(j =0; j < x.size(); j++)
    {
    cout << j+1 << ". " << x[j]->firstName;
    cout << "  |  Level: " << x[j]->level;
    cout << "  |  Pref: " << x[j]->pref[1];
    cout << "  |  PrevAppts: " << x[j]->prevAppts[1] << endl;
    }
}

void Sorting::printAssignment(vector <Student*> Course[NUM_COURSES], int level) //print the assignment of the top 3 from level, ie. all ranked #1 etc
{
    unsigned int j;
    for(j=0; j< NUM_COURSES; j++)
    {
        cout << "Course: " << j << " Assigned: " << Course[j][level]->firstName << ", ";
        cout << Course[j][level+1]->firstName << ", " << Course[j][level+2]->firstName << endl;
    }
}
/**Private Functions **/

/** debbie's suggestion************************************************/
// can we combine all the preference functions into one like this?
// ... let me know if i'm not understanding something fundamental about these functions xD
// Course is a vector of pointers to student vectors such that Course[CODE][RANK] returns the TA of rank RANK for course CODE.
vector <Student*>* [NUM_COURSE] vector <Student*> Sorting::pref(vector <Student*> TA, vector <Student*>* Course[NUM_COURSE], int Code, int preference)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    unsigned int i;
    for(i =0; i< TA.size(); i++){
          if(TA[i]->pref[code] == preference){
           // cout << TA[i]->firstName << endl;
              Course[code].push_back(TA[i]);
           }
    }
    return Course;
}
/** end debbie's suggestion********************************************/
/*
vector <Student*> Sorting::prefFirst(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    unsigned int i;
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
    unsigned int i;
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
    unsigned int i;
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
    unsigned int i;
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
    unsigned int i;
    for(i =0; i< TA.size(); i++)
    {
        if(TA[i]->pref[Code] == UNWILL)
        {
            Course.push_back(TA[i]);
        }
    }
    return Course;
}
*/
vector <Student*> Sorting::prefLeft(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    unsigned int i;
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

/*debbie's*suggestion*******************************************/
// goes through vector of TAs and stores TA's perference for a given course, repeats this for every course
vector <Student*>* [NUM_COURSE] Sorting::storePref(vector <Student*> TA, vector <Student*> Course)
{
    int i,j;
    for (i=0;i<NUM_COURSES;i++)   for (j=FIRST;j>=UNWILL;j--)  Course = pref(TA, Course, i, j);
    /*
    Course = prefFirst(TA, Course, Code);
    Course = prefSecond(TA, Course, Code);
    Course = prefThird(TA, Course, Code);
    Course = prefWill(TA, Course, Code);
    Course = prefUnwill(TA, Course, Code);
    Course = prefLeft(TA, Course, Code);
    */
    return Course;
}
/*end**debbie's*suggestion***************************************/

/*
// ORIGINAL: goes through vector of TAs and stores TA's perference of a given course
vector <Student*> Sorting::storePref(vector <Student*> TA, vector <Student*> Course, int Code)
{
    //if debbie's suggestion for "pref" is approved
    //int i;
    //for (i=FIRST;i>=UNWILL;i--)  Course = pref(TA, Course, Code, i);
    
    Course = prefFirst(TA, Course, Code);
    Course = prefSecond(TA, Course, Code);
    Course = prefThird(TA, Course, Code);
    Course = prefWill(TA, Course, Code);
    Course = prefUnwill(TA, Course, Code);
    Course = prefLeft(TA, Course, Code);
    return Course;
}
*/

/**suggested bySeniority*******************************************************/
// returns: stable sorted Course vector first by perference then by seniority
vector <Student*>* [NUM_COURSE] Sorting::bySeniority(vector <Student*> Course)
{
    unsigned int i, j;                          
    int swappedFlag = 1;
    for (j=0;j<NUM_COURSES;j++){
        swappedFlag=1;
        while(swappedFlag == 1){
              swappedFlag = 0;
              for(i = 0; i < (Course[j].size())-1; i++){
                    // if two TAs, i and i+1, have the SAME preference for Course j and TA i+1 higher senority, then swap TA i and i+1
                    if(Course[j][i]->level < Course[j][i+1]->level && Course[j][i]->pref[i] == Course[j][i+1]->pref[i+1]){
                //swap two students
                Course[j].insert(Course[j].begin()+(i+2), Course[j][i]);
                Course[j].erase(Course[j].begin()+i);
                swappedFlag = 1;
              }
        }
    }
    return Course;
}
/**end**suggestioned bySeniority***********************************************/

// ORIGINAL: returns course with higher seniority at front ... but not stable?
vector <Student*> Sorting::bySeniority(vector <Student*> Course)
{
    int swappedFlag = 1;
    while(swappedFlag == 1)
    {

        swappedFlag = 0;
        //bubble sort (kevin, is there a particular reason we're using bubble sort?)
        unsigned int i;
        for(i = 0; i < (Course.size())-1; i++)
        {
            if(Course[i]->level < Course[i+1]->level)
            {
                //swap two students
                Course.insert(Course.begin()+(i+2), Course[i]);
                Course.erase(Course.begin()+i);

                swappedFlag = 1;
            }
        }
    }
    return Course;
}

vector <Student*> Sorting::byPrevAppts(vector <Student*> Course, int code)
{
    int swappedFlag = 1;
    while(swappedFlag == 1)
    {

        swappedFlag = 0;
        //bubble sort
        unsigned int i;
        for(i = 0; i < (Course.size())-1; i++)
        {
            if(Course[i]->prevAppts[code] < Course[i+1]->prevAppts[code])
            {
                //swap two students
                Course.insert(Course.begin()+(i+2), Course[i]);
                Course.erase(Course.begin()+i);

                swappedFlag = 1;
            }
        }
    }
    return Course;
}

vector <Student*> Sorting::byScore(vector <Student*> Course, int code)
{
    int swappedFlag = 1;
    while(swappedFlag == 1)
    {

        swappedFlag = 0;
        //bubble sort
        unsigned int i;
        for(i = 0; i < (Course.size())-1; i++)
        {
            if(Course[i]->score[code] < Course[i+1]->score[code])
            {
                //swap two students
                Course.insert(Course.begin()+(i+2), Course[i]);
                Course.erase(Course.begin()+i);

                swappedFlag = 1;
            }
        }
    }
    return Course;
}


vector <Student*> Sorting::byTAshipsOwed(vector <Student*> Course)
{
    int swappedFlag = 1;
    while(swappedFlag == 1)
    {

        swappedFlag = 0;
        //bubble sort
        unsigned int i;
        for(i = 0; i < (Course.size())-1; i++)
        {
            if(Course[i]->TAhoursOwed < Course[i+1]->TAhoursOwed)
            {
                //swap two students
                Course.insert(Course.begin()+(i+2), Course[i]);
                Course.erase(Course.begin()+i);

                swappedFlag = 1;
            }
        }
    }
    return Course;
}
