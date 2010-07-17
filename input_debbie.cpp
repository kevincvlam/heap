#include "input_debbie.h"

Input::input(){

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
    int ta_count = 0;
    for(i=0;i<(unsigned)v.size();i++){
        if (v[i].rfind("First name",str.size()!=string::npos){
            identity[NAME_FIRST].push_back(v[i].substr(12,v[i].end()-1));
            ta_count++;
        } else if (v[i].rfind("Middle name",str.size()!=string::npos){
            identity[NAME_MIDDLE].push_back(v[i].substr(13,v[i].end()-1));
        } else if (v[i].rfind("Last name",str.size()!=string::npos){
            identity[NAME_LAST].push_back(v[i].substr(11,v[i].end()-1));
        }
        // ... go through all options ... until the next "First name" is reached, then increment the index of the corresponding option
    }

}
