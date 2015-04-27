#include <iostream>
#include <vector>
#include "BinarySearch.h"
#include <stdlib.h>
using namespace std;

void BinarySearch(vector <int> a, int x)
{
    int counter_BinarySearch = 0;
	int left = 0;
	int right = a.size()-1;
	int next = (right+left)/2;

	while ((x != a[next]) && (left < right))
	{
		if (x <= a[next])
        {
            counter_BinarySearch++;
			right = next - 1;
        }
		else
        {
            counter_BinarySearch++;
			left = next + 1;
        }

		next = (right + left) / 2;
	}

	if (x == a[next])
		{
			counter_BinarySearch++;
			cout << "Congratulation!!  " << endl << "Number " << x <<" is at position: " << next << endl;	
		}
	else	
		{
			counter_BinarySearch++;
			cout << "The Number " << x <<" not found! " << endl;
		}

	cout <<"Counter Binary Search = " <<counter_BinarySearch<<endl;
}
