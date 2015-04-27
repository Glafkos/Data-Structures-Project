#include "BinaryInterpolationSearch.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <vector>

using namespace std;

void BinaryInterpolationSearch(vector <int> table,int x)
{
	int left = 0;
	int right = table.size() - 1;
	int size = right - left + 1;
	int counter_Interpolation = 0;

	float tnext = 0.0;

	tnext = ceil(size*(float) (x - table[left]) / (table[right] - table[left]));
	int next = (int) tnext;

	if (next >= size)
	{
		next = size - 1;
	}

	while (x != table[next])
	{
	    counter_Interpolation++;

		if ((right - left + 1) <= 3)
		{
			for (int i = left; i <= right; i++)
			{
				if (table[i] == x)
				{
					counter_Interpolation++;
					cout << "Congratulation!!  " << endl << "Number " << x <<" is at position: " << i << endl;
					cout <<"Counter for Binary Interpolation Search = " << counter_Interpolation <<endl;
					return;
				}
			}

			cout << "Number " << x <<" not found!" << endl;
			cout <<"Counter for Binary Interpolation Search = " << counter_Interpolation <<endl;
			return;
		}

		int i = 0;
		size = right - left + 1;

		if (x >= table[next])
		{

			while (x > table[next + i*int(sqrt(size)) - 1])
			{
				i++;
            }

			right = next + i*int(sqrt(size));
			left = next + (i - 1)* int(sqrt(size));

			if (right >= table.size())
			{
				right = table.size() - 1;
				left = right - int(sqrt(size));
			}
		}
		else if (x < table[next] && next != 0)
		{
			while (x < table[next - i*int(sqrt(size)) + 1])
			{
				i++;
			}

			right = next - (i - 1)*int(sqrt(size));
			left = next - i*int(sqrt(size));
		}

		if (table[right] - table[left] != 0)
		{
			tnext = ceil((float) ((right - left + 1) * (x - table[left]) / (table[right] - table[left])));
			next = left + (int) tnext - 1;
		}
	}


	if (x == table[next])
		cout << "Congratulation!!  " << endl << "Number " << x <<" is at position: " << next << endl;
	else
		cout << "Number " << x <<" not found! " << endl;
    cout <<"Counter for Binary Interpolation Search = " << counter_Interpolation <<endl;
	system("pause");
}
