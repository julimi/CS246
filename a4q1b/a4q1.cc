#include <iostream>
#include <string>
#include <sstream>

#include "integer.h"
#include "unary.h"
#include "binary.h"
#include "expression.h"

using namespace std;

int main() {
    // array of pointers to expression objects, with size 10
    Expression *stack[10];
    // current number of stack
    unsigned int nstack = 0;
    // input
    string in;
    // integer ot represent integer input
    int lone;
    
    while (cin >> in) {
        stringstream ii(in);
        
        // the lone integer expression:
        if (ii >> lone) {
            
            // situation of stack overflow
            if (nstack >= 10) {
                cerr << "Stack overflow" << endl;
                return 1;
            }
            // normal situation
            else stack[nstack++] = new Integer(lone, in, lone); // exit
        }
        
        // operators situations:
        else {
            
            // replaced final result
            int rfinal;
            // replaced expression
            string rexpre;
            
            // unary expression ABS or NEG:
            if (in.size() == 3) {
                
                // no stack before, ignore it
                if (nstack == 0) continue; // exit
                
                // get the number and expression firstly
                rfinal = stack[nstack - 1]->getfinal();
                rexpre = stack[nstack - 1]->getexpre();
                
                delete stack[nstack - 1];
                
                // make a new Unary class to replace original stack expression
                stack[nstack - 1] = new Unary(rfinal, rexpre, in);
                
                // update expression
                stack[nstack - 1]->prettyprint();
                // update final number
                stack[nstack - 1]->evaluate();
            }
            
            // binary expression +, -, * amd /
            else {
                
                // no stack before, the binary situation cannot continue
                if (nstack == 0) return 1;
                
                // 1 stack before, we still need 1 more
                else if (nstack == 1) continue;
                
                // second int for binary expression
                int rsec;
                // second expression for binary expression
                string ranother;
                
                /* get the first number, first expression,
                 * second number and second expression firstly */
                rfinal = stack[nstack - 2]->getfinal();
                rsec = stack[nstack - 1]->getfinal();
                rexpre = stack[nstack - 2]->getexpre();
                ranother = stack[nstack - 1]->getexpre();
                
                delete stack[nstack - 1];
                delete stack[nstack - 2];
                
                /* after operating bop, num of stack loses 1
                 * because we combines 2 numbers */
                --nstack;
                
                // make a new Binary class to replace original stack expression
                stack[nstack - 1] = new Binary(rfinal, rexpre, in, rsec, ranother);
                
                // update expression
                stack[nstack - 1]->prettyprint();
                // update final number
                stack[nstack - 1]->evaluate();
            } // exit
        } // exit
    } // while
    
    // the printing process:
    /* we can print final number
     * if we have taken up 1 stack */
    if (nstack == 1) {
        
        // print it
        cout << stack[0]->getexpre() << endl;
        cout << "= " << stack[0]->getfinal() <<endl;
        
        delete stack[0];
    } // exit
} // main
