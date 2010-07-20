#include "input.h"

Input::Input(){
    numTA = 0;
}

void Input::store_info(const char * file){

    ifstream in (file);
    string s; // holds each line
    while (getline(in,s)){
        if (s.rfind("First name",s.size()-1)!=string::npos){
            Student *TA = new Student;
            TA->firstName = s.substr(12,s.size()-1);
            info.push_back(TA);
            cout << "added first name: " << info[numTA]->firstName << endl;
            numTA++;
        } else if (s.rfind("Middle name",s.size()-1)!=string::npos){
            info[numTA-1]->middleName = s.substr(13,s.size()-1);
            cout << "added " << info[numTA-1]->firstName << "'s middle name: " << info[numTA-1]->middleName << endl;
        } else if (s.rfind("Last name",s.size()-1)!=string::npos){
            info[numTA-1]->lastName = s.substr(11,s.size()-1);
            cout << "added last name: " << info[numTA-1]->lastName << endl;
        }
        s.clear();
    }
    in.close();
    
}
