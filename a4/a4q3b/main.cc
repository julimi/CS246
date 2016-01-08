#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h"
#include "echo.h"
#include "decorator.h"
#include "dropfirst.h"
#include "doublewords.h"
#include "allcaps.h"
#include "count.h"

int main () {
    string s;
    
    while(1) {
        getline(cin,s);
        // if the cin fails, break the loop
        if (cin.fail()) break;
        
        // get each string in this line
        istringstream iss(s);
        string fname;
        iss >> fname;
        
        // seperate 2 situations: stdin and *.txt
        istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());
        
        
        TextProcessor *tp = new Echo;
        string dec;
        
        // point out which textprocessor we gonna use
        while (iss >> dec) {
            if (dec == "dropfirst") {
                int n;
                iss >> n;
                tp = new DropFirst(tp, n);
            }
            else if (dec == "doublewords") {
                tp = new DoubleWords(tp);
            }
            else if (dec == "allcaps") {
                tp = new Allcaps(tp);
            }
            else if (dec == "count") {
                char c;
                iss >> c;
                tp = new Count(tp, c);
            }
        } // while
        
        // get the source from stdin or *.txt
        tp->setSource(in);
        
        // get each word from source
        string word;
        
        // if not fail, print the word after processing
        while (word = tp->getWord(), !tp->fail()) {
            cout << word << endl;
        } // while
        
        if (in != &cin) delete in;
        
        delete tp;
    } // while
} // main
