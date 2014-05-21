#include <string>
#include <vector>
#include <algorithm>

#include "TextSimilarityServiceImpl.h"
#include "DistanceType.h"

TextSimilarityServiceImpl::TextSimilarityServiceImpl(AbstractConfiguration *config)
	: strategy(NULL)
{
    configurationService = config;
}

void TextSimilarityServiceImpl::clearStrategies()
{
	std::map<DistanceType, AbstractTextDistance*>::iterator itr;
	for (itr = this->strategies.begin(); itr != this->strategies.end(); itr++) {
		delete itr->second;
	}
	this->strategies.clear();
}


void TextSimilarityServiceImpl::registerStrategy(DistanceType type, AbstractTextDistance* strategy)
{
	this->strategies[type] = strategy;
}

bool TextSimilarityServiceImpl::switchStrategy()
{
	if (configurationService == NULL) {
		printf("NULL configuration supplied!\n");
		return false;
	}

	strategy = this->strategies[configurationService->getDistnanceType()];
	if (strategy == NULL) {
		printf("Wrong configuration supplied!\n");
		return false;
	}
	return true;
}

DistanceValue* TextSimilarityServiceImpl::calculateDistance(WordValue &word1, WordValue &word2)
{
	if (!switchStrategy()) return NULL;
	return this->strategy->calculateDistance(word1, word2);
}
