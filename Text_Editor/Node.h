#pragma once
#include<iostream>
#include<string>
using namespace std;

class LinkedList;
class Node
{
public:
	friend LinkedList;
	string line;
	Node* prev;
	Node* next;
public:
	Node(string s = "", Node* p = NULL, Node* n = NULL);
};

