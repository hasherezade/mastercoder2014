#ifndef INCLUDED_TEXTSIMILARITYSERVICEIMPL_H_
#define INCLUDED_TEXTSIMILARITYSERVICEIMPL_H_

#include "AbstractTextDistance.h"
#include "AbstractConfiguration.h"
#include <map>

class TextSimilarityServiceImpl : public AbstractTextDistance
{
private:
	AbstractConfiguration* configurationService;
	AbstractTextDistance* strategy;
	std::map<DistanceType, AbstractTextDistance*> strategies;
	
	void clearStrategies();
	bool switchStrategy();

public: 
    TextSimilarityServiceImpl(AbstractConfiguration *config);
	virtual ~TextSimilarityServiceImpl() { clearStrategies(); }

	void registerStrategy(DistanceType type, AbstractTextDistance* strategy);

    virtual DistanceValue *calculateDistance(WordValue &word1, WordValue &word2);

	virtual const char* code() { return strategy ? strategy->code() : "NULL"; }
};


#endif // INCLUDED_TEXTSIMILARITYSERVICEIMPL_H_