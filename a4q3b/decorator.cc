#include "textprocess.h"
#include "decorator.h"

// ctor
Decorator::Decorator(TextProcessor *tp): tp(tp) {}

// dtor
Decorator::~Decorator() { delete tp; }
