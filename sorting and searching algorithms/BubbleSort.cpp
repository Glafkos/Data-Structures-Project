#include <iostream>
#include <vector>
#include "BubbleSort.h"
#include <stdlib.h>

using namespace std;

void BubbleSort(vector <int> &a,long long int& counter_BS)
{
	int s;
	s = a.size();

	while (s > 1)
	{
		int j;

		j = 0;

		for (int i = 0; i < s - 1; i++)
		{

			if (a[i] > a[i + 1])
			{
				counter_BS++;
				swapBubbleSort(a[i], a[i + 1]);
				j++;
			}
		}
		if (j == 0)
			return;
		s--;
	}
}
void swapBubbleSort(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
