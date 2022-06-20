#ifndef header
#define header

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct People {
	string name;
	int height;
	int weight;
	People* next;
};

struct PeopleList {
	People* first;
	People* last;
};

void print_output(PeopleList* P, int x);
PeopleList* read_file(string input_file);

void main_testcases(string input_file, int x);
void main_debug(string input_file, int x);

bool addHead(People*& pnode);
bool addTail(People*& pnode);

#endif
