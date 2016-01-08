#include <iostream>
#include <string>
#include "echo.h"
using namespace std;

// ctor: original source is null
Echo::Echo(): source(0) {}

// get the input, let source equals to it
void Echo::setSource(istream *in) { source = in; }  // setSource

// get the word from input
string Echo::getWord() {
    string s;
    
    // put input source in s
    *source >> s;
    
    // if input source fail, echo fail; otherwise.
    failed = source->fail();
    
    return s;
} // getWord

// check it fail or not
bool Echo::fail() const { return failed; }
