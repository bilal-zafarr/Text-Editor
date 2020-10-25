#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}

void LinkedList::remove(Node* x)
{
	if (x != nullptr && x != head && x != tail) {
		(x->prev)->next = x->next;
		(x->next)->prev = x->prev;
		delete x;
	}
}

void LinkedList::print()
{
	Node* t = head->next;
	int i = 1;
	while (t != tail)
	{
		cout << i++ << ">\t" << t->line << '\n';
		t = t->next;
	}
}

string LinkedList::toString()
{
	Node* t = head->next;
	int i = 1;
	string s;
	while (t != tail)
	{
		s = s + to_string(i) + ">\t" + t->line + '\n';
		i++;
		t = t->next;
	}
	return s;
}

LinkedList::~LinkedList()
{
	Node* curr = head->next; Node* t;
	while (curr->next != tail)
	{
		t = curr;
		curr = curr->next;
		delete t;
	}
}

void LinkedList::insertBefore(Node* y, string s)
{
	if (y != nullptr && y != head) {
		Node* t = new Node(s, y->prev, y);
		(y->prev)->next = t;
		y->prev = t;
	}
}


void LinkedList::insert(string s, int insBefore)
{
	Node* curr = head->next;

	for (int i = 1; i < insBefore; i++)
		curr = curr->next;

	insertBefore(curr, s);
}



void LinkedList::del(int& currLine, int startRange, int endRange)
{
	Node* curr = head->next;

	if (startRange == -1 && endRange == -1)
	{
		for (int i = 1; i < currLine - 1; i++)
			curr = curr->next;
		remove(curr);
		currLine--;
		return;
	}

	if (startRange != -1 && endRange == -1) {

		for (int i = 1; i < startRange; i++)
			curr = curr->next;
		remove(curr);
		currLine--;
		return;
	}

	if (startRange != -1 && endRange != -1) {

		for (int i = 1; i < startRange; i++)
			curr = curr->next;

		Node* t;

		for (int i = startRange; i <= endRange; i++)
		{
			t = curr;
			curr = curr->next;
			remove(t);
			currLine--;
		}
		return;
	}
}

void LinkedList::display(int& currLine, int startRange, int endRange)
{
	Node* curr = head->next;

	if (startRange != -1 && endRange == -1) {

		for (int i = 1; i < startRange; i++)
			curr = curr->next;
		cout << startRange << ">\t" << curr->line << '\n';
		return;
	}

	if (startRange != -1 && endRange != -1) {

		for (int i = 1; i < startRange; i++)
			curr = curr->next;

		for (int i = startRange; i <= endRange; i++)
		{
			cout << i << ">\t" << curr->line << '\n';
			curr = curr->next;
		}
		return;
	}
}

void LinkedList::appendInNode(string s, int nodeNo)
{
	Node* curr = head->next;
	for (int i = 1; i < nodeNo; i++)
		curr = curr->next;
	curr->line += s;
}