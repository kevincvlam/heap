#include "input.h"
#include <math.h>

Input::Input(){
    numTA = 0;
}

vector <int> Input::store_courseinfo(const char * file)
{
    vector <int> courseinfo;
    courseinfo.push_back(4);
    courseinfo.push_back(4);
    //for the two courses with no enrollment

    //read in file
    ifstream in (file);
    string s;
    while (getline(in,s)){
        if (s.rfind("Enrolment:",s.size()-1)!=string::npos){
            int enrolled = convert_int(s.substr(s.rfind("*",s.size()-1)+8,s.rfind(")",s.size()-1)-1));
            double TAships = enrolled*2.5/54.0;
            //round up to nearest ones place
            if(((int)(TAships*10))%10 >=5)
            TAships = ceil(TAships);
            else
            TAships = floor(TAships);

            courseinfo.push_back((int)TAships);
        }


    s.clear();
    }
    in.close();

    return courseinfo;
}

vector <Student*> Input::store_info(const char * file){

    vector <Student*> info;

    ifstream in (file);
    string s;
    while (getline(in,s)){

        if (s.rfind("First name",s.size()-1)!=string::npos){
            Student *TA = new Student;
            TA->firstName = s.substr(12,s.size()-1);
            info.push_back(TA);            numTA++;
        } else if (s.rfind("Middle name",s.size()-1)!=string::npos){
            info[numTA-1]->middleName = s.substr(13,s.size()-1);
        } else if (s.rfind("Last name",s.size()-1)!=string::npos){
            info[numTA-1]->lastName = s.substr(11,s.size()-1);

        } else if (s.rfind("Level of study",s.size()-1)!=string::npos){
            if (s.rfind("PhD",s.size()-1)!=string::npos) info[numTA-1]->level = PHD;
            else if (s.rfind("MSc",s.size()-1)!=string::npos) info[numTA-1]->level = MSC;
            else  info[numTA-1]->level = BA;

        } else if (s.rfind("reading",s.size()-1)!=string::npos){
            info[numTA-1]->reading = convert_int(s.substr(9,s.size()-1));
        } else if (s.rfind("writing",s.size()-1)!=string::npos){
            info[numTA-1]->writing = convert_int(s.substr(9,s.size()-1));
        } else if (s.rfind("coversation",s.size()-1)!=string::npos){
            info[numTA-1]->conversation = convert_int(s.substr(13,s.size()-1));
        } else if (s.rfind("Java",s.size()-1)!=string::npos){
            info[numTA-1]->Java = convert_int(s.substr(6,s.size()-1));
        } else if (s.rfind("C++",s.size()-1)!=string::npos){
            info[numTA-1]->Cpp = convert_int(s.substr(5,s.size()-1));
        } else if (s.rfind("C:",s.size()-1)!=string::npos){
            info[numTA-1]->C = convert_int(s.substr(3,s.size()-1));
        } else if (s.rfind("BASIC",s.size()-1)!=string::npos){
            info[numTA-1]->BASIC = convert_int(s.substr(7,s.size()-1));
        } else if (s.rfind("Prolog",s.size()-1)!=string::npos){
            info[numTA-1]->Prolog = convert_int(s.substr(8,s.size()-1));
        } else if (s.rfind("Lisp/Scheme",s.size()-1)!=string::npos){
            info[numTA-1]->LispScheme = convert_int(s.substr(13,s.size()-1));
        } else if (s.rfind("HTML:",s.size()-1)!=string::npos){
            info[numTA-1]->HTML = convert_int(s.substr(6,s.size()-1));
        } else if (s.rfind("UML",s.size()-1)!=string::npos){
            info[numTA-1]->UML = convert_int(s.substr(5,s.size()-1));
        } else if (s.rfind("ML:",s.size()-1)!=string::npos){
            info[numTA-1]->ML = convert_int(s.substr(4,s.size()-1));
        } else if (s.rfind("CVS",s.size()-1)!=string::npos){
            info[numTA-1]->CVS = convert_int(s.substr(5,s.size()-1));
        } else if (s.rfind("CSim",s.size()-1)!=string::npos){
            info[numTA-1]->CSim = convert_int(s.substr(6,s.size()-1));
        } else if (s.rfind("Maple",s.size()-1)!=string::npos){
            info[numTA-1]->Maple = convert_int(s.substr(7,s.size()-1));
        } else if (s.rfind("Matlab",s.size()-1)!=string::npos){
            info[numTA-1]->Matlab = convert_int(s.substr(8,s.size()-1));
        } else if (s.rfind("RCS",s.size()-1)!=string::npos){
            info[numTA-1]->RCS = convert_int(s.substr(5,s.size()-1));
        } else if (s.rfind("Perl",s.size()-1)!=string::npos){
            info[numTA-1]->Perl = convert_int(s.substr(6,s.size()-1));
        } else if (s.rfind("Python",s.size()-1)!=string::npos){
            info[numTA-1]->Python = convert_int(s.substr(8,s.size()-1));
        } else if (s.rfind("Unix/Linux",s.size()-1)!=string::npos){
            info[numTA-1]->UnixLinux = convert_int(s.substr(12,s.size()-1));
        } else if (s.rfind("tools",s.size()-1)!=string::npos){
            info[numTA-1]->tools = convert_int(s.substr(7,s.size()-1));
        } else if (s.rfind("shell",s.size()-1)!=string::npos){
            info[numTA-1]->shell = convert_int(s.substr(7,s.size()-1));
        } else if (s.rfind("make",s.size()-1)!=string::npos){
            info[numTA-1]->make = convert_int(s.substr(6,s.size()-1));
        } else if (s.rfind("assembly",s.size()-1)!=string::npos){
            info[numTA-1]->assembly = convert_int(s.substr(10,s.size()-1));
        } else if (s.rfind("logic design",s.size()-1)!=string::npos){
            info[numTA-1]->logicDesign = convert_int(s.substr(14,s.size()-1));
        } else if (s.rfind("digital circuits",s.size()-1)!=string::npos){
            info[numTA-1]->digitalCircuits = convert_int(s.substr(18,s.size()-1));
        } else if (s.rfind("graphics",s.size()-1)!=string::npos){
            info[numTA-1]->graphics = convert_int(s.substr(10,s.size()-1));
        } else if (s.rfind("web programming",s.size()-1)!=string::npos){
            info[numTA-1]->webProgramming = convert_int(s.substr(17,s.size()-1));
        } else if (s.rfind("information theory",s.size()-1)!=string::npos){
            info[numTA-1]->infoTheory = convert_int(s.substr(20,s.size()-1));
        } else if (s.rfind("interface design",s.size()-1)!=string::npos){
            info[numTA-1]->interfaceDesign = convert_int(s.substr(18,s.size()-1));
        } else if (s.rfind("databases",s.size()-1)!=string::npos){
            info[numTA-1]->databases = convert_int(s.substr(11,s.size()-1));
        } else if (s.rfind("concurrency",s.size()-1)!=string::npos){
            info[numTA-1]->concurrency = convert_int(s.substr(13,s.size()-1));
        } else if (s.rfind("networks",s.size()-1)!=string::npos){
            info[numTA-1]->networks = convert_int(s.substr(10,s.size()-1));
        } else if (s.rfind("compilers",s.size()-1)!=string::npos){
            info[numTA-1]->compilers = convert_int(s.substr(11,s.size()-1));
        } else if (s.rfind("statistics",s.size()-1)!=string::npos){
            info[numTA-1]->statistics = convert_int(s.substr(12,s.size()-1));
        } else if (s.rfind("simulations",s.size()-1)!=string::npos){
            info[numTA-1]->simulations = convert_int(s.substr(13,s.size()-1));
        } else if (s.rfind("systems modelling",s.size()-1)!=string::npos){
            info[numTA-1]->systemsModelling = convert_int(s.substr(19,s.size()-1));
        } else if (s.rfind("numerical methods",s.size()-1)!=string::npos){
            info[numTA-1]->numMethods = convert_int(s.substr(19,s.size()-1));
        } else if (s.rfind("business",s.size()-1)!=string::npos){
            info[numTA-1]->business = convert_int(s.substr(10,s.size()-1));
        } else if (s.rfind("Past TAships",s.size()-1)!=string::npos){
            info[numTA-1]->pastTAships = convert_int(s.substr(14,s.size()-1));
        } else if (s.rfind("TAships owed (database)",s.size()-1)!=string::npos){
            info[numTA-1]->TAhoursOwed = convert_int(s.substr(s.rfind("[",s.size()-1)+1,s.rfind(",",s.size()-1)-1));
        } else if (s.rfind("TAships wanted",s.size()-1)!=string::npos){
            info[numTA-1]->TAshipsWanted = convert_int(s.substr(16,s.size()-1));
        } else if (s.rfind("Min. TAships willing",s.size()-1)!=string::npos){
            info[numTA-1]->minWilling = convert_int(s.substr(22,s.size()-1));
        } else if (s.rfind("Max. TAships willing",s.size()-1)!=string::npos){
            info[numTA-1]->maxWilling = convert_int(s.substr(22,s.size()-1));



        } else if (s.rfind("Preference",s.size()-1)!=string::npos){
            if (s.rfind("1st",s.size()-1)!=string::npos){
                if (s.rfind("HLP101H:",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101H] = FIRST;
                else if (s.rfind("HLP101HTAH",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101HTAH] = FIRST;
                else if (s.rfind("CSC108H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC108H] = FIRST;
                else if (s.rfind("CSC148H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC148H] = FIRST;
                else if (s.rfind("CSC165H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC165H] = FIRST;
                else if (s.rfind("CSC207H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC207H] = FIRST;
                else if (s.rfind("CSC209H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC209H] = FIRST;
                else if (s.rfind("CSC373H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC373H] = FIRST;
                else if (s.rfind("CSC324H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC324H] = FIRST;
            } else if (s.rfind("2nd",s.size()-1)!=string::npos) {
                if (s.rfind("HLP101H:",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101H] = SECOND;
                else if (s.rfind("HLP101HTAH",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101HTAH] = SECOND;
                else if (s.rfind("CSC108H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC108H] = SECOND;
                else if (s.rfind("CSC148H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC148H] = SECOND;
                else if (s.rfind("CSC165H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC165H] = SECOND;
                else if (s.rfind("CSC207H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC207H] = SECOND;
                else if (s.rfind("CSC209H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC209H] = SECOND;
                else if (s.rfind("CSC373H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC373H] = SECOND;
                else if (s.rfind("CSC324H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC324H] = SECOND;
            } else if (s.rfind("3rd",s.size()-1)!=string::npos) {
                if (s.rfind("HLP101H:",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101H] = THIRD;
                else if (s.rfind("HLP101HTAH",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101HTAH] = THIRD;
                else if (s.rfind("CSC108H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC108H] = THIRD;
                else if (s.rfind("CSC148H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC148H] = THIRD;
                else if (s.rfind("CSC165H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC165H] = THIRD;
                else if (s.rfind("CSC207H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC207H] = THIRD;
                else if (s.rfind("CSC209H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC209H] = THIRD;
                else if (s.rfind("CSC373H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC373H] = THIRD;
                else if (s.rfind("CSC324H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC324H] = THIRD;
            } else if (s.rfind("pref",s.size()-1)!=string::npos) {
                if (s.rfind("HLP101H:",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101H] = PREF;
                else if (s.rfind("HLP101HTAH",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101HTAH] = PREF;
                else if (s.rfind("CSC108H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC108H] = PREF;
                else if (s.rfind("CSC148H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC148H] = PREF;
                else if (s.rfind("CSC165H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC165H] = PREF;
                else if (s.rfind("CSC207H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC207H] = PREF;
                else if (s.rfind("CSC209H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC209H] = PREF;
                else if (s.rfind("CSC373H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC373H] = PREF;
                else if (s.rfind("CSC324H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC324H] = PREF;
            } else if (s.rfind(" will",s.size()-1)!=string::npos) {
                if (s.rfind("HLP101H:",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101H] = WILL;
                else if (s.rfind("HLP101HTAH",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101HTAH] = WILL;
                else if (s.rfind("CSC108H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC108H] = WILL;
                else if (s.rfind("CSC148H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC148H] = WILL;
                else if (s.rfind("CSC165H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC165H] = WILL;
                else if (s.rfind("CSC207H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC207H] = WILL;
                else if (s.rfind("CSC209H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC209H] = WILL;
                else if (s.rfind("CSC373H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC373H] = WILL;
                else if (s.rfind("CSC324H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC324H] = WILL;
            } else if (s.rfind("unwill",s.size()-1)!=string::npos) {
                if (s.rfind("HLP101H:",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101H] = UNWILL;
                else if (s.rfind("HLP101HTAH",s.size()-1)!=string::npos) info[numTA-1]->pref[HLP101HTAH] = UNWILL;
                else if (s.rfind("CSC108H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC108H] = UNWILL;
                else if (s.rfind("CSC148H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC148H] = UNWILL;
                else if (s.rfind("CSC165H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC165H] = UNWILL;
                else if (s.rfind("CSC207H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC207H] = UNWILL;
                else if (s.rfind("CSC209H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC209H] = UNWILL;
                else if (s.rfind("CSC373H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC373H] = UNWILL;
                else if (s.rfind("CSC324H",s.size()-1)!=string::npos) info[numTA-1]->pref[CSC324H] = UNWILL;
            }

        } else if (s.rfind("Prev. appts.",s.size()-1)!=string::npos){
            if (s.rfind("HLP101H:",s.size()-1)!=string::npos)  info[numTA-1]->prevAppts[HLP101H] = convert_int(s.substr(26,s.size()-1));
            else if (s.rfind("HLP101HTAH",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[HLP101HTAH] = convert_int(s.substr(29,s.size()-1));
            else if (s.rfind("CSC108H",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[CSC108H] = convert_int(s.substr(26,s.size()-1));
            else if (s.rfind("CSC148H",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[CSC148H] = convert_int(s.substr(26,s.size()-1));
            else if (s.rfind("CSC165H",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[CSC165H] = convert_int(s.substr(26,s.size()-1));
            else if (s.rfind("CSC207H",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[CSC207H] = convert_int(s.substr(26,s.size()-1));
            else if (s.rfind("CSC209H",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[CSC209H] = convert_int(s.substr(26,s.size()-1));
            else if (s.rfind("CSC373H",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[CSC373H] = convert_int(s.substr(26,s.size()-1));
            else if (s.rfind("CSC324H",s.size()-1)!=string::npos) info[numTA-1]->prevAppts[CSC324H] = convert_int(s.substr(26,s.size()-1));
        }

        s.clear();
    }
    in.close();


    //testing input of random things

    //unsigned int i,/*j*/;
    //for (i=0; i<(unsigned)info.size(); i++){
        /*for (j=0;j<NUM_COURSES;j++){
            cout << info[i]->firstName << " " << j <<". prev: " << info[i]->prevAppts[j] <<" pref: "<< info[i]->pref[j] <<endl;
        }*/
        //cout << i+1 << ". " << info[i]->firstName /*<< " " << info[i]->TAhoursOwed << " prev appt HLP101HTAH: " << info[i]->prevAppts[HLP101HTAH] << " pref for HLP101HTAH: " << info[i]->pref[HLP101HTAH]*/ << endl;
    //}

    return info;

}

int Input::convert_int(string s) {
  int i;
  i = atoi(s.c_str());
  return i;
}
