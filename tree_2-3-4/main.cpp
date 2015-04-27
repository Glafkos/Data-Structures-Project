#include "Tree234.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main()
{ 
	int x;
	cout <<"Please insert value to create tree: "<<endl;
	cin >> x;
	Tree234 tree = Tree234 (x);
	
	int choose;
	int value;
	bool y;
	vector <int> Array;
	do
		{ 
			cout<<"\n\n1)Insert\n2)Number Of Nodes\n3)Contains\n4)Delete\n5)toIntArray\n6)Print\n7)Quit"; 
			cout<<"\nEnter your choice : "; 
			cin>>choose; 
		
			switch(choose) 
				{ 
					case 1: 
						{
							cout<<"\nEnter a data : "; 
							cin >> value; 
							tree.insert(value); 
							cout<<"\nTree after insertion : "; 
							tree.print(); 
							break;
						}
					case 2:
						{
							cout << "Number Of Nodes = " << tree.numberOfNodes() << endl;
							break;
						}
					case 3:
						{
							int p;
							cout<<"\nEnter a data : "; 
							cin >> p; 
							y = tree.Contains(p,tree.root);
							if (y==0)
								cout << "False" <<endl;
							else
								cout <<"True" <<endl;
							break;
						}
					case 4:
						{
							int x = tree.numberOfNodes();
							cout<<"\nEnter a data : "; 
							cin >> value; 
							tree.delete_value(value); 
							if (tree.numberOfNodes() == x)
							{
								cout <<"I timi pou epilexate gia diagrafi den iparxi sto dentro!!"<<endl;
								break;
							}
							cout<<"\nTree after delete : "; 
							tree.print(); 
							break;
						}
					case 5:
						{
							cout <<"----------"<<endl;
							Array = tree.toIntArray(tree.root);
							for (int i = 0; i< Array.size(); i++)
							cout <<"Value [ " << i <<" ] = " << Array[i] <<endl;
							break;
						}
					case 6:
						{
							tree.print();
						}						
		}
		}while(choose!=7); 
    	
}

	
	