#include <string>
#include <iostream>
#include <istream>
#include <stdio.h>      /* printf */
#include <cstring>

#include "Walls.h"

using namespace std;

int main (int argc, char* argv[]) {
	
	bool visualise = false;
	bool testMode = false;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-v") == 0) visualise = true;
		if (strcmp(argv[i], "-t") == 0) testMode = true;
	}
	
	std::vector<unsigned int> walls;
	if (testMode == false) {
		unsigned int val;
		while ((std::cin.peek() !='\n') && (std::cin>>val)) {
			walls.push_back(val);
		}
	} else {
		walls = Walls::generateWalls();
		Walls::printInput(walls);
	}
	Walls w(walls, visualise);
	long long totalFilling = w.getFilling();
	printf("%lld\n", totalFilling);

	if (visualise) {
		long long dashes = w.printWalls();
		if (totalFilling == dashes) {
			printf("[OK]\n");
		} else printf("[FAIL]\n");
	}
	return 0;
}
