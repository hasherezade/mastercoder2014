/* by: hasherezade@op.pl */
#pragma once

#include <iostream>
#include <vector>
#include <set>

class Walls {
public:
	static std::vector<unsigned int> generateWalls();
	static std::vector<unsigned int> generateWalls(size_t maxW, size_t maxH);
	static void printInput(const std::vector<unsigned int>& walls);

	Walls(const std::vector<unsigned int>& wallsVec, bool visual = false);
	~Walls() { delete localMax; }

	long long getFilling() { return totalFilling; }
	long long printWalls();

protected:
	long long calcTotalFilling();
	long calcFilling(long from, long to);

	const std::vector<unsigned int>& walls;
	long long totalFilling;
	std::set<long> *localMax;
};