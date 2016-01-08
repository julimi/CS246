#ifndef __a4q3b__doublewords__
#define __a4q3b__doublewords__
#include <iostream>
#include <string>
#include "textprocess.h"
#include "decorator.h"

class DoubleWords: public Decorator {
    /* sign the word has already doubled or not
     * sign = 0, NO
     * sign = 1, YES */
    int sign;
    // the copy word
    std::string rword;
public:
    DoubleWords(TextProcessor *tp);
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
};

#endif /* defined(__a4q3b__doublewords__) */
