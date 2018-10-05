#include "WordList.h"
#include <iostream>
#include <string>

using std::cout;




/*********************
 
 main:
 Simple driver program
 
 *********************/
int main() {
    WordList wl("input.txt");
    wl.printList(cout);
    return 0;
}
