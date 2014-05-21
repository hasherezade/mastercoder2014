#include <string>
#include <vector>
#include <algorithm>
#include <set>

#include "JaroWinkerTextDistance.h"

const double JaroWinkerTextDistance::TRESHOLD = 0.7;
const double JaroWinkerTextDistance::PREFIX_SCALING_FACTOR = 0.1;

DistanceValue *JaroWinkerTextDistance::calculateDistance(WordValue &word1, WordValue &word2)
{
	std::string s1 = word1.toString();
	std::string s2 = word2.toString();
	double distance = calcDist(s1, s2);
	return new DistanceValue(distance);
}

std::string indexesToString(const std::set<int> &indexes, const std::string &origStr)
{
	std::string newString;

	std::set<int>::iterator itr;
	for (itr = indexes.begin(); itr != indexes.end(); itr++) {
		char c = origStr[*itr];
		newString.push_back(c);
	}
	return newString;
}

bool hasIndex(const std::set<int> &indexes, const int indx)
{
	return (indexes.find(indx) != indexes.end());
}

int JaroWinkerTextDistance::countTranspositions(const std::string &ms1, const std::string &ms2)
{
	int len = std::min(ms1.length(), ms2.length());
	int transpositions = 0;
	for (unsigned int i = 0; i < len; i++) {
		if (ms1[i] != ms2[i]) {
			transpositions++;
		}
	}
	return transpositions;
}

int JaroWinkerTextDistance::countPrefixLength(const std::string &s1, const std::string &s2)
{
	int len = std::min(s1.length(), s2.length());
	int prefixLen = 0;
	for (int i = 0; i < len && s1[i] == s2[i]; i++)
	{
		prefixLen++;
	}
	return prefixLen;
}

double JaroWinkerTextDistance::jaroScore(float m, float t, int len1, int len2)
{
	float num1 = m / len1;
	float num2 = m / len2;
	float num3 = (m - t) / m;
	
	double distance = (num1 + num2 + num3) / 3;
	return distance;
}

double JaroWinkerTextDistance::calcDist(const std::string &s1, const std::string &s2)
{
	const std::string &max = (s1.length() > s2.length())? s1 : s2;
	const std::string min = (s1.length() <= s2.length())? s1 : s2;
	const int maxLen = max.length();
	const int minLen = min.length();

	const int range = std::max(static_cast<int>(maxLen / 2 - 1), 0);

	std::set<int> matchIndexMin;
	std::set<int> matchIndexMax;

	for (int i = 0; i < minLen; i++)
	{
		int start = std::max(i - range, 0);
		int end = std::min((i + range + 1), maxLen);
		
		for (int j = start; j < end; j++) {
			if (min[i] == max[j] && !hasIndex(matchIndexMax, j))
			{
				matchIndexMin.insert(i);
				matchIndexMax.insert(j);
				break;
			}
		}
	}
	int matches = matchIndexMax.size();
	if (matches == 0)
	{
		return 0.0;
	}
//---------------------------
	std::string ms1 = indexesToString(matchIndexMin, min);
	std::string ms2 = indexesToString(matchIndexMax, max);
	
	int transpNum = countTranspositions(ms1, ms2);
	int prefixLen = countPrefixLength(s1, s2);

	double distance = jaroScore(matches, (transpNum / 2), s1.length(), s2.length());
	if (distance < TRESHOLD)
	{
		return distance;
	}
	distance += std::min(PREFIX_SCALING_FACTOR, 1.0 / maxLen) * prefixLen * (1 - distance);
	return distance;
}
