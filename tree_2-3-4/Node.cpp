
#include <iostream>
#include "Node.h"
#include "Tree234.h"

using namespace std;

Node :: Node (Node* dad)
{
	father = dad;
}

Node :: Node (Node *dad, int value)
{
	father = dad;
	this->contect.push_back(value);
}

Node :: Node (Node *dad, int value1, int value2)
{
	father = dad;
	contect.push_back(value1);
	contect.push_back(value2);
}

bool Node :: isRoot()
{
	return (father == nullptr);
}

bool Node :: isLeave()
{
	return children.empty();
}

void Node :: insertChildren(int value)
{
	if (this->isRoot() && children.size() == 4)
		{
			split_up(value);
			return;
		}
	
	if (this->children.size() == 4 && this->father->contect.size() == 3)
	{
		this->split_up(value);
	}

	if (this->children.size() == 4 && this->father->children.size() < 4)
		{
			split_brother(value);
			return;
		}
	
	
	bool flag = false;

	for (int i = 0; ((i<children.size()) && (flag == false)); i++)
	{
		if (value < children[i]->contect[0])
			{
				children.insert(children.begin() + i, new Node(this, value));
				flag = true;
			}
	}

	if (flag == false)
		children.push_back(new Node (this,value));

	contect.clear();
	int j = 0;
	while (j<children.size()-1)
		{
			contect.push_back(children[j]->contect[0]);
			j++;
		}
}

void Node ::split_up(int value)
{
	bool flag = false;
	if (this->contect.size() <4)
	{
	for (int i = 0; ((i<children.size()) && (flag == false)); i++)
	{
		if (value < children[i]->contect[0])
			{
				children.insert(children.begin() + i, new Node(this, value));
				flag = true;
			}
	}

	if (flag == false)
		children.push_back(new Node (this,value));

	contect.clear();
	int j = 0;
	while (j<children.size()-1)
		{
			contect.push_back(children[j]->contect[0]);
			j++;
		}

	}

	vector <int> copyOfContect;
	
	copyOfContect = contect;

	sort(copyOfContect.begin(),copyOfContect.end());
	contect.clear();
	contect.push_back(copyOfContect[1]);

	vector <int> Leaves ;
	
	for (int i=0; i<children.size(); i++)
	{
		if (this->children[i]->isLeave())
			Leaves.push_back(children[i]->contect[0]);
	}

	
	children.clear();

	Node * leftChildren = new Node(this,copyOfContect[0]);
	children.push_back(leftChildren);

	Node * rightChildren = new Node(this,copyOfContect[2],copyOfContect[3]);
	children.push_back(rightChildren);

	leftChildren->insertChildren(Leaves[0]);
	leftChildren->insertChildren(Leaves[1]);

	rightChildren->insertChildren(Leaves[2]);
	rightChildren->insertChildren(Leaves[3]);
	rightChildren->insertChildren(Leaves[4]);

}

void Node ::split_brother(int value)
{
	bool flag = false;

	for (int i = 0; ((i<children.size()) && (flag == false)); i++)
	{
		if (value < children[i]->contect[0])
			{
				children.insert(children.begin() + i, new Node(this, value));
				flag = true;
			}
	}

	if (flag == false)
		children.push_back(new Node (this,value));

	contect.clear();
	int j = 0;
	while (j<children.size()-1)
		{
			contect.push_back(children[j]->contect[0]);
			j++;
		}

	vector <int> copyOfContect;
	
	copyOfContect = contect;

	
	sort(copyOfContect.begin(),copyOfContect.end());

	vector <int> leafValues;

	for (int i=0; i<children.size(); i++)
	{
		leafValues.push_back(children[i]->contect[0]);
	}

	sort (leafValues.begin() , leafValues.end());

	children.clear();
	
	Node *brother = new Node(this->father,copyOfContect[0]);
	
	bool flag1 = false;

	for (int i = 0; ((i<this->father->children.size()) && (flag1 == false)); i++)
	{
		if (value < this->father->children[i]->contect[0])
			{
				this->father->children.insert(this->father->children.begin() + i,brother);
				flag1 = true;
			}
	}

	if (flag1 == false)
			this->father->children.push_back(brother);

	
	this->father->contect.push_back(copyOfContect[1]);
	sort (this->father->contect.begin(),this->father->contect.end());

	if (this->contect[0] < brother->contect[0])
	{
	
		brother->insertChildren(leafValues[0]);
		brother->insertChildren(leafValues[1]);
		
		this->insertChildren(leafValues[2]);
		this->insertChildren(leafValues[3]);
		this->insertChildren(leafValues[4]);
	}
	else
	{
		this->insertChildren(leafValues[0]);
		this->insertChildren(leafValues[1]);
		
		brother->insertChildren(leafValues[2]);
		brother->insertChildren(leafValues[3]);
		brother->insertChildren(leafValues[4]);
	}
}
