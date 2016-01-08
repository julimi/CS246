#ifndef __a4q3b__allcaps__
#define __a4q3b__allcaps__
#include <iostream>
#include <string>
#include "textprocess.h"
#include "decorator.h"

class Allcaps: public Decorator {
public:
    Allcaps(TextProcessor *tp);
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
};

#endif /* defined(__a4q3b__allcaps__) */
