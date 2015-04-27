#include <iostream>
#include <vector>
#include <string>
#include "Read_from_file.h"
#include "main.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "BinarySearch.h"
#include "BinaryInterpolationSearch.h"
#include <algorithm>
#include <stdlib.h>
#include <ctime>

using namespace std;

int myrandom (int i) { return std::rand()%i;}

int main()
{int choose;
    do{
	cout << "Choose Type Of Algorithm:" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
	cout << "1. Sorting Algorithm" << endl;
	cout << "2. Searching Algorithm" << endl;
	cout << "3. End the programme" <<endl<<endl;
	cout << "Insert Your Choose:";
	cin >> choose;
	cout << "-----------------" << endl;

	while (choose<1 || choose>3)
	{
		cout << "Your choose is incorect!! Please insert correct choose:";
		cin >> choose;
	}

	switch (choose)
	{
		case 1:
			{
				int secondChoose;
				cout << "Choose:" << endl;
				cout << "1. Select if you want sorted test data ( worst case )" << endl;
				cout << "2. Select if you want sorted data from file" << endl;
				cout << "Insert Your Choose:";
				cin >> secondChoose;
				cout << "-----------------" << endl;

			  while (secondChoose<1 || secondChoose>2)
			  {
				  cout << "Your choose is incorect!! Please insert correct choose:";
				  cin >> secondChoose;
			  }

			  switch (secondChoose)
				{
					int thirdChoose;

					case 1:
						{
						    int y;
                            vector <int> test;
                            cout << "Insert value to create vector for worst case input, size as the value:";
                            cin >> y;	//y o megaliteros arithmos sto vector pou tha dimiourgithi
										//xrimipiite gia na paroume metrisis xiristis periptwsis apo 1000 ews 10000 stixia
                            
							for (int i = y; i >0; i--)
                                test.push_back(i);

							cout << "Choose Sorting Algorithm to apply it to Test Data: " << endl;
							cout << "	1.QuickSort" << endl;
							cout << "	2.MergeSort" << endl;
							cout << "	3.BubbleSort" << endl;
							cout << "Insert Your Choose:";
							cin >> thirdChoose;

							while (thirdChoose<1 || thirdChoose>3)
							{
								cout << "Your choose is incorect!! Please insert correct choose:";
								cin >> thirdChoose;
							}

							switch (thirdChoose)
							{
								case 1:
									{
									    sort(test.begin(),test.end());

                                        cout << "Quick Sort Start : " << endl;
                                        cout << "-----------------" << endl;
                                        QuickSortMain(test);
                                        break;
									}
								case 2:
									{
										
                                        random_shuffle ( test.begin(), test.end() );

                                        random_shuffle ( test.begin(), test.end(), myrandom);

                                   
                                        cout << "Merge Sort Start : " << endl;
                                        cout << "-----------------" << endl;
                                        MergeSortMain(test);
                                        break;
									}
								case 3:
									{
                                        cout << "Bubble Sort Start : " << endl;
                                        cout << "-----------------" << endl;
                                        BubbleSortMain(test);
                                        break;
									}

							} // end of case for type sorted algorithm
							break;
						}//end of case 1 for test data

					case 2:
						{
							string nameOfFile;

							cout << "Insert file name for read content and sorting:";
							cin >> nameOfFile;

							vector <int> tableForSort;

							tableForSort = ReadFromFile(nameOfFile);
							
							if (tableForSort.size() == 0)
								break;
							
							cout << "Choose Sorting Algorithm to apply it to Table From File: " << endl;
							cout << "	1.QuickSort" << endl;
							cout << "	2.MergeSort" << endl;
							cout << "	3.BubbleSort" << endl;
							cout << "Insert Your Choose:";
							cin >> thirdChoose;
							cout << "-----------------" << endl;

							while (thirdChoose<1 || thirdChoose>3)
							{
								cout << "Your choose is incorect!! Please insert correct choose:";
								cin >> thirdChoose;
							}

							switch (thirdChoose)
							{

								case 1:
									{
										cout << "QuickSort Start : " << endl;
										cout << "-----------------" << endl;
										QuickSortMain(tableForSort);
										break;
									}
								case 2:
									{
										cout << "MergeSort Start : " << endl;
										cout << "-----------------" << endl;
										MergeSortMain(tableForSort);
										break;
									}
								case 3:
									{
										cout << "BubbleSort Start : " << endl;
										cout << "-----------------" << endl;
										BubbleSortMain(tableForSort);
										break;
									}
							}//end of case type of sorted algorithm to apply it to data from file
							break;
						}//end of case for data from file

				}//end of case second choose
				break;
			}//end of case for sorted algorithm

		case 2:
			{
			  int value = 0;
			  vector <int> table;
			  cout << "Insert values to create table which will be searched" << endl;
			  cout << "To stop entering numbers insert -1" << endl;
			  cout << "-----------------------------------------------------:" << endl;

			  while (value != -1)
			  {
				  cout << "Please insert value to create table : ";
				  cin >> value;
				  table.push_back(value);
			  }
              table.pop_back();     //delete -1 from vector

			  sort(table.begin(), table.end());

			  for (int i = 0; i < table.size(); i++)
				  cout << "table [" << i << "]" << table[i] << endl;

			  int x;

			  cout << "Enter the number you want to find :";
			  cin >> x;

			  /*Epilogi me pio algorithmo tha kani search ston pinaka pou edwse o xristis pio panw*/
			  int secondChoose;

			  cout << "Choose Searching Algorithm to apply it : " << endl;
			  cout << "	1.Binary Search" << endl;
			  cout << "	2.Binary Interpolation Search" << endl;

			  cin >> secondChoose;
			  cout << "--------------------" << endl;

			  while (secondChoose<1 || secondChoose>2)
			  {
				  cout << "Your choose is incorect!! Please insert correct choose:";
				  cin >> secondChoose;
			  }

			  switch (secondChoose)
				{
					case 1:
						{
							BinarySearch(table, x);
							system("pause");
							break;
						}

					case 2:
						{
							BinaryInterpolationSearch(table, x);
							system("pause");
							break;
						}
				}//end of switch for second choose
			}//end of switch for Search Algorithm
        }//end of switch for Sorting Or Searching Algorithm
 }while(choose !=3);
}//end main


