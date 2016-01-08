#include "istring.h"
#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

// constructor of iString
iString::iString(): chars(NULL), length(0), capacity(0) {}
// iString::iString()

// create a new string
iString::iString(const char *a) {
    length = strlen(a);
    capacity = length * 2;
    chars = new char[capacity + 1];
    if (a) strcpy(chars, a);
} // iString::iString(const char *a)

/* copy of constructor:
 * copy another identical iString */
iString::iString(const iString& a) {
    length = a.length;
    capacity = a.capacity;
    chars = new char[capacity + 1];
    if (a.length) strcpy(chars, a.chars);
} // iString::iString(const iString& a)

// destructor
iString::~iString() {
    // delete if chars exists
    if (chars) delete [] chars;
    chars = NULL;
} // ~iString()

// operator= overload
iString & iString::operator=(const iString &other) {
   
    // return directly if equal
    if (this == &other) return *this;
    
    // delete original one, and create new to copy
    if (other.capacity != capacity) {
        if (chars) delete [] chars;
        chars = new char[other.capacity + 1];
        capacity = other.capacity;
    }
    length = other.length;
    if (other.chars) strcpy(chars, other.chars);
    return *this;    // return myself, using *this
} // iString::operator=

// operator+ overload
iString operator+(const iString &a, const iString &b) {
    iString c;

    // define length and capacity
    c.capacity = c.length = a.length + b.length; 
    c.chars = new char[c.capacity + 1];
    c.chars[0] = '\0';     // avoid crash if callstrcat directly
    if (a.length) strcpy(c.chars, a.chars);
    if (b.length) strcat(c.chars, b.chars);
    return c;
} // operator+(iString,iString)

// operator+ overload
iString operator+(const iString &a, const char *c) {
   
    // put the string c to iString and use + to run it with a
    return a + iString(c);
} // operator+(iString, char*)

// operator>> overload
istream &operator>>(std::istream &in, iString &a) {
    if (a.capacity == 0) {
        a.capacity = 5;
        a.chars = new char[a.capacity + 1];
    } // exit
    a.length = 0;
    in >> ws;     // skip all whitespace in `in`
   
    // while keep go on if do not meet '\0'
    while (!isspace(in.peek())) {
        char c;
        in >> c;

        // resize the allocation
        if (a.length == a.capacity) {
            a.capacity *= 2;
            char *temp = new char[a.capacity + 1];
            strcpy(temp, a.chars);
            delete [] a.chars;
            a.chars = temp;
        }
        a.chars[a.length++] = c;
        a.chars[a.length] = '\0';     // all cstring ends with '\0'
    }
    return in;
} // operator>>

// operator<< overload
ostream &operator<<(std::ostream &out, const iString &a) {
   
    // if string is not NULL, output it
    if (a.length) out << a.chars;
    return out;
} // operator<<

// operator* overload: iString * int
iString operator*(const iString &a, int i) {
    iString c;
    if (a.length == 0) return c;
    c.capacity = c.length = a.length * i;
    c.chars = new char[c.capacity + 1];
    c.chars[0] = '\0';
    for (int times = 0; times < i; ++times) {
        strcat(c.chars, a.chars);
    } // for
    return c;
} // operator*(iString,int)

// operator* overload: int * iString
iString operator*(int i, const iString &a) {
    return a * i;
} // operator*(int,iString)
