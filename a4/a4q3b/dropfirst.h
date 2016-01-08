#ifndef __a4q3b__dropfirst__
#define __a4q3b__dropfirst__
#include <string>
#include <iostream>
#include "textprocess.h"
#include "decorator.h"

class DropFirst: public Decorator {
    // the given number
    int n;
public:
    DropFirst(TextProcessor *tp, int n);
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
};

#endif /* defined(__a4q3b__dropfirst__) */
