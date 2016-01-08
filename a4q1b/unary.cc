#include <string>

#include "unary.h"

using namespace std;

// ctor
Unary::Unary(int final, string expression, string uop): Expression(final, expression), uop(uop){}

void Unary::prettyprint() {
    
    // get the original expression first
    string nexp = getexpre();
    
    // update it by unary expression style
    if (uop == "ABS") nexp = "|" + nexp + "|";
    else if (uop == "NEG") nexp = "-" + nexp;
    
    // mutate the expression field of Expression
    smutator(nexp);
} // prettyprint

void Unary::evaluate() {
    
    // get the original final number first
    int nfinal = getfinal();
    
    // update it by various unary operators
    if (uop == "ABS") {
        if (nfinal < 0) nfinal = -nfinal;
    } else if (uop == "NEG") {
        nfinal = -nfinal;
    }
    
    // mutate the final field of Expression
    imutator(nfinal);
} // evaluate

// dtor
Unary::~Unary() {}
