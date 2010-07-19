#include "input_debbie.h"

//Input::Input(){} <--- this prorbably doesn't need to be a class

void Input::store_info(const char * file){

    // PART 1 extract data from file
    ifstream in (file);
    string s; // holds each line
    vector <string> v; // holds document
    while (getline(in,s)){
        v.push_back(s);
        s.clear();
    }
    in.close();
    

    //PART 2 view v index by index and change information matrix based on findings
    int i;
    int ta_count = 0;
    for(i=0;i<(unsigned)v.size();i++){
          //cout << "viewing: " << v[i] << endl;
        if (v[i].rfind("First name",v[i].size()-1)!=string::npos){
            studentInfo newStudent;
            newStudent.firstName = v[i].substr(12,v[i].size()-1)
            TAinfo.push_back(newStudent);
            //identity[NAME_FIRST].push_back(v[i].substr(12,v[i].size()-1));
            //cout << "added first name: " << identity[NAME_FIRST][ta_count] << endl;
            ta_count++;
        } else if (v[i].rfind("Middle name",v[i].size()-1)!=string::npos){
            identity[NAME_MIDDLE].push_back(v[i].substr(13,v[i].size()-1));
            //cout << "added " << identity[NAME_FIRST][ta_count-1] << "'s middle name: " << identity[NAME_MIDDLE][ta_count-1] << endl;
        } else if (v[i].rfind("Last name",v[i].size()-1)!=string::npos){
            identity[NAME_LAST].push_back(v[i].substr(11,v[i].size()-1));
            //cout << "added last name: " << identity[NAME_LAST][ta_count-1] << endl;
        }
    }
    
    print_identity();
    
        // ... go through all options ... until the next "First name" is reached, then increment the index of the corresponding option
}

//  -- probably don't need this anymore
void Input::print_identity(){
    int i, j;
    for(i=0;i<identity[NAME_FIRST].size();i++){
        cout << i <<". ";
        for(j=0;j<3;j++){
           cout << identity[j][i];
           if (identity[j][i].size()>0) cout << " ";
        }
        cout << endl;
    }
}
