#ifndef INCLUDED_JAROWINKERTEXTDISTANCE_H_
#define INCLUDED_JAROWINKERTEXTDISTANCE_H_

#include "AbstractTextDistance.h"

class JaroWinkerTextDistance : public AbstractTextDistance
{
private:
	static const double TRESHOLD;
	static const double PREFIX_SCALING_FACTOR;

	static int countPrefixLength(const std::string &s1, const std::string &s2);
	static int countTranspositions(const std::string &ms1, const std::string &ms2);
	static double jaroScore(float m, float t, int len1, int len2);

protected:
	double calcDist(const std::string &s1, const std::string &s2);

public:
	virtual DistanceValue *calculateDistance(WordValue &word1, WordValue &word2);

	virtual const char* code() { return "J/W"; }
};

#endif // INCLUDED_JAROWINKERTEXTDISTANCE_H_