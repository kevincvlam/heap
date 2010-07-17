#include "input_debbie.h"

void store_info(const char * file){

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



}
