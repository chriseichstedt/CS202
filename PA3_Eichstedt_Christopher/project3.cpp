/**********************
*Christopher Eichstedt*
**CS202 - Spring 2016**
******Project 3********
**********************/

/***libraries included***/
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

/***global variables***/
struct vehicles
{
	int year;
	char make[20];
	char model[20];
	float price;
	bool available;
};

struct company
{
	char name[10];
	int zipcode[5];
	vehicles inventory[5];
};

/***function declararions***/
void printMenu(int&);
void readFile(company*);
void printInventory(company*);
void estimateCarRental(company*);
void expensiveCarRental(company*);
void printAvailable(company*);

/***main function***/
int main()
{
	int select;
	bool exitProgram = false;

	vehicles rental[10];
	company service[3];

	company *compPtr = service;

	do{
		printMenu(select);
		switch (select)
		{
			case 1:
				readFile(compPtr);
				break;			
			case 2:
				printInventory(compPtr);
				break;
			case 3:
				estimateCarRental(compPtr);
				break;
			case 4:
				expensiveCarRental(compPtr);
				break;
			case 5:
				printAvailable(compPtr);
				break;
			case 6:
				exitProgram = true;
				break;
			default:
				cout << "Incorrect selection, please try again!" << endl;
				break;
		}
	}while (!exitProgram);	

	return 0;
}

/***secondary functions***/

/***this function will print a menu at the program start***/
void printMenu(int& select)
{
	cout << endl << "Rent-a-car" << endl
	     << "==========" << endl
	     << "1. Read data from file" << endl
	     << "2. Print out all cars" << endl
	     << "3. Estimate car rental" << endl
	     << "4. Find most expensive car rental" << endl
	     << "5. Print out avaialble cars" << endl
	     << "6. Exit" << endl << endl;

	cout << "Enter a choice: ";
	cin >> select;
}

/***the function that will read in a file and add it to the structs***/
void readFile(company *cPtr)
{
	char fileName[20];
	int *zPtr = (*cPtr).zipcode;
	char buffer[20];
	vehicles* iPtr = (*cPtr).inventory;	
	ifstream fin;
	
	cout << endl << "Please enter a file name: ";
	cin >> fileName;
	fin.open(fileName);

	for (int a = 0; a < 3; a++)
	{
		fin >> (*cPtr).name;
		fin >> buffer;

		for(int c = 0; c < 5; c++)
		{
			*zPtr = atoi(buffer);
			zPtr++;
		}
		

		for (int b = 0; b < 5; b++)
		{
			fin >> (*iPtr).year 
			    >> (*iPtr).make 
			    >> (*iPtr).model 
			    >> (*iPtr).price 
			    >> (*iPtr).available;
			iPtr++;
		}
		cPtr++;
		zPtr = (*cPtr).zipcode;
		iPtr = (*cPtr).inventory;
	}
}

/***the function that will print out the information within the structs***/
void printInventory(company *cPtr)
{
	int *zPtr = (*cPtr).zipcode;
	vehicles *iPtr = (*cPtr).inventory;	
	
	for (int a = 0; a < 3; a++)
	{
		cout << endl << (*cPtr).name << " ";
		cout << *zPtr << endl;

		for (int b = 0; b < 5; b++)
		{
			cout << (*iPtr).year << " " 
			     << (*iPtr).make << " "
			     << (*iPtr).model << " "
			     << (*iPtr).price << " ";
			if ((*iPtr).available == 1)
			{
				cout << "available" << endl;			
			}
			else
			{
				cout << "unavailable" << endl;
			}
			iPtr++;
		}
		cPtr++;
		zPtr = (*cPtr).zipcode;
		iPtr = (*cPtr).inventory;
	}
}
/***the function for taking in information to find an estimated price***/
void estimateCarRental(company *cPtr)
{
	int selectCompany, selectCar, days;
	float cost;
	company *aPtr = cPtr;
	vehicles (*bPtr) = (*cPtr).inventory;
	
	cout << endl;

	for (int a = 0; a < 3; a++)
	{
		cout << a + 1<< ") " << (*cPtr).name << endl;
		cPtr++;
	}

	cout << endl << "Enter a rental company number: ";
	cin >> selectCompany;
	cout << endl;

	if (selectCompany = 1)
	{
		cPtr = aPtr;
	}
	else if (selectCompany = 2)
	{
		cPtr = aPtr + 1;
	}
	else if (selectCompany = 3)
	{
		cPtr = aPtr + 2;
	}
	else
	{
		cout << "Incorrect Input, please try again.";
	}

			for (int b = 0; b < 5; b++)
			{
				cout << b+1 << ") " 
				     << (*bPtr).year << " " 
		     		     << (*bPtr).make << " " 
		     		     << (*bPtr).model << " " 
		     		     << (*bPtr).price << " " 
				     << endl;
				bPtr++;
			}
			
			cout << endl << "Enter a vehicle number: ";
			cin >> selectCar;
			cout << endl;
			cPtr = aPtr;
			bPtr = (*cPtr).inventory;
		
			switch (selectCar)
			{
				case 1:
					cout << "Enter how many days would you like to rent for: ";
					cin >> days;
					cout << endl;
					cost = (days * (*bPtr).price);
					
					cout << "The total to rent a " 
					     << (*bPtr).year << " "
					     << (*bPtr).make << " "
					     << (*bPtr).model << " "
					     << "for " << days
					     << " day(s), is $" << cost << endl;
					break;
				case 2:
					bPtr = bPtr + 1;					

					cout << "Enter how many days would you like to rent for: ";
					cin >> days;
					cout << endl;
					cost = (days * (*bPtr).price);
					
					cout << "The total to rent a " 
					     << (*bPtr).year << " "
					     << (*bPtr).make << " "
					     << (*bPtr).model << " "
					     << "for " << days
					     << " day(s), is $" << cost << endl;
					break;
				case 3:
					bPtr = bPtr + 2;

					cout << "Enter how many days would you like to rent for: ";
					cin >> days;
					cout << endl;
					cost = (days * (*bPtr).price);
					
					cout << "The total to rent a " 
					     << (*bPtr).year << " "
					     << (*bPtr).make << " "
					     << (*bPtr).model << " "
					     << "for " << days
					     << " day(s), is $" << cost << endl;
					break;
				case 4:
					bPtr = bPtr + 3;

					cout << "Enter how many days would you like to rent for: ";
					cin >> days;
					cout << endl;
					cost = (days * (*bPtr).price);
					
					cout << "The total to rent a " 
					     << (*bPtr).year << " "
					     << (*bPtr).make << " "
					     << (*bPtr).model << " "
					     << "for " << days
					     << " day(s), is $" << cost << endl;
					break;
				case 5:
					bPtr = bPtr + 4;

					cout << "Enter how many days would you like to rent for: ";
					cin >> days;
					cout << endl;
					cost = (days * (*bPtr).price);
					
					cout << "The total to rent a " 
					     << (*bPtr).year << " "
					     << (*bPtr).make << " "
					     << (*bPtr).model << " "
					     << "for " << days
					     << " day(s), is $" << cost << endl;
					break;
				default:
					cout << "Incorrect selection, please try again." << endl;
					break;
			}
}

/***the function that will find the most expensive car***/
void expensiveCarRental(company *cPtr)
{
	company *aPtr = cPtr;
	vehicles *vTempPtr = (*cPtr).inventory;
	vehicles *original = vTempPtr;
	vehicles *temp;
	vTempPtr++;

	cout << endl;

	for (int a = 0; a < 3; a++)
	{
		if((*vTempPtr).price > (*original).price)
		{
			temp = vTempPtr;
		}
		else if((*vTempPtr).price < (*original).price)
		{
			temp = original;
		}
		else
		{
			temp = vTempPtr;
		}
		
		cout << (*aPtr).name << " "
		     << (*temp).year << " " 
		     << (*temp).make <<  " " 
		     << (*temp).model << " " << endl;
			aPtr++;
			vTempPtr++;
			original++;
	}
}

/***the function that will print only the available rentals***/
void printAvailable(company *cPtr)
{
	int *zPtr = (*cPtr).zipcode;
	vehicles *iPtr = (*cPtr).inventory;

	cout << endl << "Here are the only available cars:" << endl;

	for (int a = 0; a < 3; a++)
	{
		cout << endl << (*cPtr).name << " ";
		cout << *zPtr << endl;

		for (int b = 0; b < 5; b++)
		{
			if ((*iPtr).available == 1)
			{
				cout << (*iPtr).year << " " << (*iPtr).make << " " << (*iPtr).model << endl;
			}
			iPtr++;
		}
		cPtr++;
		iPtr = (*cPtr).inventory;
	}
}
