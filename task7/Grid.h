/* by: hasherezade@op.pl */
#pragma once

#include <iostream>
#include <vector>
#include <set>

#include <exception>
#include <stdexcept>

#include "Node.h"


class Grid
{
public:
	enum PrintMode
	{
		NO_PATH = 0,
		PATH_ONLY,
		OTHERS_ONLY,
		PATH_AND_OTHERS
	};

	Grid(const char* fileName, int startX, int startY);
	virtual ~Grid();

	void printGrid(const PrintMode &mode);
	void printMinPath();
	size_t getMinPathLen() { return this->minPathLen; }

protected:
	long readCsvLine(std::string &line, long lineNum);
	long readCsvFile(const char* fileName);

	Node* getAt(long x, long y);
	bool findMinPath();

	bool fillLayer(std::set<Node*> *layer1, std::set<Node*> *layer2);
	bool fetchNbrs(Node *n, std::set<Node*> &nSet);
	bool fetchIfNbr(Node *parent, Node *candidate, std::set<Node*> &nSet);

	bool isStop(Node &n) { return (n.h == 0); }
	bool isStart(Node &n) { return (n.x == this->sX && n.y == this->sY); }

	void printNode(Node &n);

	// pole startowe:
	int sX, sY;

	long width, height;
	std::vector<Node*> nodes;

	Node* minNode;
	size_t minPathLen;
};