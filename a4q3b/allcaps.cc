#include <iostream>
#include <string>
#include "allcaps.h"

using namespace std;

// ctor
Allcaps::Allcaps(TextProcessor *tp): Decorator(tp) {}

// set source from input
void Allcaps::setSource(istream *inp) {
    tp->setSource(inp);
} // setSource

// get the word after processing
string Allcaps::getWord() {
    string nword = tp->getWord();
    
    /* searching the lower case char,
     * and change them into upper case */
    for (int i = 0;i < nword.size();++i) {
        if (nword[i] >= 'a' && nword[i] <= 'z') nword[i] += ('A' - 'a');
    } // for
    return nword;
} // getWord

// check it fail or not
bool Allcaps::fail() const {
    return tp->fail();
} // fail
