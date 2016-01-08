#include <string>

#include "binary.h"

using namespace std;

// ctor
Binary::Binary(int final, string expression, string bop, int second, string another):
Expression(final, expression), bop(bop), second(second), another(another) {}

void Binary::prettyprint() {
    
    // get the original expression first
    string nexp = getexpre();
    
    // update it by binary expression style
    nexp = "(" + nexp + " " + bop + " " + another + ")";
    
    // mutate the expression field of Expression
    smutator(nexp);
} // prettyprint

void Binary::evaluate() {
    
    // get the original final number first
    int nfinal = getfinal();
    
    // update it by various binary operators
    if (bop == "+") nfinal += second;
    else if (bop == "-") nfinal -= second;
    else if (bop == "*") nfinal *= second;
    else if (bop == "/") nfinal /= second;
    
    // mutate the final field of Expression
    imutator(nfinal);
} // evaluate

// dtor
Binary::~Binary() {}
