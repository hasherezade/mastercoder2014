/* by: hasherezade@op.pl */
#include "Walls.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>      /* printf */


Walls::Walls(const std::vector<unsigned int>& wallsVec, bool visual)
		: walls(wallsVec), totalFilling(0), localMax(NULL)
{
	if (visual) this->localMax = new std::set<long>();
	calcTotalFilling();
}


long Walls::calcFilling(long from, long to)
{
	unsigned int max = 0;
	long long chunkFilling = 0;
	
	long increment = from < to ? 1 : (-1);

	long chunkEnd = -1;
	long indx = from; 

	while (true) {
		if (increment > 0) {
			if (indx > to) break;
		} else if (indx < to) break;
	
		unsigned int wall = walls[indx];
		//---
		if (wall >= max) {
			chunkEnd  = indx;
			if (localMax) localMax->insert(chunkEnd);

			max = wall;
			this->totalFilling += chunkFilling;
			chunkFilling = 0;
		}
		chunkFilling += (max - wall);
		indx += increment;
		//---
	}
	if (chunkFilling == 0) return to;
	return chunkEnd;
}

long long Walls::calcTotalFilling()
{
	this->totalFilling = 0;

	long width = this->walls.size();

	long leftEnd = calcFilling(0, width - 1);
	if (leftEnd == width - 1) {
		return this->totalFilling;
	}
	calcFilling(width - 1, leftEnd);
	return this->totalFilling;
}

long long Walls::printWalls()
{
	long long dashes = 0;

	unsigned int maxH = 0;
	unsigned int maxL = 0;
	unsigned int maxR = 0;
	long width = this->walls.size();

	putchar('\n');

	for (long i = 0; i < width; i++ ) {
		unsigned int wall = walls[i];
		if (wall > maxH) maxH = wall;

		printf("[%4ld] %4u ", i, wall);

		if (localMax) {
			maxL = maxR;
			std::set<long>::iterator itr = localMax->upper_bound(i);
			if (itr != localMax->end())
				maxR = walls[*itr];
		}

		for (unsigned int p = 0; p < maxH; p++) {
			if (p < wall) putchar('#');
			else {
				if (p < maxL && p < maxH) {
					putchar('-');
					dashes++;
				}
			}
		}
		putchar('\n');
	}
	putchar('\n');
	return dashes;
}

std::vector<unsigned int> Walls::generateWalls(size_t maxW, size_t maxH)
{
	unsigned int hight;

	srand (time(NULL));
	std::vector<unsigned int> walls;
	
	while (walls.size() < maxW) {
		hight = rand() % maxH + 1;
		walls.push_back(hight);
	}
	return walls;
}

std::vector<unsigned int> Walls::generateWalls()
{
	srand (time(NULL));
	size_t maxW = rand() % 100 + 1;
	size_t maxH = rand() % 100 + 1;
	return generateWalls(maxW, maxH);
}

void Walls::printInput(const std::vector<unsigned int>& walls)
{
	long width = walls.size();

	for (long i = 0; i < width; i++ ) {
		unsigned int wall = walls[i];
		printf("%u ", wall);
	}
	putchar('\n');
}
