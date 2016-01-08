#ifndef __ECHO_H__
#define __ECHO_H__
#include <iostream>
#include <string>
#include "textprocess.h"

/* concrete implementation of TextProcessor
 * echoes the words in its input stream, one token at a time. */
class Echo: public TextProcessor {
    // input source
    std::istream *source;
    /* fail boolean
     * failed = 1, Fail
     * failed = 0, Not Fail */
    bool failed;
public:
    Echo();
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
};

#endif /* defined(__a4q3b__echo__) */
