#include <iostream>
#include <sstream>

#include "textdisplay.h"

using namespace std;

// ctor
TextDisplay::TextDisplay(int n): View(n) {
    
    // new pointer to pointer
    theDisplay = new char *[n];
    
    // new arrays pointed by pointer to pointer
    for (int i = 0; i < n; ++i) {
        theDisplay[i] = new char [n];
    } // for
    
    // set each content of 2Darray as '0'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            theDisplay[i][j] = '0';
        } // for
    } // for
    
} // TextDisplay(int)

TextDisplay::~TextDisplay() {
    
    // delete each array firstly
    for (int i = 0; i < gridSize; i++) {
        delete [] theDisplay[i];
    } // for
    
    // delete the pointer to pointer
    delete [] theDisplay;
    
} // ~TextDisplay()

void TextDisplay::notify(int r, int c, char ch) {
    
    // update the (r,c) location to ch
    theDisplay[r][c] = ch;
    
} // notify

void TextDisplay::print(std::ostream &out) {
    
    // print all
    for (int i = 0; i < gridSize; i++) {
        
        // print content of theDisplay[i][0-(gridSize-1)]
        // at the same line firstly
        for (int j = 0; j < gridSize; j++) {
            out << theDisplay[i][j];
        } // for
        
        // end of line
        out << endl;
    } // for
} // print
