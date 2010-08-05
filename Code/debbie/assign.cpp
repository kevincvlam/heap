#include "input.h"
#include "student.h"
#include "sorting.h"
#include "assign.h"

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

void Assign::assign(vector <Student*> Courses[NUM_COURSES], vector <Student*> TA, vector <int> TAships){

    vector <Student*> assignment[NUM_COURSES];
    Sorting sort;
    unsigned int i,j;
    // add heuristics, ex: karl's note about constrained TAs
    
    // final resort
    while (!constraint_course(assignment,TAships)/*||!constraint_guarantee(Courses)*/){
        for (i=0;i<NUM_COURSES;i++){
            //cout << assignment[i].size() << " " << TAships[i] << endl;
            if (Courses[i][0]->TAhoursOwed <= 0){
                 for(i=0;i<NUM_COURSES;i++){
                     cout << "course " << i;
                     for (j=0;j<assignment[i].size();j++) cout << " " << assignment[i][j]->firstName;
                     cout << endl;
                 }
                 return;
            } else if(assignment[i].size()<(unsigned)TAships[i]){                                           
                /*if (Courses[i][0]->TAhoursOwed<=0){
                   cout << "Courses[i][0]->TAhoursOwed<=0" << endl;
                   for (j=0;j<Courses[i].size();j++){
                       cout << Courses[i][j]->firstName << " " << Courses[i][j]->TAhoursOwed << endl;
                   }
                }*/
                assignment[i].push_back(Courses[i][0]);
                cout << "Added "<< assignment[i][assignment[i].size()-1]->firstName << " " << assignment[i][assignment[i].size()-1]->TAhoursOwed << " to course " << i << endl;
                TA[Courses[i][0]->id]->TAhoursOwed -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->minWilling -= 54;
                TA[Courses[i][0]->id]->maxWilling -= 54;
                TA[Courses[i][0]->id]->minTA -= 54;
                TA[Courses[i][0]->id]->maxTA -= 54;
                //cout << " Next " << Courses[i][0]->firstName << " " << Courses[i][0]->TAhoursOwed << endl;
                for(j = 0; j < NUM_COURSES; j++){
                       sort.storePref(TA, Courses[j], j);
                       sort.bySeniority(Courses[j], j);
                       sort.byPrevAppts(Courses[j], j);
                       sort.byScore(Courses[j], j);
                       sort.byOwed(Courses[j]);
                }
                sort.printAssignment(Courses, 0);
                for (j=0;j<Courses[i].size();j++){
                    if(Courses[i][j]->id == assignment[i][assignment[i].size()-1]->id){
                        cout << " removing " << Courses[i][j]->firstName << endl;
                        Courses[i].erase(Courses[i].begin()+j);
                    }
                }
            } else if (constraint_course(assignment,TAships)&&!constraint_guarantee(Courses)&&Courses[i][0]->TAhoursOwed>0){
                assignment[i].push_back(Courses[i][0]);
                cout << "Course constraint satisfied.  Added "<< assignment[i][assignment[i].size()-1]->firstName << " to course " << i << endl;
                TA[Courses[i][0]->id]->TAhoursOwed -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->TAshipsWanted -= 54;
                TA[Courses[i][0]->id]->minWilling -= 54;
                TA[Courses[i][0]->id]->maxWilling -= 54;
                TA[Courses[i][0]->id]->minTA -= 54;
                TA[Courses[i][0]->id]->maxTA -= 54;
                Courses[i].erase(Courses[i].begin());
                for(j = 0; j < NUM_COURSES; j++){
                       sort.storePref(TA, Courses[j], j);
                       sort.bySeniority(Courses[j], j);
                       sort.byPrevAppts(Courses[j], j);
                       sort.byScore(Courses[j], j);
                       sort.byOwed(Courses[j]);
                }
            }
        }
    }
        
        //print assignment
        for(i=0;i<NUM_COURSES;i++){
            cout << "course " << i;
            for (j=0;j<assignment[i].size();j++){
                cout << " " << assignment[i][j]->firstName;
            }
            cout << endl;
        }
        
        //return assignment; need to find out how to return vector <student*> assignment[NUM_COURSES]
}

// returns 0 if guarantees still exist
bool Assign::constraint_guarantee(vector <Student*> Courses[NUM_COURSES]){
     int i;
     int guarantee = 1;
     for(i=0; i<NUM_COURSES; i++){
         if(Courses[i][0]->TAhoursOwed <= 0)   guarantee = 0;
     }
     return guarantee;
}

//returns 0 there are courses that don't fit the TA enrolment ratio minimum
bool Assign::constraint_course(vector <Student*> assignment[NUM_COURSES], vector <int> TAships){
     
     int i;
     int course = 1;
     for(i=0; i<NUM_COURSES; i++){
         if(assignment[i].size() < (unsigned)TAships[i]){
             course = 0;
         }
     }
     return course;
}
