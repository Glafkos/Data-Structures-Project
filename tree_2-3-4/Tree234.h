#pragma once
#include "Node.h"


class Tree234
{
public:
	Node *root;
	Tree234 (int);
	Tree234 (Node*);

	void insert (int value);

	vector <int> toIntArray(Node* x);
	
	Node* findNode(int value, Node* root);
	
	void print();
	
	void print_help(Node *);
	
	int numberOfNodes();
	
	int numberOfNodes(Node *root);
	
	bool Empty();
	
	bool Contains(int key, Node* temp);

	void delete_value(int value);

};