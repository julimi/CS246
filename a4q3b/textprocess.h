#ifndef __TEXTPROCESS_H__
#define __TEXTPROCESS_H__
#include <iostream>
#include <string>

// abstract base class for Echo and Decorator
class TextProcessor {
public:
    virtual void setSource(std::istream *inp) = 0;
    virtual std::string getWord() = 0;
    virtual bool fail() const = 0;
    virtual ~TextProcessor();
};

#endif /* defined(__a4q3b__textprocess__) */

