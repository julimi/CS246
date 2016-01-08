
#include <iostream>
#include <string>
#include <sstream>
#include "count.h"

using namespace std;

// ctor: original count is 1
Count::Count(TextProcessor *tp, char c): Decorator(tp), c(c), count(1) {}

// setSource from input
void Count::setSource(istream *inp) {
    tp->setSource(inp);
} // setSource

// get the word after processing
string Count::getWord() {
    
    string nword = tp->getWord();
    
    // search the char is c and change it into count
    for (unsigned long i = 0; i < nword.size(); ++i) {
        if (nword[i] == c) {
            // make a new string to store the count in string type
            string s;
            stringstream ss;
            ss << count;
            ss >> s;
            
            // update the word
            nword = nword.substr(0, i) + s + nword.substr(i + 1);
            
            // increment the count
            ++count;
            
            // consider the situation of 2 or more digit number of count
            if (s.size() != 1) i += (s.size() - 1);
        } //exit
    } // for
    
    return nword;
} // getWord

// check it fail or not
bool Count::fail() const {
    return tp->fail();
} // fail
