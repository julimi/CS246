#include <string>
#include <sstream>

#include "integer.h"

using namespace std;

// ctor
Integer::Integer(int final, string expression, int lone_integer): Expression(final, expression), lone_integer(lone_integer) {}

void Integer::prettyprint() {
    // change the lone integer to string
    string lone_integers;
    stringstream si;
    si << lone_integer;
    si >> lone_integers;
    
    // update the expression
    string nexp = getexpre();
    nexp += lone_integers;
    
    // mutate the expression field of Expression
    smutator(nexp);
} // prettyprint

void Integer::evaluate() {
    
    // mutate the final field of Expression
    imutator(lone_integer);
} // evaluate

// dtor
Integer::~Integer() {}
