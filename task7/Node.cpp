#include "Node.h"

#include <string>
#include <stdio.h>      // printf
#include <cmath>        // std::abs
#include <stack>


Node::Node(int height, int v_x, int v_y)
	: h(height), x(v_x), y(v_y)
{
	parent = NULL;
}

bool Node::canJump(Node *n)
{
	if (n == NULL) return false;
	int hDif = std::abs(n->h - this->h);
	if (hDif > 5) return false;
	return true;
}

void Node::printAddr()
{
	printf("[%d,%d]", y + 1, x + 1);
}

void Node::printPath(Node *startN)
{
	std::stack<Node*> nodes;

	Node *n = startN;
	while (n != NULL) {
		nodes.push(n);
		n = n->parent;
	}
	while (nodes.size()) {
		n = nodes.top();
		n->printAddr();
		nodes.pop();
		if (nodes.size()) putchar(';');
	}
	putchar('\n');
}