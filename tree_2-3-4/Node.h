#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
	Node (Node *father);
	Node (Node *father,int value);
	Node (Node *father, int value1, int value2);

	bool isLeave();
	bool isRoot();
	void insertChildren(int value);
	void split_up(int value);
	void split_brother(int value);
	vector <int> contect;
	vector <Node*> children;
	Node *father;
};