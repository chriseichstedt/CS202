///////////////////////
//Christopher Eichstedt
//CS202, Spring 2016
//Project 5
//"test driver"
///////////////////////

#include "String.h"
#include <iostream>
#include <fstream>

using namespace std;

void printMenu(int&);

///////////////////////////////////////////////////////////////////
//this is the main function that will read in the first two strings
///////////////////////////////////////////////////////////////////
int main()
{
	int selection, copySelect;
	bool exitOut = false;
	char *fileName = new char[20];
	char *temp = new char[20];
	String *sptr = new String[2];
	String *homeptr = sptr;
	String *copyptr = sptr;
	ifstream fin;
	
	do{
		printMenu(selection);
		
		switch (selection)
		{
			case 1:
				cout << "please enter a file name: ";
				cin >> fileName;
				fin.open(fileName);
				break;
			case 2:
				for (int i = 0; i < 2; i++)
				{
					fin >> temp;
					(*sptr).initialize(temp);
					sptr++;
				}
			
				sptr = homeptr;
				break;
			case 3:
				cout	<< "How would you like to proceed?" << endl
					<< "==============================" << endl
					<< "1.) copy String A into String B" << endl
					<< "2.) copy String B into String A" << endl;
					
				cin >> copySelect;
			
				switch (copySelect)
				{
					case 1: 
						sptr++;
						(*copyptr).copy(*sptr);
						break;
					case 2: 
						copyptr++;
						(*copyptr).copy(*sptr);
						break;
					default:
						cout << "incorrect selection, please try again" << endl;
						break;
				}
				sptr = homeptr;
				copyptr = homeptr;
				break;
			case 4:
				for (int i = 0; i < 2; i++)
				{
					(*sptr).length();
					sptr++;
				}
				
				sptr = homeptr;
				break;
			case 5:
				cout	<< "How would you like to proceed?" << endl
					<< "==============================" << endl
					<< "1.) concat String A into String B" << endl
					<< "2.) concat String B into String A" << endl;
					
				cin >> copySelect;
			
				switch (copySelect)
				{
					case 1: 
						sptr++;
						(*copyptr).concat(*sptr);
						break;
					case 2: 
						copyptr++;
						(*copyptr).concat(*sptr);
						break;
					default:
						cout << "incorrect selection, please try again" << endl;
						break;
				}
				sptr = homeptr;
				copyptr = homeptr;
				break;
			
			case 6:
					cout	<< "How would you like to proceed?" << endl
					<< "==============================" << endl
					<< "1.) compare String A to String B" << endl;
					
				cin >> copySelect;
			
				switch (copySelect)
				{
					case 1: 
						sptr++;
						(*copyptr).compare(*sptr);
						
						if ((*copyptr).compare(*sptr) == 1)
							{
								cout << endl;
								(*sptr).print();
							   	cout << "is bigger than" << endl;
							   	(*copyptr).print();
							}
						else if ((*copyptr).compare(*sptr) == 0)
							{
								cout << endl;
								(*copyptr).print();
								cout << "is bigger than" << endl;
								(*sptr).print();
							}
						break;
					default:
						cout << "incorrect selection, please try again" << endl;
						break;
				}
				sptr = homeptr;
				copyptr = homeptr;
				break;
			case 7:				
				for (int i = 0; i < 2; i++)
				{
					(*sptr).print();
					sptr++;
				}
				
				sptr = homeptr;
				break;
			case 8:
				fin.close();
				for (int i = 0; i < 2; i++)
				{
					(*sptr).deallocate();
					sptr++;
				}
				
				sptr = homeptr;
				
				delete [] sptr;
				delete [] temp;
				delete [] fileName;
				
				sptr = homeptr = NULL;
				copyptr = NULL;
				temp = NULL;
				fileName = NULL;
				
				exitOut = true;
				break;
		}
	}while(!exitOut);
	
	return 0;
}

///////////////////////////////////////////////
//this function will print out the project menu
///////////////////////////////////////////////
void printMenu(int& selection)
{	
	cout	<<  endl << "Project 5 Menu" << endl
		<< "==============" << endl
		<< "1.)open file" << endl
		<< "2.)initialize string (2 at a time)" << endl
		<< "3.)copy string" << endl
		<< "4.)string length" << endl
		<< "5.)string concat" << endl
		<< "6.)string compare" << endl
		<< "7.)print string" << endl
		<< "8.)exit" << endl << endl
		<< "Make a selection: ";
		
	cin >> selection;
	cout << endl;
}
