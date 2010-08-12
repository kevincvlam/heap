#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//Definitions

//    EXP_LVL
    #ifndef PHD
    #define PHD 2
    #endif
    #ifndef MSC
    #define MSC 1
    #endif
    #ifndef BA
    #define BA 0
    #endif

//    COURSES
    #ifndef NUM_COURSES
    #define NUM_COURSES 8
    #endif
    #ifndef HLP101H
    #define HLP101H 0
    #endif
    #ifndef CSC108H
    #define CSC108H 1
    #endif
    #ifndef CSC148H
    #define CSC148H 2
    #endif
    #ifndef CSC165H
    #define CSC165H 3
    #endif
    #ifndef CSC207H
    #define CSC207H 4
    #endif
    #ifndef CSC209H
    #define CSC209H 5
    #endif
    #ifndef CSC324H
    #define CSC324H 6
    #endif
    #ifndef CSC373H
    #define CSC373H 7
    #endif

//  WILLINGNESS
//     currently arbitrarily defined
//     (perhaps change values to the number of "points" each rank rewards for Kevin and Karl's part)
    #ifndef FIRST
    #define FIRST 10
    #endif
    #ifndef SECOND
    #define SECOND 8
    #endif
    #ifndef THIRD
    #define THIRD 6
    #endif
    #ifndef PREF
    #define PREF 4
    #endif
    #ifndef WILL
    #define WILL 2
    #endif
    #ifndef UNWILL
    #define UNWILL 0
    #endif

using namespace std;
