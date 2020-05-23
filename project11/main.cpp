#include "listarray.h"
#include "listnode.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int sortList(ListNode&, int);
void recursiveSort(int[], int); 
int nodeToArray(ListNode&, ListArray&, int);
int binarySearch(ListArray, int, int, int);
int fibonachi(const int);
void printMenu(int&);

int main()
{
	int selection;
	bool exitOut = false;
	
	do{
		printMenu(selection);
		switch (selection)
		{
			case 1:
			{
				char fileName[25];
				int fileSize;
				int temp;
				ifstream fin;
				
				cout << "enter a file name: ";
				cin >> fileName;
				cout << endl << endl;
				fin.open(fileName);
	
				fin >> fileSize;
				int start = 0;
				int end = fileSize;
				int searchValue;
				ListNode superSaiyans(fileSize);
				ListArray nameks(fileSize);
	
				for(int i = 0; i < fileSize; i++)
				{
					fin >> temp;
					superSaiyans.insertAfter(temp);
				}
	
				superSaiyans.goToBeginning();
				cout << "List Node before sort:" << endl;
				cout << superSaiyans << endl;
				cout << "---------------------" << endl;
	
				sortList(superSaiyans, fileSize);
				cout << "List Node after sort:" << endl;
				cout << superSaiyans << endl;
				cout << "---------------------" << endl;
	
				nodeToArray(superSaiyans, nameks, fileSize);
				cout << "List Array after List Node:" << endl;
				cout << nameks << endl;
				cout << "---------------------" << endl;
				
				cout << "enter a value to find within the List Array:";
				cin >> searchValue;
				cout << "---------------------" << endl;
				
				if (binarySearch(nameks, searchValue, start, end) == -1)
				{
					cout << "invalid selection, please try again" << endl;
				}
				
				else
				{
					cout << "selection is in element " << binarySearch(nameks, searchValue, start, end) + 1 << endl;
				}
				
				fin.close();
				superSaiyans.clear();
				nameks.clear();
				break;
			}
			case 2:
			{
				int input;
				
				cout << "enter a value: ";
				cin >> input;
				
				cout << "The fibonachi sequence for position " << input << " is " << fibonachi(input) << endl;
				break;
			}
			case 3:
			{
				exitOut = true;
				break;
			}
			default:
			{
				cout << "invalid input, try again." << endl;
				break;
			}
		}
	}while(!exitOut);
	
	return 0;
}

int sortList(ListNode &list, int size)
{
	list.goToBeginning();
	int temp[size];
	int temp2;

	for(int i = 0; i < size; i++)
	{
		list.get(temp2);
		temp[i] = temp2;
		list.goToNext();
	}
	
	list.goToBeginning();
	list.clear();
	
	recursiveSort(temp, size);
	
	for (int i = 0; i < size; i++)
	{
		list.insertAfter(temp[i]);
	}
	
	list.goToBeginning();
}

void recursiveSort (int array[], int size)
{
	int max = 0;
	int total = 0;
	int temp = 0;

	for(total = max; total < size; total++)
	{
		if (array[total] > array[max])
		{
			max = total;
		}
	}
	
	temp = array[size-1];
	array[size-1] = array[max];
	array[max] = temp;
	
	if(size > 1)
	{
		recursiveSort(array, --size);
	}
}

int nodeToArray(ListNode &list, ListArray &array, int size)
{
	int temp;
	for(int i = 0; i < size; i++)
	{
		list.get(temp);
		list.goToNext();
		array.insertAfter(temp);
	}
}


int binarySearch(ListArray list, int searchValue, int start, int end)
{
	if (end >= start)
	{
		int middle = (start + end)/2;
		int midpoint;
		list.goToBeginning();
		
		for(int i = 0; i < middle; i++)
		{
			list.goToNext();
		}
		
		list.get(midpoint);
		
		if (searchValue == midpoint)
		{
			return middle;
		}
		
		else if (searchValue < midpoint)
		{
			return binarySearch(list, searchValue, start, middle - 1);
		}
		
		else
		{
			return binarySearch(list, searchValue, middle + 1, end);
		}
	}
	
	else
	{
		return -1;
	}
}

int fibonachi(const int a)
{
	if(a < 2)
	{
		return 1;
	}
	
	else
	{
		return fibonachi(a-1) + fibonachi(a-2);
	}
}

void printMenu(int &selection)
{
	cout << endl << endl << "Project 11 Menu" << endl
	     << "--------------------" << endl
	     << "1. Binary Search" << endl
	     << "2. Fibonachi" << endl
	     << "3. Exit" << endl << endl;
	     
	cout << "Make a selection:";
	cin >> selection;
}
