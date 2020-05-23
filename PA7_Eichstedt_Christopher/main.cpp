#include "polynomial.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	polynomial poly1;
	polynomial poly2;
	polynomial poly3;
	
	ifstream fin;
	fin.open("data");
	
	fin >> poly1;
	fin >> poly2;
	fin >> poly3;
	
	cout << "polynomial A:" << poly1 << endl;
	cout << "polynomial B:" << poly2 << endl;
	cout << "polynomial C:" << poly3 << endl;
	
	cout << "----------------------" << endl;
	
	//polynomial addition
	cout << "polynomial A + polynomial B = " << (poly1+poly2) << endl;
	cout << "polynomial B + polynomial C = " << (poly2+poly3) << endl;
	cout << "polynomial C + polynomial A = " << (poly3+poly1) << endl;
	
	cout << "----------------------" << endl;
	
	//polynomial subtraction
	cout << "polynomial A - polynomial B = " << (poly1-poly2) << endl;
	cout << "polynomial B - polynomial C = " << (poly2-poly3) << endl;
	cout << "polynomial C - polynomial A = " << (poly3-poly1) << endl;
	
	cout << "----------------------" << endl;
	
	//polynomial multiplication
	cout << "polynomial A * polynomial B = " << (poly1*poly2) << endl;
	cout << "polynomial B * polynomial C = " << (poly2*poly3) << endl;
	cout << "polynomial C * polynomial A = " << (poly3*poly1) << endl;
	
	/*
	//polynomial equality
	if (poly1==poly2)
	{
		cout << "polynomial A and B are equal" << endl;
	}
	else if (poly1!=poly2)
	{
		cout << "polynomial A and B aren't equal" << endl;
	}
	
	if (poly2==poly3)
	{
		cout << "polynomial B and C are equal" << endl;
	}
	else if (poly2!=poly3)
	{
		cout << "polynomial B and C aren't equal" << endl;
	}
	
	if (poly3==poly1)
	{
		cout << "polynomial C and A are equal" << endl;
	}
	else if (poly3!=poly1)
	{
		cout << "polynomial C and A aren't equal" << endl;
	}

*/ 
	return 0;
}
