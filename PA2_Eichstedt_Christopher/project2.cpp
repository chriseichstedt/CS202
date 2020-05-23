/************************
* Christopher Eichstedt *
*  CS202 - Spring 2016  *
*	Project 2       *
************************/

//////////////////////////////////////////////////////////////////////////
//library inclusion
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////////////////
//global variables
//////////////////////////////////////////////////////////////////////////
struct vehicles
{
	int year;
	char make[20];
	char model[20];
	float price;
	bool available;
};

//////////////////////////////////////////////////////////////////////////
//secondary function declarations
//////////////////////////////////////////////////////////////////////////
void printMenu(int&);
void readFile(vehicles rental[]);
void printAll(vehicles rental[]);
void estimateCarRental(vehicles rental[]);
void findExpensiveCar(vehicles rental[]);
void printAvailable(vehicles rental[]);

//--------------------------------------------->>

//////////////////////////////////////////////////////////////////////////
//the main function
//////////////////////////////////////////////////////////////////////////

//--------------------------------------------->>

int main()
{
	///////////////////////////
	//variables------------->>
	///////////////////////////
	int select;
	bool exitOut = false;
	vehicles rental[10];		

	//////////////////////////
	//do-while loop & selection
	//////////////////////////
	do{
		printMenu(select);
		switch (select)
		{
			case 1:
				readFile(rental);
				break;
			case 2:
				printAll(rental);
				break;
			case 3:
				estimateCarRental(rental);
				break;
			case 4:
				findExpensiveCar(rental);
				break;
			case 5:
				printAvailable(rental);
				break;
			case 6:
				exitOut = true;
				break;
			default:
				cout << "Incorrect selection, please try again." << endl;
				break;
		}
	}while(!exitOut);
}

//--------------------------------------------->>

//////////////////////////////////////////////////////////////////////////
//the secondary functions
//////////////////////////////////////////////////////////////////////////

//--------------------------------------------->>

//////////////////////////////////////////////////////////////////////////
//this function will print out the main menu
//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
//this function reads in the user defined file
//////////////////////////////////////////////////////////////////////////
void readFile(vehicles rental[])
{
	char fileName[20];
	ifstream fin;

	cout << "Please enter a filename: ";
	cin >> fileName;
	fin.open(fileName);

	for (int i = 0; i < 10; i++)
	{
		fin >> rental[i].year >> rental[i].make >> rental[i].model >> rental[i].price >> rental[i].available;
	}
	

}

//////////////////////////////////////////////////////////////////////////
//this function prints out all of the data from the file
//////////////////////////////////////////////////////////////////////////
void printAll(vehicles rental[])
{
	cout << endl;

	for(int i = 0; i < 10; i++)
	{
		int j = i +1;

		cout << "#" << j << " " << rental[i].year << " "
		     << rental[i].make << " "
                     << rental[i].model << ", " 
                     << "$" << rental[i].price << " a day, currently ";

		if (rental[i].available == 1)
		{
			cout << "available" << endl;			
		}
		else
		{
			cout << "unavailable" << endl;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//this function estimates a car rental using the given information
//////////////////////////////////////////////////////////////////////////
void estimateCarRental(vehicles rental[])
{
	int carPick = 0;	
	int days = 0;
	
	cout << endl;

	for(int i = 0; i < 10; i++)
	{
		int j = i +1;

		cout << "#" << j << " " << rental[i].year << " "
		     << rental[i].make << " "
                     << rental[i].model << ", " 
                     << "$" << rental[i].price << " a day, currently ";

		if (rental[i].available == 1)
		{
			cout << "available" << endl;			
		}
		else
		{
			cout << "unavailable" << endl;
		}
	}

	cout << endl;

	cout << "Please enter the number for the rental you want to estimate: ";
	cin >> carPick;

	cout << "How many days would you like to rent: ";
	cin >> days;
		
	cout << endl << "The total price is $" << (rental[carPick-1].price * days) << " " << "to rent the " << rental[carPick-1].year << " " << rental[carPick-1].make << " " << rental[carPick-1].model << " for " << days << " day(s)." << endl;
}

//////////////////////////////////////////////////////////////////////////
//this function compares all of the data to find the most expensive rental car
//////////////////////////////////////////////////////////////////////////
void findExpensiveCar(vehicles rental[])
{
	int expensive = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i +1; j < 10; j++)
		{
			if (rental[i].price < rental[j].price && rental[expensive].price < rental[j].price)
			{
				expensive = i;
			}
			else if (rental[j].price < rental[i].price && rental[expensive].price < rental[i].price)
			{
				expensive = j;
			}
		}
	}

	cout << endl << "The most expensive car is the " << rental[expensive].year << " " << rental[expensive].make << " " << rental[expensive].model << " at $" << rental[expensive].price << " a day." << endl;
}

//////////////////////////////////////////////////////////////////////////
//this function will sort all of the data to find which ones are available
//////////////////////////////////////////////////////////////////////////
void printAvailable(vehicles rental[])
{
	cout << endl << "Here are the only available cars:" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (rental[i].available == 1)
		{
			cout << rental[i].year << " " << rental[i].make << " " << rental[i].model << " $" << rental[i].price << endl;
		}
	}
}
