#include <iostream>
#include <string>
#include "doublewords.h"

using namespace std;

// ctor: make original sign 0 and original copy word NULL
DoubleWords::DoubleWords(TextProcessor *tp): Decorator(tp), sign(0), rword("") {}

// set source from input
void DoubleWords::setSource(istream *inp) {
    tp->setSource(inp);
} // setSource

// get the word after processing
string DoubleWords::getWord() {
    string nword;
    
    // if no word doubled before
    if (sign == 0) {
        // get the word
        nword = tp->getWord();
        // change the sign into 1
        sign = 1;
        // update the copy word
        rword = nword;
    }
    // if there exists doubled word
    else {
        // let new word equals to copy word
        nword = rword;
        // let the sign back to 0
        sign = 0;
    } // exit
    
    return nword;
} // getWord

// check it fail or not
bool DoubleWords::fail() const {
    return tp->fail();
} // fail
