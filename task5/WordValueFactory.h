#ifndef INCLUDED_WORDVALUEFACTORY_H_
#define INCLUDED_WORDVALUEFACTORY_H_

#include "WordValue.h"

class WordValueFactory
{

public:

    WordValue* createWord(const char* str);

    virtual ~WordValueFactory() {;}

};

#endif // INCLUDED_WORDVALUEFACTORY_H_
