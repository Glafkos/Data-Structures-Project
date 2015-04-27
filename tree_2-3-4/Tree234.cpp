#include "Node.h"
#include "Tree234.h"
#include <iostream>


Tree234::Tree234(int value)
{
	root = new Node (NULL, value);
	root->insertChildren (value);
	root->contect.push_back(value);
}

void Tree234 :: insert(int value)
{
	Node *newdad = findNode(value,root);
	newdad->insertChildren(value);
}

Node* Tree234 :: findNode(int value, Node* root)
{
	if (root->children[0]->isLeave())
		return root;

	for (int i = 0; i < root->contect.size(); i++)
		if (value < root->contect[i])
			return findNode(value,root->children[i]);

	return findNode(value,root->children[root->children.size()-1]);
}

void Tree234 :: print()
{
	print_help(root);
}

void Tree234 :: print_help (Node* x)
{
	if (x->isRoot())
	{
		cout <<"Root :";
	}
	for (vector<int>::iterator it = x->contect.begin() ; it != x->contect.end(); ++it)
	{
		cout << ' ' << *it;
			
	}
	cout <<endl;

	for (int i=0; i<x->children.size(); i++)
	{
		if (x->children[i]->isLeave())
		{
			cout <<"Leave [ " << i<<" ] = ";
			print_help(x->children[i]);

		}
		else
		{
			cout <<"------------"<<endl;
			cout<<"			Child [ " << i <<" ] =";
			print_help(x->children[i]);
		}
	}
	
}

int Tree234 :: numberOfNodes()
{
	return numberOfNodes(root);
}

int  Tree234 :: numberOfNodes(Node *root)
{
	int counter = 1;
	for (int i=0; i < root->children.size(); i++)
	{
		counter += numberOfNodes(root->children[i]);
	}
	return counter;
}

bool Tree234 :: Empty()
	{
		return(root = nullptr);
	}

bool Tree234 :: Contains(int x, Node* temp)
    {
		if (temp->isLeave())
		{
			return (temp->contect[0] == x);
		}
		else
		{
			int i;

			for (i = 0; i < temp->contect.size(); i++)
			{
				if (x <= temp->contect[i])
					return Contains(x, temp->children[i]);
			}

			if (x > temp->contect[temp->contect.size() - 1])
				return Contains(x, temp->children[temp->children.size() - 1]);
			else
				return false;

		}
	}

vector <int> Array;

vector <int> Tree234 :: toIntArray(Node*x)
    {

		if (x->isLeave())
		{
		for (vector<int>::iterator it = x->contect.begin() ; it != x->contect.end(); ++it)
		{
			Array.push_back(*it);
		}
		}
	
		for (int i=0; i < x->children.size(); i++)
		{
			if (x->children[i]->isLeave())
			{
				toIntArray(x->children[i]);	
			}
			else
			{
				toIntArray(x->children[i]);
			}
		}

	return Array;
}

void Tree234:: delete_value (int value)
{
	 if(root->children.size() == 1)
        {
			root->contect.clear();
			root->contect.push_back(0);
			root->children.clear();
		}
		
        else
        {
            Node *temp = findNode(value, root);
                        
			for(int i=0; i<temp->children.size(); i++) 
            {   
				if(value == temp->children[i]->contect[0])
                {
					temp->children.erase(temp->children.begin()+i);

                    temp->contect.clear();
					int j = 0;
					
					while (j<temp->children.size()-1)
					{
						temp->contect.push_back(temp->children[j]->contect[0]);
						j++;
					}
	
                  }
              }
           
         }
}
