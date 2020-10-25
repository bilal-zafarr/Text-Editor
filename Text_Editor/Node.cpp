#include "Node.h"

Node::Node(string s, Node* p, Node* n)
{
	line = s;
	prev = p;
	next = n;
}
