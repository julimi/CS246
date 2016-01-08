#ifndef __a4q1b__integer__
#define __a4q1b__integer__

#include <string>

#include "expression.h"

class Integer: public Expression {
    // lone integer
    int lone_integer;
public:
    Integer(int final, std::string expression, int lone_integer);
    void prettyprint();
    void evaluate();
    ~Integer();
};

#endif /* defined(__a4q1b__integer__) */
