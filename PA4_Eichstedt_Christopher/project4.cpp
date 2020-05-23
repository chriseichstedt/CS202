///////////////////////
//Christopher Eichstedt
//CS202, Spring 2016
//Project 4
///////////////////////

////////////////////
//library inclusions
////////////////////
#include <iostream>
#include <fstream>

using namespace std;

////////////////
//global struct
////////////////
struct pieces
{
	char *word;
	int jump;
};
////////////////////////
//function declarations
///////////////////////
void strCopy(char*, char*);
int strLen(char*);
char* strConcat(char*, char*);

//***********************************************************************************************//

////////////////////
//the main function
////////////////////
int main()
{	
	///////////////////
	//initialize values
	///////////////////	
	int size, keys, length;
	char *fileName = new char[20];
	ifstream fin;

	cout << "enter a file name: ";
	cin >> fileName;

	fin.open(fileName);


	//////////////////////////////////////////////////
	//read in file information and create DMA pointers
	//////////////////////////////////////////////////
	fin >> size;
	fin >> keys;

	pieces *pPtr = new pieces[size];
	pieces *homePtr = pPtr;

	for (int i = 0; i < size; i++)
	{
		char *temp = new char[20];

		fin >> temp;
		fin >> (*pPtr).jump;
		(*pPtr).word = new char[strLen(temp)];
		strCopy((*pPtr).word, temp); 

		delete [] temp;

		pPtr++;
	}

	pPtr = homePtr;

	int *oPtr = new int[keys];
	int *originPtr = oPtr;

	for (int i = 0; i < keys; i++)
	{
		fin >> *oPtr;
		oPtr++;
	}
	
	oPtr = originPtr;

	fin.close();

	/////////////////////////
	//deciphering the message
	/////////////////////////
	int counter = 0, jumpValue;
	char *message = new char[100];
	
	for (int i = 0; i < keys; i++)
	{
		for (int i = 0; i < *oPtr; i++)
		{
			counter++;
			pPtr++;

			if (counter == size)
			{
				pPtr = homePtr;
				counter = 0;		
			}
		}

		jumpValue = (*pPtr).jump;
		
		while (jumpValue != 0)
		{
			for (int i = 0; i < jumpValue; i++)
			{
				counter++;
				pPtr++;

				if (counter == size)
				{
					pPtr = homePtr;
					counter = 0;		
				}
			}
			
			jumpValue = (*pPtr).jump;
		}	
	
		//strConcat(message, (*pPtr).word);

		cout << (*pPtr).word << " ";

		counter = 0;
		pPtr = homePtr;
		oPtr++;
	}
	
	cout << endl;

//	cout << message << endl;
	
	////////////////////////////////////////
	//deallocating memory
	////////////////////////////////////////

	for (int i = 0; i < size; i++)
	{
		delete [] (*pPtr).word;
		pPtr++;
	}

	pPtr = homePtr;
	oPtr = originPtr;

	delete [] pPtr;
	delete [] oPtr;
	delete [] fileName;
	delete [] message;

	pPtr = NULL;
	homePtr = NULL;
	oPtr = NULL; 
	originPtr = NULL;
	fileName = NULL;
	message = NULL;

	return 0;
}

//***********************************************************************************************//

/////////////////////////////////////////////////
//this function will copy one character array to another
/////////////////////////////////////////////////
void strCopy(char *destination, char *source)
{
	while (*source != '\0')
	{
		*destination = *source;
	
		source++;
		destination++;
	}
	*destination = '\0';
}

///////////////////////////////////////////
//this function will count a string length
///////////////////////////////////////////
int strLen(char *source)
{
	int count = 0;

	while (*source != '\0')
	{
		count++;
		source++;
	}
	
	return count;
}

///////////////////////////////////////////////////////////////
//this function will put a string at the end of another string
///////////////////////////////////////////////////////////////
char* strConcat(char *destination, char *source)
{
	int destinationLength, sourceLength, totalLength;

	destinationLength = strLen(destination);
	sourceLength = strLen(source);
	totalLength = destinationLength + sourceLength;

	char *amendedWord = new char[totalLength];

	for(int i = 0; i < destinationLength; i++)
	{
		amendedWord = destination;
		destination++;
	}

	for (int i = 0; i < sourceLength; i++)
	{
		amendedWord = source;
		source++;
	}	

	amendedWord[totalLength] = '\0';

	return amendedWord;
		
	delete [] amendedWord;
}
