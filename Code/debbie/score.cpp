#include "input.h"
#include "student.h"
#include "score.h"

//Assign a score for each ta and associated course

vector <Student*> Score::forCourse(vector <Student*> Course, int code)
{
    //for all students, assign a score based on preference, prev appts, and seniority
    /**Change Score Values in DEFINITIONS**/
    unsigned int i;
    for(i = 0; i< Course.size(); i++) //for all students
    {
        Course[i]->score[code] += Course[i]->pref[code];
        Course[i]->score[code] += Course[i]->prevAppts[code];
        Course[i]->score[code] += Course[i]->level;
    }
    return Course;
}
