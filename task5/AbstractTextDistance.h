#ifndef INCLUDED_ABSTRACTTEXTDISTANCE_H_
#define INCLUDED_ABSTRACTTEXTDISTANCE_H_

#include "WordValue.h"
#include "DistanceValue.h"

class AbstractTextDistance
{
public:
    virtual DistanceValue *calculateDistance(WordValue &word1, WordValue &word2) = 0;
	virtual const char* code() = 0;

    virtual ~AbstractTextDistance() {;}
};

#endif // INCLUDED_ABSTRACTTEXTDISTANCE_H_
