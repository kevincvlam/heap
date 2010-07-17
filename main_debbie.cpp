/**************************************************************
* stuff i copied from huff assignment, for personal reference
**************************************************************/
#include "input_debbie.cpp"

//1. Takes the name of a file to view as the first command-line argument
int main(int argc, char* argv[]) {

    if (argc != 1)  return EXIT_FAILURE;

    store_info(argv[1]);

}
