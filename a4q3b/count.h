#ifndef __a4q3b__Count__
#define __a4q3b__Count__
#include <iostream>
#include <string>
#include "textprocess.h"
#include "decorator.h"

class Count: public Decorator {
    // the given char
    char c;
    // the count number
    int count;
public:
    Count(TextProcessor *tp, char c);
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
};

#endif /* defined(__a4q3b__Count__) */
