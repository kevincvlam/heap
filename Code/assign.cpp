#include "input.h"
#include "student.h"
#include "score.h"
#include "sorting.h"

//while(guarantees unfulfilled && course unfilled)
//{ 
//  for each course
//   if course unfulfilled
//     append one top ranked candidate while guarantees are not fulfilled
//     (append to a new list, and remove it from the course rankied list, also decrement the taships owed in the reference vector of students)
//   
//   if all course is fulfilled
//     append top ranked candidate
//     if guarantees fulfilled break;
//}   

vector <Student*> Assign::Assign(vector <Student*> Courses[NUM_COURSES], vector <Student*> TA, vector <int> TAships){

    vector <Student*> assignment[NUM_COURSES]

    int i, j;
    Sorting sort;

    
    while (!constraint_course(assignment)||!constraint_gaurantee(Courses));
        added = 0;
        for (i=0;i<NUM_COURSES;i++){
            if(assignment[i].size()<TAships[i]){
                assignment[i].push_back(Courses[i][0]);
                TA[Courses[i][0]->id]->TAhoursOwed -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->minWilling -= 54;
                TA[Courses[i][0]->id]->maxWilling -= 54;
                TA[Courses[i][0]->id]->minTA -= 54;
                TA[Courses[i][0]->id]->maxTA -= 54;
                sort(TA,Courses);
            } else if (constraint_course(assignment,TAships)&&!constraint_gaurantee(Courses)){
                assignment[i].push_back(Courses[i][0]);
                TA[Courses[i][0]->id]->TAhoursOwed -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->minWilling -= 54;
                TA[Courses[i][0]->id]->maxWilling -= 54;
                TA[Courses[i][0]->id]->minTA -= 54;
                TA[Courses[i][0]->id]->maxTA -= 54;
                sort(TA,Courses);
            } 
        }
        
        return assignment;
}

bool Assign::constraint_gaurantee(vector <Student*> Courses[NUM_COURSES]){
     int i;
     int gaurantee = 0;
     for(i=0; i<NUM_COURSES; i++){
         if(Courses[i][0]->TAhoursOwed <= 0)   guarantee = 1;
     }
     return guarantee;
}

bool Assign::constraint_course(vector <Student*> assignment[NUM_COURSES], vector <int> TAships){
     int i;
     int course = 0;
     for(i=0; i<NUM_COURSES; i++){
         if(assignment[i].size() < TAships[i])   course = 1;
     }
     return course;
}
