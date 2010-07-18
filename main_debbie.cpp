/**************************************************************
* stuff i copied from huff assignment, for personal reference
**************************************************************/
#include "input_debbie.h"

//1. Takes the name of a file to view as the first command-line argument
int main(int argc, char* argv[]) {
    if (argc < 2) { cout << "Error: Use 1 Argument." << endl; return EXIT_FAILURE;}
    Input in;
    in.store_info(argv[1]);
    
    return 0;

}
