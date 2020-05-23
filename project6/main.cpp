/////////////////////////////
//Christopher Eichstedt    //
//Project 6                //
//CS202 - Spring 2016      //
/////////////////////////////

#include "Agency.h"
#include <iostream>

using namespace std;

void printMenu(int &);

int main()
{
	char *fileName = new char[20];
	char *carSearch = new char[20];
	int carSelect, daysRented;
	int selection;
	Agency temp;
	bool finished = false;
	
	do{
		printMenu(selection);
		
		switch (selection)
		{	
			case 1:
				cout << "Enter a file name: ";
				cin >> fileName;
				temp.readInData(fileName);
				cout <<"--------------" << endl;
				break;
			case 2:
				temp.print();
				cout <<"--------------" << endl;
				break;
			case 3:
				temp.printAvailableCars();
				cout <<"--------------" << endl;
				break;
			case 4:
				temp.findMostExpensive();
				cout <<"--------------" << endl;
				break;
			case 5:
				temp.print();
				cout <<"--------------" << endl;
				cout << "Enter a car number: ";
				cin >> carSelect;
				
				cout << "Enter the amount of days: ";
				cin >> daysRented;
				
				temp.estimateCost(carSelect, daysRented);
				cout <<"--------------" << endl;
				break;
			case 6:
				temp.sortByMake();
				cout <<"--------------" << endl;
				break;
			case 7:
				temp.sortByPrice();
				cout <<"--------------" << endl;
				break;
			case 8:
				cout << "Enter the make of a vehicle: ";
				cin >> carSearch;
				temp.searchByMake(carSearch);
				cout <<"--------------" << endl;
				break;
			case 9:
				delete[] fileName;
				delete[] carSearch;
				fileName = NULL;
				carSearch = NULL;
				finished = true;
				break;
		}
	}while(!finished);
	
	return 0;
}

void printMenu(int &selection)
{
	cout	<< "Project 6 Menu" << endl
		<< "--------------" << endl
		<< "1.) Read in File" << endl
		<< "2.) Print Inventory" << endl
		<< "3.) Print Available Cars" << endl
		<< "4.) Find Most Expensive Car" << endl
		<< "5.) Estimate Cost" << endl
		<< "6.) Sort by Make" << endl
		<< "7.) Sort by Price" << endl
		<< "8.) Search by Make" << endl
		<< "9.) Exit" << endl;
	
	cout <<"--------------" << endl;
	cout << "Make a selection: ";	
	cin >> selection;
	cout <<"--------------" << endl;
}
