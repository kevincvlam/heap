#include "input.h"

Input::Input(){
    numTA = 0;
}

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
    for(i=0;i<(unsigned)v.size();i++){
          //cout << "viewing: " << v[i] << endl;
        if (v[i].rfind("First name",v[i].size()-1)!=string::npos){
            Student *TA = new Student;
            TA->firstName = v[i].substr(12,v[i].size()-1);
            info.push_back(TA);
            cout << "added first name: " << info[numTA]->firstName << endl;
            numTA++;
        } else if (v[i].rfind("Middle name",v[i].size()-1)!=string::npos){
            info[numTA-1]->middleName = v[i].substr(13,v[i].size()-1);
            cout << "added " << info[numTA-1]->firstName << "'s middle name: " << info[numTA-1]->middleName << endl;
        } else if (v[i].rfind("Last name",v[i].size()-1)!=string::npos){
            info[numTA-1]->lastName = v[i].substr(11,v[i].size()-1);
            cout << "added last name: " << info[numTA-1]->lastName << endl;
        }
    }
    
}
