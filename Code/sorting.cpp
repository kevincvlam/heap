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

// prints names for course x
void Sorting::printNames(vector<Student*> x)
{
    unsigned int j;
    for(j =0; j < x.size(); j++)
    {
    cout << j+1 << ". " << x[j]->firstName;
    cout << " | Owed: " << x[j]->TAhoursOwed;
    cout << " | Pref: " << x[j]->pref[1];
    cout << " | Lvl: " << x[j]->level;
    cout << " | PrevAppts: " << x[j]->prevAppts[1];
    cout << " | Score: " << x[j]->score[1];
    cout << endl;
    }
}

void Sorting::printAssignment(vector <Student*> Course[NUM_COURSES], int level) //print the assignment of the top 3 from level, ie. all ranked #1 etc
{
    unsigned int j;
    for(j=0; j< NUM_COURSES; j++)
    {
        cout << "Course: " << j << " Assigned: " << Course[j][level]->firstName << ", ";
        cout << Course[j][level+1]->firstName << ", " << Course[j][level+2]->firstName;
        cout << ", " << Course[j][level+3]->firstName << ", " << Course[j][level+4]->firstName << endl;

    }
}
/**Private Functions **/

void Sorting::pref(vector <Student*> TA, vector <Student*> (&Course), int code, int preference)
{

    //for every TA, if he/she ranks the course as 1st, append that TA to Course
    unsigned int i;
    for(i =0; i< TA.size(); i++){
          //cout << TA[i]->firstName << " | pref: " << TA[i]->pref[code] << endl;
          if(TA[i]->pref[code] == preference){
              //cout << TA[i]->firstName << endl;
              Course.push_back(TA[i]);
           }
    }

}

/** Public Functions **/

// goes through vector of TAs and stores TA's perference for a given course, repeats this for every course
void Sorting::storePref(vector <Student*> TA, vector <Student*> (&Course), int code)
{
    int i;
    for (i=FIRST;i>=UNWILL;i--)    pref(TA, Course, code, i);

}

// returns: stable sorted Course vector first by perference then by seniority
void Sorting::bySeniority(vector <Student*> (&Course), int code)
{
    unsigned int i;
    int swappedFlag = 1;
    while(swappedFlag == 1){
        swappedFlag = 0;
        for(i = 0; i < (Course.size())-1; i++){
                    //if (j==1)   cout << "viewing TA #" << i << endl;
                    // if two TAs, i and i+1, have the SAME preference for Course j and TA i+1 higher senority, then swap TA i and i+1
              if((Course[i]->level < Course[i+1]->level) &&
                 (Course[i]->pref[code] == Course[i+1]->pref[code])){
                         //if (j==1) cout << "swapped " << Course[j][i]->firstName << " and " << Course[j][i+1]->firstName << " in " << Course[j][i]->pref << endl;
                         //swap two students
                    Course.insert(Course.begin()+(i+2), Course[i]);
                    Course.erase(Course.begin()+i);
                    swappedFlag = 1;
              }
        }
    }
}

// returns: stable sorted Course vector first by perference then by seniority then by prevAppts
void Sorting::byPrevAppts(vector <Student*> (&Course), int code)
{
    unsigned int i;
    int swappedFlag = 1;
    while(swappedFlag == 1){
         swappedFlag = 0;
         for(i = 0; i < (Course.size())-1; i++){
             if((Course[i]->prevAppts[code] < Course[i+1]->prevAppts[code]) &&
                (Course[i]->level == Course[i+1]->level) &&
                (Course[i]->pref[code] == Course[i+1]->pref[code])){
                     Course.insert(Course.begin()+(i+2), Course[i]);
                     Course.erase(Course.begin()+i);
                     swappedFlag = 1;
             }
         }
    }
}

// returns: stable sorted Course vector first by perference then by seniority then by prevAppts then by score
void Sorting::byScore(vector <Student*> (&Course), int code)
{
    unsigned int i;
    int swappedFlag = 1;
    while(swappedFlag == 1){
         swappedFlag = 0;
         for(i = 0; i < (Course.size())-1; i++){
             if((Course[i]->score[code] < Course[i+1]->score[code]) &&
                (Course[i]->prevAppts[code] < Course[i+1]->prevAppts[code]) &&
                (Course[i]->level == Course[i+1]->level) &&
                (Course[i]->pref[code] == Course[i+1]->pref[code])){
                     Course.insert(Course.begin()+(i+2), Course[i]);
                     Course.erase(Course.begin()+i);
                     swappedFlag = 1;
             }
         }
    }
}

// final pass to separate TAs with guarantees from those who don't ... still stable sorted.
   // it doesn't matter HOW much they're owed, as long as they're owed something, they're given the priority
   // when assigning TAs later, the assignment will simply cause the decrement of 54 hours under TAhoursOwed.
void Sorting::byOwed(vector <Student*> (&Course))
{
     vector <Student*> notOwed;
     unsigned int i = 0;
     while(i<Course.size()){
         if (Course[i]->TAhoursOwed <= 0){
            //cout << "not owed" << endl;
            notOwed.push_back(Course[i]);
            Course.erase(Course.begin()+i);
         } else i++;
     }
     /*cout << "List of not owed" << endl;
     for (i=0;i<notOwed.size();i++){
     cout << notOwed[i]->TAhoursOwed << endl;
     }*/
     Course.insert(Course.end(), notOwed.begin(), notOwed.end());
     notOwed.clear();

}
