#include <string>
#include <vector>
#include <algorithm>

#include "LevensteinTextDistance.h"

//util:
int min(int inp1, int inp2, int inp3) {
	int minumum = std::min(inp1, inp2);
	return std::min(minumum, inp3);
}

DistanceValue *LevensteinTextDistance::calculateDistance(WordValue &word1, WordValue &word2)
{
	const std::string s1 = word1.toString();
	const std::string s2 = word2.toString();

	double distance = calcDist(s1, s2);
	
	return new DistanceValue(distance);
}

// applied algorithm: iterative with two matrix rows
double LevensteinTextDistance::calcDist(const std::string &target, const std::string &other)
{
	double distance = 0.0;

	const int targetLen = target.length();
	const int otherLen = other.length();

	if (targetLen == 0 || otherLen == 0) {
		if (targetLen == otherLen) {
			distance = 1;
		} else {
			distance = 0;
		}
		return distance;
	}

	std::vector<int> vec0(targetLen + 1);
	std::vector<int> vec1(targetLen + 1);

	std::vector<int> *prev = &vec0;
	std::vector<int> *curr = &vec1;

	for (int i = 0; i <= targetLen; i++)
	{
		prev->at(i) = i;
	}

	for (int j = 0; j < otherLen; j++)
	{
		curr->at(0) = j + 1;
		
		for (int i = 0; i < targetLen; i++)
		{
			int cost = target[i] == other[j] ? 0 : 1;

			int val1 = curr->at(i) + 1;
			int val2 = prev->at(i + 1) + 1;
			int val3 = prev->at(i) + cost;

			//minimum of three inputs:
			curr->at(i + 1) = min(val1, val2, val3);
		}
		//swap vectors
		std::vector<int> *temp = prev;
		prev = curr;
		curr = temp;
	}
	const int maxLen = std::max(otherLen, targetLen);
	double tDist = static_cast<double>(prev->at(targetLen));

	distance = 1.0 - (tDist / maxLen);
	return distance;
}
