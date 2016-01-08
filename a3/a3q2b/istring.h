#ifndef __ISTRING_H__
#define __ISTRING_H__
#include <iostream>

struct iString{
    char * chars;
    unsigned int length;
    unsigned int capacity;
    iString();
    iString(const char *);
    iString(const iString&);
    ~iString();
    iString& operator=(const iString&);
};

// Add other declarations here:
iString operator+(const iString &a, const iString &b);
iString operator+(const iString &a, const char *c);
std::istream &operator>>(std::istream &in, iString &a);
std::ostream &operator<<(std::ostream &out, const iString &a);
iString operator*(const iString &a, int i);
iString operator*(int i, const iString& a);
#endif
