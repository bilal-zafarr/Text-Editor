#pragma once
#include "Node.h"
class LinkedList
{
	Node* head;
	Node* tail;
public:
	LinkedList(); //constructor

	void remove(Node* x);  //removes a node x //used

	void print();//prints the whole list

	void insertBefore(Node* y, string s);   /*inserts a node before node y*/

	// Neeeded for text Editor
	void insert(string s, int insBefore);

	void del(int& currLine, int startRange = -1, int endRange = -1);

	void display(int& currLine, int startRange = -1, int endRange = -1);

	void appendInNode(string s, int nodeNo);

	string toString();

	~LinkedList();  //destructor
};