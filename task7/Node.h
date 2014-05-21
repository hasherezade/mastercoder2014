/* by: hasherezade@op.pl */
#pragma once

#include <iostream>

class Node
{
public:
	static void printPath(Node *n);

	Node(int height, int v_x, int v_y);
	void printAddr();

	bool canJump(Node *n);

protected:
	Node* parent;
	int h;
	int x, y;

	friend class Grid;
};
