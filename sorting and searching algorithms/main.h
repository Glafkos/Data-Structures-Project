#include <iostream>
#include <vector>
#include "QuickSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include <ctime>
#include "time.h"
#include <limits>
#include <stdlib.h>

using namespace std;

void print(vector <int> a, const int& N)
{
	for (int i = 0; i < N; i++)
		cout << "array[" << i << "] = " << a[i] << endl;
}

void QuickSortMain(vector <int> tableForSort)
{
	cout << "Size Of table: " << tableForSort.size() << endl << endl;

	int mesos_xronos_QS = 0;
    int counter_QS;

	vector <int> help_vector_QS;

	for (int i = 0; i < 5; i++)
	{
		help_vector_QS = tableForSort;
		counter_QS = 0;
       
		clock_t start = clock();

		quickSort(help_vector_QS, 0, (help_vector_QS.size() - 1), counter_QS);

		clock_t end = clock() - start;
    
       
		cout << "Number of comparisons for Quick Sort Algorithm = " << counter_QS << endl;

		cout.precision(numeric_limits<double>::digits10);
		cout << "Total time for Quick Sort Algorithm : " << fixed << (double) end / CLOCKS_PER_SEC \
			 << " seconds" << endl;
		cout <<"-----------------------------------------------------------"<<endl;
		
		mesos_xronos_QS = mesos_xronos_QS + end;
	}
	
	int printSelect;
	
	cout <<"-----------------------------------------------------------"<<endl;
	cout << "Mesos xronos 5 epanalipsewn gia Quick Sort = " << fixed << (double) mesos_xronos_QS/5 / CLOCKS_PER_SEC \
		 << " seconds" << endl;
    cout <<"-----------------------------------------------------------"<<endl;
	cout << "Arithmos sigkrisewn gia ton algorithmo Quick Sort = " << counter_QS << endl;
	cout <<"Insert 0 if you want to print sorting table anything else for continue:";
	
	cin >>printSelect;
	if (printSelect == 0)
		{
			print(help_vector_QS,help_vector_QS.size());
			system("pause");
		}

	cout <<endl;
}

void BubbleSortMain(vector <int> BubbleSortTable)
{
	cout << "Size Of table: " << BubbleSortTable.size() << endl << endl;

	long long int counter_BS;
	int mesos_xronos_BS = 0;
	
	vector <int> help_vector_BS; 
	
	for (int i = 0; i < 5; i++)
	{
		
		counter_BS = 0;
		
		help_vector_BS = BubbleSortTable;
		
		clock_t start = clock();

		BubbleSort(help_vector_BS,counter_BS);

		clock_t end = clock() - start;
		
		cout << "Number of comparisons for Bubble Sort Algorithm = " << counter_BS << endl;

		cout.precision(numeric_limits<double>::digits10);

		cout << "Total time for Bubble Sort Algorithm : " << fixed << (double) end  / CLOCKS_PER_SEC \
			<< " seconds" << endl;
		cout <<"-----------------------------------------------------------"<<endl;
		
		mesos_xronos_BS = mesos_xronos_BS + end;
	}

	int printSelect;

	cout <<"-----------------------------------------------------------"<<endl;
	cout << "Mesos xronos 5 epanalipsewn gia Bubble Sort = " << fixed << (double) mesos_xronos_BS/5 / CLOCKS_PER_SEC \
		 << " seconds" << endl;
	cout <<"-----------------------------------------------------------"<<endl;
	cout << "Arithmos sigkrisewn  gia ton algorithmo Bubble Sort = " << counter_BS << endl;

	cout <<"Insert 0 if you want to print sorting table anything else for continue:";
	cin >>printSelect;
	
	if (printSelect == 0)
		{
			print(help_vector_BS,help_vector_BS.size());
			system("pause");
		}
	cout <<endl;
}

void MergeSortMain(vector <int> MergeSortTable)
{
	cout << "Size Of table: " << MergeSortTable.size() << endl << endl;
	int mesos_xronos_MS = 0;
	int counter_MS;

	vector <int> help_vector_MS;

	for (int i = 0; i < 5; i++)
	{
		counter_MS = 0;

		help_vector_MS = MergeSortTable;

		clock_t start = clock();

		help_vector_MS = mergeSort(help_vector_MS,counter_MS);

		clock_t end = clock() - start;

		cout << "Number of comparisons for Merge Sort Algorithm = " << counter_MS << endl;

		cout.precision(numeric_limits<double>::digits10);
		
		cout << "Total time for Merge Sort Algorithm : " << fixed << (double) end / CLOCKS_PER_SEC \
		     << " seconds" << endl;
		cout <<"-----------------------------------------------------------"<<endl;
		
		mesos_xronos_MS = mesos_xronos_MS + end;
	}
	int printSelect;

	cout <<"-----------------------------------------------------------"<<endl;
	cout << "Mesos xronos 5 epanalipsewn gia Merge Sort = " << fixed << (double) mesos_xronos_MS/5  / CLOCKS_PER_SEC \
		<< " seconds" << endl;
	cout <<"-----------------------------------------------------------"<<endl;
	cout << "Mesos arithmos sigkrisewn 5 epanalipsewn gia ton algorithmo Merge Sort = " << counter_MS << endl;

	cout <<"Insert 0 if you want to print sorting table anything else for continue:";
	cin >>printSelect;
	
	if (printSelect == 0)
		{
			print(help_vector_MS,help_vector_MS.size());
			system("pause");
		}
	cout <<endl;
}

