#ifndef __a4q1b__expression__
#define __a4q1b__expression__

#include <string>

class Expression {
    // final number
    int final;
    // expression
    std::string expression;
protected:
    // mutators
    void smutator(const std::string &s);
    void imutator(const int &i);
public:
    Expression(int final, std::string expression); // ctor
    
    // accessors
    int getfinal() const;
    std::string getexpre() const;
    
    // pure virtual methods
    virtual void prettyprint() = 0;
    virtual void evaluate() = 0;
    virtual ~Expression(); // dtor
};

#endif /* defined(__a4q1b__expression__) */
