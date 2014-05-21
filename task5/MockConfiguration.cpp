#include "MockConfiguration.h"

DistanceType MockConfiguration::getDistnanceType()
{
	return currentType;
}

void MockConfiguration::useJaroWinkler()
{
	currentType = JARO_WINKLER;
}

void MockConfiguration::useLevenshtein()
{
	currentType = LEVENSHTEIN;
}