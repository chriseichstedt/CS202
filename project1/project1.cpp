/******************************/
//Christopher Eichstedt------>>
//CS202 - Spring 2016-------->>
//Project 1------------------>>
/******************************/

#include <iostream>
#include <fstream>

using namespace std;

/////////////////////////////////////////////////
//function declarations
/////////////////////////////////////////////////
void printOut(char name[10][20]);
void copyString(char a[], char b[]);
int compareString(char a[], char b[]);
void sortNames(char name[10][20]);

/////////////////////////////////////////////////
//the main function
/////////////////////////////////////////////////
int main()
{
	///////////////////////////////////
	//-----------variables---------->>
	///////////////////////////////////
	ifstream fin;
	ofstream fout;
	char name[10][20];
	char fileNameIn[100];
	char fileNameOut[100];
	
	///////////////////////////////////
	//------------input------------->>
	///////////////////////////////////
	cout << endl << "please enter the in-file name: ";
	cin >> fileNameIn;
	fin.open(fileNameIn);
	
	///////////////////////////////////
	//------print unsorted list----->>
	///////////////////////////////////
	cout << endl << "Unsorted:" << endl;
	cout << "===========" << endl;
	for (int i = 0; i < 10; i++)
	{
		fin >> name[i];
	}
	fin.close();
	printOut(name);	
	sortNames(name);
	
	///////////////////////////////////
	//------------output------------>>
	///////////////////////////////////
	cout << endl << "please enter the out-file name: ";
	cin >> fileNameOut;
	fout.open(fileNameOut);
	
	///////////////////////////////////
	//-------print sorted list------>>
	///////////////////////////////////
	cout << endl << "Sorted:" << endl;
	cout << "==========" << endl;
	for (int i = 0; i < 10; i++)
	{
		fout << name[i] << endl;
	}
	fout.close();
	printOut(name);

	return 0;
}

/////////////////////////////////////////////////
//this function will print out the character array
/////////////////////////////////////////////////
void printOut(char name[10][20])
{
	for (int i = 0; i < 10; i++)
	{
		cout << name[i] << endl;
	}
}

/////////////////////////////////////////////////
//this function will copy one character array to another
/////////////////////////////////////////////////
void copyString(char a[], char b[])
{
	int j;

	for(j = 0; a[j] != '\0'; j++)	
	{
		b[j] = a[j];
	}
	b[j] = '\0';
}

/////////////////////////////////////////////////
//this function will compare one character array to another
/////////////////////////////////////////////////
int compareString (char a[], char b[])
{
	int k = 0;
	
	while (a[k] != '\0' && b[k] != '\0')
	{
		if (b[k] > a[k])
		{
			return 1;
		} 
		else if (b[k] < a[k])
		{
			return -1;
		}
		else
		{
			k++;
		}
	}

	if (a[k] == '\0')
	{
		return 1;
	}
	return 0;
}

/////////////////////////////////////////////////
//this function will sort the character array
/////////////////////////////////////////////////
void sortNames(char name[10][20])
{
	int total = 0; 
	char temp[20];
	
	for (int l = 0; l < 10; l++)
	{
		for(int m = 0; m < 10; m++)
		{
			total = compareString(name[l], name[m]);

			if (total == 1)
			{
				copyString(name[l], temp);
				copyString(name[m], name[l]);
				copyString(temp, name[m]);
			}
		}
	}
}
