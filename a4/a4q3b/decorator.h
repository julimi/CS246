#ifndef __a4q3b__decorator__
#define __a4q3b__decorator__

// the basecase for all tps, abstract
class Decorator: public TextProcessor {
protected:
    TextProcessor *tp;
public:
    Decorator(TextProcessor *tp);
    virtual ~Decorator();
};

#endif /* defined(__a4q3b__decorator__) */
