#ifndef __a4q1b__unary__
#define __a4q1b__unary__

#include <string>

#include "expression.h"

class Unary: public Expression {
    
    // unary operator
    std::string uop;
public:
    Unary(int final, std::string expression, std::string uop);
    void prettyprint();
    void evaluate();
    ~Unary();
};

#endif /* defined(__a4q1b__unary__) */
