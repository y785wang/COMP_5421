#include "Led.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;




/**************************************************
 
 Description:
 Simple main function, check command line arguments,
 initialize Led object, run Led object.
 
 Parameters:
 argc: # of command line arguments + 1
 argv: string array contains name of the executable
       name followed by command line arguments.
 
 Returns:
 Return 0 for report success
 
 **************************************************/
int main(int argc, char * argv[]) {
    string filename; // an empty filename
    switch (argc) { // determine the filename
        case 1: // no file name
            break;
        case 2: filename = argv[1]; // initialize filename from argument
            break;
        default: cout << ("too many arguments - all discarded") << endl;
        break; }
    Led editor(filename); // create a Led named editor
    editor.run(); // run our editor
    return 0; // report success
}
