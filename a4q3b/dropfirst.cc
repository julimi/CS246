#include <string>
#include <iostream>
#include "dropfirst.h"

using namespace std;

// ctor
DropFirst::DropFirst(TextProcessor *tp, int n): Decorator(tp), n(n) {}

// set source from input
void DropFirst::setSource(istream *inp) {
    tp->setSource(inp);
} // setSource

// get the word after processing
string DropFirst::getWord() {
    string nword = tp->getWord();
    
    /* if the size of word is smaller than
     * or equal to n */
    if (nword.size() <= n) {
        // check if it is not fail, run getWord() recursively
        if (!tp->fail()) return getWord();
    }

    /* if n is smaller than the size of word,
     * cut the first n char of the word */
    else nword = nword.substr(n); // exit
    
    return nword;
} // getWord

// check it fail or not
bool DropFirst::fail() const {
    return tp->fail();
} // fail
