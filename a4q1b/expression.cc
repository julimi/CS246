#include <string>

#include "expression.h"

using namespace std;

// ctor
Expression:: Expression(int final, string expression): final(final), expression(expression) {}


int Expression::getfinal() const {
    return final;
} // getfinal

string Expression::getexpre() const {
    return expression;
} // getexpre

// help objects to mutate the private field:
void Expression::smutator(const string &s) {
    expression = s;
} // smutator
void Expression::imutator(const int &i) {
    final = i;
} // imutator

// dtor
Expression::~Expression() {}
