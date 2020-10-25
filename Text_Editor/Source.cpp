#include "LinkedList.h"
#include <fstream>

string filename = "Default";

void check(string s, LinkedList& L, int& i);
void takeInput(LinkedList& L, int& currLine);

void insert(string s, LinkedList& L, int& currLine) {

	if (s.size() <= 2) {
		cout << currLine << ">\t"; getline(cin, s);
		check(s, L, currLine);
		return;
	}

	else {
		int toInsertBefore; string toConvert = "";
		for (int j = 2; s[j] || s[j] == ' '; j++)
			toConvert += s[j];
		toInsertBefore = stoi(toConvert);

		currLine = toInsertBefore;
		cout << currLine << ">\t"; getline(cin, s);
		check(s, L, currLine);
	}
}


void del(string s, LinkedList& L, int& currLine) {

	if (s == "D") {
		L.del(currLine);
		takeInput(L, currLine);
	}

	int startRange = -1, endRange = -1;

	string toConvert = ""; int j;

	for (j = 2; s[j]; j++) {
		if (s[j] == ' ')
			break;
		toConvert += s[j];
	}

	startRange = stoi(toConvert);

	if (s[j] == ' ') {
		toConvert = "";
		for (j + 1; s[j] != '\0'; j++)
			toConvert += s[j];
		endRange = stoi(toConvert);
	}

	L.del(currLine, startRange, endRange);
	takeInput(L, currLine);
}

void display(string s, LinkedList& L, int& currLine) {
	if (s == "L")
	{
		cout << "------------------------------------\n";
		cout << "          DISPLAYING\n";
		cout << "------------------------------------\n";
		L.print();
		cout << "------------------------------------\n\n";
		takeInput(L, currLine);
	}

	int startRange = -1, endRange = -1;

	string toConvert = ""; int j;

	for (j = 2; s[j]; j++) {
		if (s[j] == ' ')
			break;
		toConvert += s[j];
	}

	startRange = stoi(toConvert);

	if (s[j] == ' ') {
		toConvert = "";
		for (j + 1; s[j] != '\0'; j++)
			toConvert += s[j];
		endRange = stoi(toConvert);
	}
	cout << "------------------------------------\n";
	cout << "          DISPLAYING\n";
	cout << "------------------------------------\n";
	L.display(currLine, startRange, endRange);
	cout << "------------------------------------\n\n";
	takeInput(L, currLine);
}

void append(string s, LinkedList& L, int& currLine) {
	string st;
	cout << currLine << ">\t"; getline(cin, st);
	L.appendInNode(st, currLine);
	currLine++;
}

void check(string s, LinkedList& L, int& i) {

	if (s.substr(0, 2) == "I " || s == "I")
		insert(s, L, i);

	else if (s.substr(0, 2) == "D " || s == "D")
		del(s, L, i);

	else if (s.substr(0, 2) == "L " || s == "L")
		display(s, L, i);

	else if (s == "A")
		append(s, L, i);

	else if (s == "E") {
		ofstream out(filename + ".txt");
		out << L.toString();
		out.close();
		exit(0);
	}

	else
	{
		L.insert(s, i);
		i++;
	}
	takeInput(L, i);
}

void takeInput(LinkedList& L, int& currLine) {
	string s;
	cout << currLine << ">\t"; getline(cin, s);
	check(s, L, currLine);
}



int main() {

	string s;

	cout << "--------------------------------------\n";
	cout << "     WELCOME TO MY TEXT EDITOR\n";
	cout << "--------------------------------------\n\n";

	getline(cin, s);

	if (s.substr(0, 4) == "EDIT" || s.substr(0, 4) == "edit") {

		if (s.size() > 5)
			filename = s.substr(5, s.size() - 5);

		LinkedList L;

		int currLine = 1;

		while (true)
		{
			takeInput(L, currLine);
		}
	}
	else
		cout << "\n-------Invalid Command-------\n";
	return 0;
}