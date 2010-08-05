#include "input.h"
#include "student.h"
#include "score.h"

//Assign a score for each ta and associated course

vector <Student*> Score::studentforCourse(vector <Student*> Course, int code)
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

int Score::assignment(vector <Student*> tainfo, vector <Course*> course, vector <Student*> assignment[NUM_COURSES], int hours)
//return a fitness score based on the input of a given assigment
{


    unsigned int j;
    unsigned int i;
    int score = 0;
    for(j=0; j< NUM_COURSES; j++)//for each course
    {
        /** Score based on how the preferenes of the assigned TAs **/
        for(i =0; i < assignment[j].size(); i++) //for each TA assigned to each course
        {
            if(assignment[j][i]->pref[j] == FIRST)
            {
                score += 25;
            }
            if(assignment[j][i]->pref[j] == SECOND)
            {
                score += 15;
            }
            if(assignment[j][i]->pref[j] == THIRD)
            {
                score += 10;
            }
            if(assignment[j][i]->pref[j] == WILL)
            {
                score += 5;
            }
        }


    }
    /** Score based on the guaranteed hours fulfilled **/
    score += (guaranteedHours(tainfo)/hours)*(tainfo.size());

    /** Score based on the TA:enrollment ratio **/
        //get max and min TAratios
    unsigned int max = 0;
    for(j=0; j< NUM_COURSES; j++)//for each course
    {
        if(assignment[j].size()/course[j]->TAships > max)
        max = assignment[j].size()/course[j]->TAships;
    }
    unsigned int min = 1000;
    for(j=0; j< NUM_COURSES; j++)//for each course
    {
        if(assignment[j].size()/course[j]->TAships < min)
        min = assignment[j].size()/course[j]->TAships;
    }
       //end max min
    score -= (max-min)*course.size();


    return score;
}

/** Student functions **/

// all hours owed to students in departments
int Score::guaranteedHours(vector <Student*> student)
{
    int hours = 0;
    unsigned int j;
    for(j=0; j< student.size(); j++)
    {
        hours += student[j]->TAhoursOwed;
    }

    return hours;
}

