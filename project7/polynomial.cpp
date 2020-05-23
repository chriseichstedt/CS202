#include "polynomial.h"
#include <iostream>
#include <fstream>
using namespace std;

//default constructor
polynomial :: polynomial()
{
	maxDegree = 3;
	coefficents = new int[maxDegree + 1];
	
	for(int i = 0; i < maxDegree + 1; i++)
	{
		coefficents[i] = 0;
	}
}

//parameterized constructor
polynomial :: polynomial(int degree, int *arrayPtr)
{
	maxDegree = degree;
	coefficents = new int[maxDegree + 1];
	
	for(int i = 0; i < degree; i++)
	{
		coefficents[i] = arrayPtr[i];
	}	
}

//copy constructor
polynomial :: polynomial(const polynomial &input)
{
	maxDegree = input.maxDegree;
	coefficents = new int[maxDegree + 1];
	
	for(int i = 0; i < maxDegree; i++)
	{
		coefficents[i] = input.maxDegree; //missing input.maxDegree[i]
	}
}

//destructor
polynomial :: ~polynomial()
{
	maxDegree = 0;
	delete[] coefficents;
	coefficents = NULL;
}

//evaluates the polynomial at an interger value and returns the result
int polynomial :: solve(int input)
{
	int total = 0;
	int value = 1;
	
	for(int i = 0; i < maxDegree + 1; i++)
	{
		for(int j = 0; j < maxDegree - i; j++)
		{
			value *= input;
		}
		
		total += (value * coefficents[i]);
		value = 1;
	}
		
	return total;
}

//copies one polynomial to another
polynomial polynomial :: operator =(polynomial &input)
{
	polynomial temp(maxDegree, coefficents);
	
	temp.maxDegree = input.maxDegree;
	temp.coefficents = new int[temp.maxDegree + 1];
	
	for(int i = 0; i < temp.maxDegree + 1; i++)
	{
		temp.coefficents[i] = input.coefficents[i];
	}
}

//returns true if two polynomials are equal
bool polynomial :: operator ==(polynomial &input)
{
	polynomial temp(maxDegree, coefficents);
	
	if(temp != input)
	{
			return false;
	}
	
	bool flag = false;
	
	for(int i = 0; i < input.maxDegree + 1; i++)
	{
		if(temp.coefficents[i]==input.coefficents[i])
		{
			flag = true;
		}
		
		else
		{
			flag = false;
			break;
		}
	}
	
	if (!flag)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

//returns true if two polynomials are not equal
bool polynomial :: operator !=(polynomial &input)
{
	polynomial temp(maxDegree, coefficents);
	
	if(temp != input)
	{
			return false;
	}
}

//multiplies two polynomial expressions and returns the sum into a new polynomial
polynomial polynomial :: operator *(polynomial &input)
{
	polynomial temp((maxDegree*input.maxDegree), coefficents);
	
	for(int i = 0; i < temp.maxDegree + 1; i++)
	{
		temp.coefficents[i] = (temp.coefficents[i]*input.coefficents[i]);
	}
	
	return temp;
}

//takes an interger parameter scalar and returns a new scaled polynomial
polynomial polynomial :: operator *(int input)
{
	polynomial temp(maxDegree, coefficents);
	
	for(int i = 0; i < temp.maxDegree + 1; i++)
	{
		temp.coefficents[i] = (temp.coefficents[i]*input);
	}
	
	return temp;
}

//takes two polynomials and adds their coefficents and returns a new polynomial of the sum
polynomial operator +(polynomial &input1, polynomial &input2)
{
	if(input1.maxDegree > input2.maxDegree)
	{
		polynomial temp(input1);
		int *tempPtr = temp.coefficents;
		
		for(int i = 0; i < (input1.maxDegree - input2.maxDegree); i++)
		{
			*tempPtr = 0;
			tempPtr++;
		}
		
		for(int i = 0; i < (input2.maxDegree +1); i++)
		{
			*tempPtr = input2.coefficents[i];
			tempPtr++;
		}
		
		for(int i = 0; i < input1.maxDegree + 1; i++)
		{
			temp.coefficents[i] += input1.coefficents[i];
		}
		
		return temp;
	}
		else
	{
		polynomial temp(input2);
		int *tempPtr = temp.coefficents;
		
		for(int i = 0; i < (input2.maxDegree - input1.maxDegree); i++)
		{
			*tempPtr = 0;
			tempPtr++;
		}
		
		for(int i = 0; i < (input1.maxDegree +1); i++)
		{
			*tempPtr = input1.coefficents[i];
			tempPtr++;
		}
		
		for(int i = 0; i < input2.maxDegree + 1; i++)
		{
			temp.coefficents[i] += input2.coefficents[i];
		}
		
		return temp;
	}
}

//takes two polynomials and subtracts their coefficents and returns a new polynomial of the difference
polynomial operator -(polynomial &input1, polynomial &input2)
{
	if(input1.maxDegree > input2.maxDegree)
	{
		polynomial temp(input1);
		int *tempPtr = temp.coefficents;
		
		for(int i = 0; i < (input1.maxDegree - input2.maxDegree); i++)
		{
			*tempPtr = 0;
			tempPtr++;
		}
		
		for(int i = 0; i < (input2.maxDegree +1); i++)
		{
			*tempPtr = input2.coefficents[i];
			tempPtr++;
		}
		
		for(int i = 0; i < input1.maxDegree + 1; i++)
		{
			temp.coefficents[i] -= input1.coefficents[i];
		}
		
		return temp;
	}
		else
	{
		polynomial temp(input2);
		int *tempPtr = temp.coefficents;
		
		for(int i = 0; i < (input2.maxDegree - input1.maxDegree); i++)
		{
			*tempPtr = 0;
			tempPtr++;
		}
		
		for(int i = 0; i < (input1.maxDegree +1); i++)
		{
			*tempPtr = input1.coefficents[i];
			tempPtr++;
		}
		
		for(int i = 0; i < input2.maxDegree + 1; i++)
		{
			temp.coefficents[i] -= input2.coefficents[i];
		}
		
		return temp;
	}
}

//outputs the polynomial to screen
ostream& operator <<(ostream& out, const polynomial &input)
{
	int counter = input.maxDegree;
	for(int i = 0; i < input.maxDegree + 1; i++)
	{
		if (input.coefficents[i] != 0 && counter > 0)
		{
			out << "(" << input.coefficents[i] << "x^" << counter << ") + "; 
		}
		else if (input.coefficents[i] !=0 && counter == 0)
		{
			out << input.coefficents[i];
		}

		counter--;
	}
	
	return out;
}

//reads the degree of the polynomial in from file
ifstream& operator >>(ifstream& fin, polynomial &input)
{	
	fin >> input.maxDegree;
	
	for(int i = 0; i < (input.maxDegree + 1); i++)
	{
		fin >> input.coefficents[i];
	}
	
	return fin;
}
