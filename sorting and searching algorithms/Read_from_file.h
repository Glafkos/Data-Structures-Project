#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <math.h>

using namespace std;

vector <int> ReadFromFile(string filename)
{
	vector <int> table;
	string num;
	ifstream myfile(filename.c_str());

	if (myfile.is_open())
	{
		while (getline(myfile, num))
		{
			table.push_back(atoi(num.c_str()));
		}

		myfile.close();
		
		return table;
		table.clear();
	}

	else
	{
		cout << "Unable to open file\n " << endl;
		return table;
	}

}

