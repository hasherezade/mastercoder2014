#ifndef INCLUDED_LAVENSTEINTEXTDISTANCE_H_
#define INCLUDED_LAVENSTEINTEXTDISTANCE_H_

#include "AbstractTextDistance.h"

class LevensteinTextDistance : public AbstractTextDistance
{
private:
	double calcDist(const std::string &s1, const std::string &s2);

public:
	virtual DistanceValue *calculateDistance(WordValue &word1, WordValue &word2);

	virtual const char* code() { return "LEV"; }
};


#endif // INCLUDED_LAVENSTEINTEXTDISTANCE_H_