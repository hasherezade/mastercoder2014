#include <string.h>
#include <stdio.h>
#include <iostream>

#include "Grid.h"

using namespace std;

const char* V_PARAM = "-v";

const size_t MODE_PARAM_LEN = 1;
const char PATH_ONLY_PARAM = 'P';
const char OTHERS_PARAM = 'O';
const char PATH_AND_OTHERS_PARAM = 'A';

int getPath(const char* fileName, int wiersz, int kolumna, bool visual, Grid::PrintMode vMode = Grid::PATH_ONLY)
{
	int ret = 0;
	int x  = kolumna - 1;
	int y = wiersz - 1;
	try {
		Grid g(fileName, x, y);
		g.printMinPath();

		if (visual) {
			g.printGrid(vMode);
		}
	} catch (exception &e) {
		std::cerr << e.what() << std::endl;
		ret = -1;
	}
	return ret;
}

Grid::PrintMode parseMode(int argc, char* argv[], const int argIndex)
{
	Grid::PrintMode defaultParam = Grid::PATH_ONLY;
	if (argc <= argIndex) {
		return defaultParam;
	}
	if (strlen(argv[argIndex]) < MODE_PARAM_LEN) {
		return defaultParam;
	}
	char firstCh = toupper(argv[argIndex][0]);
	switch(firstCh) {
		case PATH_ONLY_PARAM : 
			return Grid::PATH_ONLY;

		case OTHERS_PARAM : 
			return Grid::OTHERS_ONLY;

		case PATH_AND_OTHERS_PARAM : 
			return Grid::PATH_AND_OTHERS;
	}
	return defaultParam;
}

int main (int argc, char* argv[]) 
{
	if (argc < 4) {
		std::cerr << "required args: <fileName> <row> <column>\n"
					 << "optional: <" << V_PARAM << "> for visualization\n"
					 << "\t" << V_PARAM << " "<< PATH_ONLY_PARAM << "  show only path\n"
					 << "\t" << V_PARAM << " "<< OTHERS_PARAM << "  show only path surroundings\n"
					 << "\t" << V_PARAM << " "<< PATH_AND_OTHERS_PARAM << "  all - show path and surroundings\n"
					 << std::endl;
		return -1;
	}
	const char *fileName = argv[1];
	int row = 0, column = 0;

	sscanf(argv[2], "%d", &row);
	sscanf(argv[3], "%d", &column);

	bool visualization = false;
	Grid::PrintMode vMode = Grid::PATH_ONLY;

	if (argc > 4) {
		char *pos = strstr(argv[4], V_PARAM);
		if (pos != NULL) {
			visualization = true;
			vMode = parseMode(argc, argv, 5);
		}
	}
	int ret = getPath(fileName, row, column, visualization, vMode);
	return ret;
}
