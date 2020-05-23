#include "String.h"
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////
//this function will build the class using dynamic memory
/////////////////////////////////////////////////////////
void String :: initialize(char *temp)
{
	int size = 0;
	char *home = temp;
	
	while (*temp != '\0')
	{
		size++;
		temp++;
	}
	
	temp = home;
	buffer = new char[size + 1];
	home = buffer;
	wordLength = size;

	while (*temp != '\0')
	{
		*buffer = *temp;
		temp++;
		buffer++;
	}
	
	*buffer = '\0';	
	buffer = home;
}

////////////////////////////////////////////////////////////////
//this function will deallocate the memory set during initialize
////////////////////////////////////////////////////////////////
void String :: deallocate()
{
	delete [] buffer;
	buffer = NULL;
}

////////////////////////////////////////////////
//this function will copy on string into another
////////////////////////////////////////////////
void String :: copy(const String& sptr)
{
	char *home = buffer;
	char *temp = sptr.buffer;
	
	while (*buffer != '\0')
	{
		*temp = *buffer;
		buffer++;
		temp++;
	}
	
	temp = '\0';
	buffer = home;
}

////////////////////////////////////////////////
//this function will print out the string length
////////////////////////////////////////////////
int String :: length()
{
	int size = 0;
	char *home = buffer;
	
	while (*buffer != '\0')
	{
		size++;
		buffer++;
	}
	
	buffer = home;
	wordLength = size;
	cout << buffer << " has " << wordLength << " letters." << endl;
	
	return wordLength;
}

///////////////////////////////////////////////////
//this function will concat one string onto another
///////////////////////////////////////////////////
void String :: concat(const String& sptr)
{
	int lengthA, lengthB, total;
	char *home = buffer;
	char *tptr = sptr.buffer;
	
	lengthA = wordLength;
	lengthB = sptr.wordLength;
	total = lengthA + lengthB;

	char *temp = new char[total + 1];
	char *thome = temp;

	while (*buffer != '\0')
	{
		*temp = *buffer;
		buffer++;
		temp++;
	}
	
	while (*tptr != '\0')
	{
		*temp = *tptr;
		tptr++;
		temp++;
	}
	
	temp = '\0';
	temp = thome;

	buffer = home;
	delete [] buffer;
	buffer = new char[total + 1];
	home = buffer;
	
	while (*temp != '\0')
	{
		*buffer = *temp;
		temp++;
		buffer++;
	}
	
	buffer = '\0';
	buffer = home;
	temp = thome;
	delete [] temp;
}

//////////////////////////////////////////////////
//this function will compare one string to another
//////////////////////////////////////////////////
int String :: compare(const String& sptr)
{
	char *stringA = sptr.buffer;
	char *stringB = buffer;
	
	while (*stringA != '\0' && *stringB != '\0')
	{
		if (*stringA > *stringB)
		{
			return 1;
		}
	
		else if (stringA < stringB)
		{
			return 0;
		}
		
		else
		stringA++;
		stringB++;
	}
}

/////////////////////////////////////////////////
//this function will print out all of the strings
/////////////////////////////////////////////////
void String :: print()
{	
	cout << buffer << endl;
}
