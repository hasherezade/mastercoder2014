#include "Grid.h"

#include <string>
#include <istream>
#include <stdio.h>      /* printf */

#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>

Grid::Grid(const char* fileName, int startX, int startY)
	: sX(startX), sY(startY), width(0), height(0)
{
	minNode = NULL;
	minPathLen = 0;
	readCsvFile(fileName);
	findMinPath();
}

Grid::~Grid()
{
	std::vector<Node*>::iterator itr;
	for (itr = nodes.begin(); itr != nodes.end(); itr++) {
		Node *node = *itr;
		delete node;
	}
	nodes.clear();
}

long Grid::readCsvLine(std::string &line, long pY)
{
	long pX = 0;
	std::istringstream vStream(line);
	const char DELIMITER = ';';
	std::string s;

	while (std::getline(vStream, s, DELIMITER)) {
		int height = atoi(s.c_str());

		Node* n = new Node(height, pX, pY);
		nodes.push_back(n);
		pX++;
	}
	return pX;
}

long Grid::readCsvFile(const char* fileName)
{
	std::ifstream inFile;
	inFile.open(fileName);
	std::string line;

	this->width = 0;
	this->height = 0;
	if (inFile.is_open() == false) {
		throw std::invalid_argument("Cannot open file!");
	}
	while (inFile.good() && !inFile.eof()) {
		std::getline(inFile, line);
		if (line.size() == 0) break;

		long currCount = readCsvLine(line, this->height);
		if (this->width != 0 && currCount != this->width) {
			throw std::invalid_argument("Corrupted matrix!");
			break;
		}
		this->width = currCount;
		this->height++;
	}
	inFile.close();
	return this->height;
}

Node* Grid::getAt(long x, long y)
{
	if ( x < 0 || y < 0) return NULL;
	if ( x >= this->width || y >= this->height) return NULL;
	long pos = (this->width * y) + x;
	if (static_cast<long>(nodes.size()) <= pos) {
		return NULL;
	}
	return nodes.at(pos);
}

void Grid::printNode(Node &n)
{
	if (this->isStart(n)) {
		printf("{%3d}", n.h);
		return;
	}
	printf(" %3d ", n.h);
}

void Grid::printGrid(const PrintMode &mode)
{
	long x = 0, y = 0;
	std::set<Node*> *minSet = NULL;
	if (mode != NO_PATH) {
		minSet = new std::set<Node*>();
		Node *n = this->minNode;
		while (n != NULL) {
			minSet->insert(n);
			n = n->parent;
		}
	}
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			Node *n = this->getAt(x, y);

			if (mode == NO_PATH) {
				printNode(*n);
				continue;
			}

			if (minSet && minSet->find(n) == minSet->end()) {
				//node is part of path
				if (isStart(*n) == false
					&& mode == PATH_ONLY)
				{
					printf("[...]");
					continue;
				}
				printNode(*n);
				continue;

			}
			//node is NOT part of path
			if (mode == OTHERS_ONLY) {
				printf("[...]");
			} else {
				printf("[%3d]", n->h);
			}
		}
		printf("\n");
	}
	delete minSet;
}


bool Grid::fetchIfNbr(Node *parent, Node *candidate, std::set<Node*> &nSet)
{
	if (isStart(*candidate) == false 
		&& candidate->parent == NULL 
		&& parent->canJump(candidate)) 
	{
		candidate->parent = parent;
		nSet.insert(candidate);
		if (isStop(*candidate)) {
			this->minNode = candidate;
			return true;
		}
	}
	return false;
}

bool Grid::fetchNbrs(Node *n, std::set<Node*> &nSet)
{
	bool isStop = false;
	if (n->x > 0) {
		Node *left = this->getAt(n->x - 1, n->y);
		isStop = fetchIfNbr(n, left, nSet);
		if (isStop) return true;
	}
	if (n->x < (this->width - 1)) {
		Node *right = this->getAt(n->x + 1, n->y);
		isStop = fetchIfNbr(n, right, nSet);
		if (isStop) return true;
	}
	if (n->y > 0) {
		Node *up = this->getAt(n->x, n->y - 1);
		isStop =  fetchIfNbr(n, up, nSet);
		if (isStop) return true;
	}
	if (n->y < (this->height - 1)) {
		Node *down = this->getAt(n->x, n->y + 1);
		isStop = fetchIfNbr(n, down, nSet);
		if (isStop) return true;
	}
	return false;
}

bool Grid::fillLayer(std::set<Node*> *layer1, std::set<Node*> *layer2)
{
	std::set<Node*>::iterator itr;
	for (itr = layer1->begin(); itr != layer1->end(); itr++) {
		Node *iNode = *itr;
		fetchNbrs(iNode, *layer2);
		if (this->minNode != NULL) { // found
			return true;
		}
	}
	return false;
}

bool Grid::findMinPath()
{
	this->minNode = NULL;
	this->minPathLen = 0;

	Node *startN = this->getAt(sX, sY);
	if (startN == NULL) {
		throw std::invalid_argument("Start Node is out of martix!");
	}
	long len = 1;
	if (isStop(*startN)) {
		this->minNode = startN;
		this->minPathLen = len;
		return true;
	}

	std::set<Node*> set1;
	std::set<Node*> set2;

	std::set<Node*> *nbrs = &set1;
	std::set<Node*> *nbrs2 = &set2;

	this->fetchNbrs(startN, *nbrs);
	
	while (true) {
		nbrs2->clear();
		if (nbrs->size() == 0) {
			// Not found
			break;
		}
		len++;
		this->fillLayer(nbrs, nbrs2);
		if (this->minNode != NULL) { // found
			len++;
			break;
		}
		//swap
		std::set<Node*> *temp = nbrs;
		nbrs = nbrs2;
		nbrs2 = temp;
	}
	if (this->minNode == NULL) {
		return false;
	}
	this->minPathLen = len;
	return true;
}

void Grid::printMinPath()
{
	if (minNode) {
		Node::printPath(this->minNode);
	} else {
		printf("Not found!\n");
	}
}