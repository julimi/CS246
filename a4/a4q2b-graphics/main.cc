#include "controller.h"
#include <iostream>
using namespace std;

/*
 * TODO: update main function to take argument "-graphics" for part b. 
 * If -graphics argument is provided, forward this to the controller
 */
int main (int argc, char *argv[]) {
    
    string ind;
    int i;
    // Note that loop starts from index 1
    for (int i = 1; i < argc; ++i) {
        ind = argv[i];
    }
    if (ind == "-graphics") i = 1;
    else i = 0;
    Controller c(i);
    c.play();
}
