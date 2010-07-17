#include "definitions_debbie.cpp"

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
class Input{
private:
/** Structures **/

/*******************************************************************
* INFORMATION MATRIX
*    information directly from .txt file
*       col: applicant
*       row: qualification
*    known problems: several data types in the same array??
*        potential solution: several arrays, one for each category
*
*
*
//Index       Index Label     Value               Notes
//
//Category 1 / Indices 0-2 / TA Identifier
//    0       NAME_FIRST      string
//    1       NAME_MIDDLE     string
//    2       NAME_LAST       string
//
//Category 2 / Indices 3-5 / Experience information
//    3       EXP_LVL         int
//    4       EXP_COURSES     bool[NUM_COURSE]    index of subarray: course identifier; value: taken = TRUE; not taken = FALSE
//    5       EXP_PAST_TASHIP int
//
//Category 3 / Indices 6-7 / Preferences
//    6       PREF_PREF       int[NUM_COURSE]     index of subarray: course identifier; value: willingness
//    7       PREF_PREV       int[NUM_COURSE]     index of subarray: course identifier; value: prev. appts.
//
//Category 4 / Indices 8-11 / Guarantees
//    8       TASHIP_OWE      int                 = TAships guaranteed
//    9       TASHIP_MIN      int                 = Min TAships willing
//    10      TASHIP_MAX      int                 = Max TAships willing
//    11      TASHIP_PREF     int                 = TAships wanted
//
//Category 5 / Indices 12-50 / Qualifications
//    12      QUAL_READ       int
//    13      QUAL_WRITE      int
//    14      QUAL_CONV       int
//    15      QUAL_JAVA       int
//    16      QUAL_C          ...
//    17      QUAL_CPP
//    18      QUAL_BASIC
//    19      QUAL_PROLOG
//    20      QUAL_LISP
//    21      QUAL_ML
//    22      QUAL_CVS
//    23      QUAL_CSIM
//    24      QUAL_MAPLE
//    25      QUAL_MATLAB
//    26      QUAL_RCS
//    27      QUAL_PERL
//    28      QUAL_PYTHON
//    29      QUAL_HTML
//    30      QUAL_UML
//    31      QUAL_UNIX
//    32      QUAL_TOOLS
//    33      QUAL_SHELL
//    34      QUAL_MAKE
//    35      QUAL_ASSEMBLY
//    36      QUAL_LOGIC
//    37      QUAL_CIRCUITS
//    38      QUAL_GRAPHICS
//    39      QUAL_WEB_PROG
//    40      QUAL_INFO_THEORY
//    41      QUAL_INTERFACE
//    42      QUAL_DATABASES
//    43      QUAL_CONCURRENCY
//    44      QUAL_NETWORKS
//    45      QUAL_COMPILERS
//    46      QUAL_STATS
//    47      QUAL_SIMULATIONS
//    48      QUAL_SYSTEMS_MODELLING
//    49      QUAL_NUM_METHOD
//    50      QUAL_BUSINESS
*
********************************************************************/

//structure for category 1:
//  The identity array assigns an index number to a TA for use/reference throughout the rest of the program
//  How to use: identity[NAME_FIRST or NAME_MIDDLE or NAME_LAST][assigned TA #]
vector <string> identity[3];

public:

/** Functions **/

/*******************************************************************
* Method:
* - reads in .txt file
* - convert read info to information matrix
* - scan string produced by applicant on file for key words
*******************************************************************/

Input();

void store_info(const char *);


};

#endif//INPUT_H_INCLUDED
