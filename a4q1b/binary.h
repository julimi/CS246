#ifndef __a4q1b__binary__
#define __a4q1b__binary__

#include <string>

#include "expression.h"

class Binary: public Expression {
    
    // binary operator
    std::string bop;
    // the second number to operate
    int second;
    // the second expression to operate
    std::string another;
public:
    Binary(int final, std::string expression, std::string bop, int second, std::string another);
    void prettyprint();
    void evaluate();
    ~Binary();
};
#endif /* defined(__a4q1b__binary__) */
