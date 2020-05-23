#include "String.h"

using namespace std;

//string copy
void strCopy(char *destination, char *source)
{
	while(*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	
	*destination = '\0';
}

//string compare
bool strCompare(char *stringA, char *stringB)
{
	while (*stringA != '\0' && *stringB != '\0')
	{
		if (*stringA > *stringB)
		{
			return 1;
		}
	
		else if (*stringA < *stringB)
		{
			return 0;
		}
		
	}
}
