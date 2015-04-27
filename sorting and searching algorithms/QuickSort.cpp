#include <iostream>
#include "QuickSort.h"
#include <vector>
#include <stdlib.h>

using namespace std;

int  counter_QS = 0;

void quickSort(vector <int> &a, int first, int last,int &counter_QS )
{
	int x;

	x = pivot(a, first, last, counter_QS);

	if (first < x - 1)
	{
		quickSort(a, first, x - 1, counter_QS);
		counter_QS++;
	}
	if (x < last)
	{
		counter_QS++;
		quickSort(a, x, last, counter_QS);
	}

}

int pivot(vector <int> &a, int first, int last,int &counter_QS)
{
		int S = a[first];
		int i = first;
		int k = last ;

		while (i <= k)
		{
			counter_QS++;

			while (a[i] < S)
			{
				counter_QS++;
				i++;
			}

			while (a[k] > S)
			{
				counter_QS++;
				k--;
			}

			if (i <= k)
			{
				swap(a[i], a[k]);
				k--;
				i++;
			}
		}
		return i;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}




