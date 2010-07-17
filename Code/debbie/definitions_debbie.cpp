#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//Definitions

/********************************************************************
* TABLE PROPERTIES
*********************************************************************/
    #ifndef NUM_COURSE
    #define NUM_COURSE //(number of courses == size of several subarrays)
    #endif
    #ifndef NUM_QUAL
    #define NUM_QUAL // (number of qualifications == length of information matrix)
    #endif
    #ifndef NUM_APP
    #define NUM_APP // (number of applicants == width of information matrix)
    #endif

/********************************************************************
* FIELDS
*     values pertain to index on INFORMATION MATRIX
********************************************************************/

    //CATEGORY 1
    #ifndef NAME_FIRST
    #define NAME_FIRST 0
    #endif
    #ifndef NAME_MIDDLE
    #define NAME_MIDDLE 1
    #endif
    #ifndef NAME_LAST
    #define NAME_LAST 2
    #endif

    //CATEGORY 2
    #endif
    #ifndef EXP_LVL
    #define EXP_LVL 3
    #endif
    #ifndef EXP_COURSES
    #define EXP_COURSES 4
    #endif
    #ifndef EXP_PAST_TASHIP
    #define EXP_PAST_TASHIP 5
    #endif

    //CATEGORY 3
    #ifndef PREF_WILL
    #define PREF_WILL 6
    #endif
    #ifndef PREF_PREV
    #define PREF_PREV 7
    #endif

    //CATEGORY 4
    #ifndef TASHIP_OWE
    #define TASHIP_OWE 8
    #endif
    #ifndef TASHIP_MIN
    #define TASHIP_MIN 9
    #endif
    #ifndef TASHIP_MAX
    #define TASHIP_MAX 10
    #endif
    #ifndef TASHIP_PREF
    #define TASHIP_PREF 11
    #endif

    //CATEGORY 5

    #ifndef QUAL_READ
    #define QUAL_READ 12
        #endif
    #ifndef  QUAL_WRITE
    #define QUAL_WRITE 13
        #endif
    #ifndef  QUAL_CONV
    #define QUAL_CONV 14
         #endif
    #ifndef QUAL_JAVA
    #define QUAL_JAVA 15
         #endif
    #ifndef QUAL_C
    #define QUAL_C 16
         #endif
    #ifndef QUAL_CPP
    #define QUAL_CPP 17
         #endif
    #ifndef QUAL_BASIC
    #define QUAL_BASIC 18
         #endif
    #ifndef QUAL_PROLOG
    #define QUAL_PROLOG 19
         #endif
    #ifndef QUAL_LISP 20
    #define QUAL_LISP
         #endif
    #ifndef QUAL_ML
    #define QUAL_ML 21
         #endif
    #ifndef QUAL_CVS
    #define QUAL_CVS 22
         #endif
    #ifndef QUAL_CSIM
    #define QUAL_CSIM 23
         #endif
    #ifndef QUAL_MAPLE
    #define QUAL_MAPLE 24
         #endif
    #ifndef QUAL_MATLAB
    #define QUAL_MATLAB 25
         #endif
    #ifndef QUAL_RCS
    #define QUAL_RCS 26
         #endif
    #ifndef QUAL_PERL
    #define QUAL_PERL 27
         #endif
    #ifndef QUAL_PYTHON
    #define QUAL_PYTHON 28
        #endif
    #ifndef QUAL_HTML
    #define QUAL_HTML 29
         #endif
    #ifndef QUAL_UML
    #define QUAL_UML 30
         #endif
    #ifndef QUAL_UNIX
    #define QUAL_UNIX 31
         #endif
    #ifndef QUAL_TOOLS
    #define QUAL_TOOLS 32
         #endif
    #ifndef QUAL_SHELL
    #define QUAL_SHELL 33
         #endif
    #ifndef QUAL_MAKE
    #define QUAL_MAKE 34
         #endif
    #ifndef QUAL_ASSEMBLY
    #define QUAL_ASSEMBLY 35
         #endif
    #ifndef QUAL_LOGIC
    #define QUAL_LOGIC 36
         #endif
    #ifndef QUAL_CIRCUITS
    #define QUAL_CIRCUITS 37
         #endif
    #ifndef QUAL_GRAPHICS
    #define QUAL_GRAPHICS 38
         #endif
    #ifndef QUAL_WEB_PROG
    #define QUAL_WEB_PROG 39
         #endif
    #ifndef QUAL_INFO_THEORY
    #define QUAL_INFO_THEORY 40
         #endif
    #ifndef QUAL_INTERFACE
    #define QUAL_INTERFACE 41
         #endif
    #ifndef QUAL_DATABASES
    #define QUAL_DATABASES 42
         #endif
    #ifndef QUAL_CONCURRENCY
    #define QUAL_CONCURRENCY 43
         #endif
    #ifndef QUAL_NETWORKS
    #define QUAL_NETWORKS 44
         #endif
    #ifndef QUAL_COMPILERS
    #define QUAL_COMPILERS 45
         #endif
    #ifndef QUAL_STATS
    #define QUAL_STATS 46
         #endif
    #ifndef QUAL_SIMULATIONS
    #define QUAL_SIMULATIONS 47
         #endif
    #ifndef QUAL_SYSTEMS_MODELLING
    #define QUAL_SYSTEMS_MODELLING 48
         #endif
    #ifndef QUAL_NUM_METHOD
    #define QUAL_NUM_METHOD 49
         #endif
    #ifndef QUAL_BUSINESS
    #define QUAL_BUSINESS 50
         #endif

/********************************************************************
* QUANTIFIERS
*    values that quantifies things that may be strings in .txt file
*********************************************************************/

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
    #ifndef HLP101H
    #define HLP101H 0
    #endif
    #ifndef HLP101HTAH
    #define HLP101HTAH 1
    #endif
    #ifndef CSC108H
    #define CSC108H 2
    #endif
    #endif
    #ifndef CSC148H
    #define CSC148H 3
    #endif
    #ifndef CSC165H
    #define CSC165H 4
    #endif
    #ifndef CSC207H
    #define CSC207H 5
    #endif
    #ifndef CSC209H
    #define CSC209H 6
    #endif
    #ifndef CSC324H
    #define CSC324H 7
    #endif
    #endif
    #ifndef CSC373H
    #define CSC373H 8
    #endif

//    WILLINGNESS
//        currently arbitrarily defined
//        (perhaps change values to the number of "points" each rank rewards for Kevin and Karl's part)
    #ifndef 1ST
    #define 1ST 7
    #endif
    #ifndef 2ND
    #define 2ND 6
    #endif
    #ifndef 3RD
    #define 3RD 4
    #endif
    #endif
    #ifndef PREF
    #define PREF 2
    #endif
    #ifndef WILL
    #define WILL 1
    #endif
    #ifndef UNWILL
    #define UNWILL 0
    #endif
