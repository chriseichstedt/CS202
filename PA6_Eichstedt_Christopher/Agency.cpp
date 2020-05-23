#include "Agency.h"
#include "String.cpp"
#include <iostream>
#include <fstream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
//car class functions
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////constructors//////////////////

//default constructor
Car :: Car()
{
	make = new char[100];
	model = new char[100];
	year = 0;
	price = 0.0;
	available = false;
}

//parameterized constructor
Car :: Car(char *makeTemp, char *modelTemp, int yearTemp, float priceTemp, bool availableTemp)
{
	char *makePtr = makeTemp;
	make = new char[100];
	char *makeHome = make;

	strCopy(make, makePtr);
	
	make = makeHome;
	
	char *modelPtr = modelTemp;
	model = new char[100];
	char *modelHome = model;
	
	strCopy(model,modelPtr);
	
	model = modelHome;
	
	year = yearTemp;
	price = priceTemp;
	available = availableTemp;
}

//copy constructor
Car :: Car(const Car& temp)
{
	char *makePtr = temp.make;
	
	make = new char[100];
	char *makeHome = make;
	
	strCopy(make, makePtr);
	
	make = makeHome;
	
	char *modelPtr = temp.model;
	
	model = new char[100];
	char *modelHome = model;
	
	strCopy(model, modelPtr);
	
	model = modelHome;

	year = temp.year;	
	price = temp.price;
	available = temp.available;
}

//destructor
Car :: ~Car()
{
	delete[] make;
	make = NULL;
	delete[] model;
	model = NULL;
	year = 0;
	price = 0.0;
	available = false;
}

//copy car data
void Car :: copy(Car temp)
{
	char *makeHome = make;
	char *makeTemp = temp.make;
	
	strCopy(makeHome, makeTemp);
	
	char *modelHome = model;
	char *modelTemp = temp.model;
	
	strCopy(modelHome, modelTemp);
	
	year = temp.year;
	price = temp.price;
	available = temp.available;
}

//print car data
void Car :: print() const
{
	cout << make << " " << model << " " << year << " $" << price << ", " << "available: " << boolalpha << available << endl;
}

//////////////////get functions//////////////////

char *Car::getMake() const
{
	return make;
}

char *Car::getModel() const
{
	return model;
}

int Car::getYear() const
{
	return year;
}

float Car::getPrice() const
{
	return price;
}

bool Car::getAvailable() const
{
	return available;
}

///////////////////set functions/////////////////

void Car :: setMake(char *makeTemp)
{	
	strCopy(make, makeTemp);
}

void Car :: setModel(char *modelTemp)
{	
	strCopy(model, modelTemp);
}

void Car :: setYear(int yearTemp)
{
	year = yearTemp;
}

void Car :: setPrice(float priceTemp)
{
	price = priceTemp;
}

void Car :: setAvailable(bool availableTemp)
{
	available = availableTemp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//agency class functions
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////constructors//////////////////

//default constructor
Agency :: Agency()
{
	name = new char[100];
	zipcode = new int[5];
	inventory = new Car[15];
}

//copy constructor
Agency :: Agency(const Agency &temp)
{	
	name = new char[100];
	char *nameHome = name;
	char *namePtr = temp.name;
	
	strCopy(name, namePtr);
	
	name = nameHome;
	
	int *zipcodePtr = temp.zipcode;
	zipcode = new int[5];
	int *zipcodeHome = zipcode;
	
	for(int i = 0; i < 5; i++)
	{
		*zipcode = *zipcodePtr;
		zipcodePtr++;
		zipcode++; 
	}
	
	zipcode = zipcodeHome;
}

//destructor
Agency :: ~Agency()
{
	delete[] name;
	name = NULL;
	delete[] zipcode;
	zipcode = NULL;
	delete[] inventory;
	inventory = NULL;
}

///////////////////other functions///////////////

void Agency :: readInData(char *fileName)
{
	ifstream fin;
	fin.open(fileName);
	
	fin >> name;
	
	int *zipcodePtr = zipcode;
	char *tempPtr = new char[5];
	
	for(int i = 0; i < 5; i++)
	{
		fin >> *tempPtr;
		*zipcodePtr = (*tempPtr - '0');
		zipcodePtr++;
	}
	
	zipcodePtr = zipcode;
	
	int yearTemp;
	float priceTemp;
	bool availableTemp;
	char *makeTemp = new char[100];
	char *modelTemp = new char[100];
	Car *carPtr = inventory;
	
	for(int i = 0; i < 15; i++)
	{
		fin >> yearTemp;
		(*carPtr).setYear(yearTemp);
		
		fin >> makeTemp;
		(*carPtr).setMake(makeTemp);
		
		fin >> modelTemp;
		(*carPtr).setModel(modelTemp);
		
		fin >> priceTemp;
		(*carPtr).setPrice(priceTemp);
		
		fin >> availableTemp;
		(*carPtr).setAvailable(availableTemp);
		
		carPtr++;
	}
	
	delete[] tempPtr;
	delete[] makeTemp;
	delete[] modelTemp;
	
	tempPtr = NULL;
	makeTemp = NULL;
	modelTemp = NULL;
	
	fin.close();
	
}

void Agency :: print() const
{
	Car *carTemp = inventory;
	int *zipTemp = zipcode;
	
	cout << name << " ";
	
	for(int i = 0; i < 5; i++)
	{
		cout << *zipTemp;
		zipTemp++;
	}
	
	cout << endl;
	
	for(int i = 0; i < 15; i++)
	{
		cout << "#" << i+1 << " ";
		(*carTemp).print();
		carTemp++;
	}
}

void Agency :: printAvailableCars() const
{
	Car *carPtr = inventory;
	
	for(int i = 0; i < 15; i++)
	{
		if ((*carPtr).getAvailable() == true)
		{
			(*carPtr).print();
		}
		carPtr++;
	}		
	
	carPtr = inventory;
}

void Agency :: findMostExpensive() const
{
	Car *tempA = inventory;
	Car *tempB = inventory;
	tempB++;
	
	for (int i = 0; i < 15; i++)
	{
		tempB++;
		 
		if ((*tempA).getPrice() < (*tempB).getPrice())
		{
			tempA = tempB;
		}
	}
	
	(*tempA).print();
}

float Agency :: estimateCost(int carNumber, int days) const
{
	float cost;
	
	Car *carPtr = inventory;
	
	for (int i = 0; i < carNumber - 1; i++)
	{
		carPtr++;
	}
	
	cost = ((*carPtr).getPrice() * days);
	
	cout << "Your total is $" << cost << endl;
	
	return cost;
}


void Agency :: sortByMake() //selection sort version
{
	Car *carA = inventory;
	Car *carB = carA;
	Car tempCar;
	
	bool finished = false;
	int start = 0;
	int finish = 14;
	carB++;
	
	do{
		carA = inventory;
		carB = carA;
		carB++;
		finished = true;
			
		for(int i = 0; i < start; i++)
		{
			carA++;
			carB++;
		}
	
		for(int i = 0; i < finish; i++)
		{
			if((*carA).getMake() > (*carB).getMake())
			{
				tempCar.copy(*carA);
				(*carA).copy(*carB);
				(*carB).copy(tempCar);	
				finished = false;		
			}
			
			/*
			if(strCompare((*carA).getMake(),(*carB).getMake()))
			{
				tempCar.copy(*carA);
				(*carA).copy(*carB);
				(*carB).copy(tempCar);
				finished = false;				
			}
			*/
		}
		
		start++;
		finish--;
		
	}while(!finished);
}

/*
void Agency :: sortByMake() //bubble sort version
{	
	Car *carA = inventory;
	Car *carB = carA;
	Car tempCar;
	carB++;
	
	bool finished = false;
	
	do{	
		carA = inventory;
		carB = carA;
		carB++;
		finished = true;
		
		for(int i = 0; i < 14; i++)
		{	
			if((*carA).getMake() > (*carB).getMake())
			{
				tempCar.copy(*carA);
				(*carA).copy(*carB);
				(*carB).copy(tempCar);	
				finished = false;		
			}
			
			carA++;
			carB++;
		}
		
	}while (!finished);
}
*/

void Agency :: sortByPrice()
{	
	Car *carA = inventory;
	Car *carB = carA;
	Car tempCar;
	carB++;
	
	bool finished = false;
	
	do{	
		carA = inventory;
		carB = carA;
		carB++;
		finished = true;
		
		for(int i = 0; i < 14; i++)
		{
			if((*carA).getPrice() > (*carB).getPrice())
			{
				tempCar.copy(*carA);
				(*carA).copy(*carB);
				(*carB).copy(tempCar);	
				finished = false;		
			}
			
			carA++;
			carB++;
		}
		
	}while (!finished);
}

void Agency :: searchByMake(char *temp) const
{
	Car *carTemp = inventory;
	char *makeTemp = (*carTemp).getMake();
	char *homeTemp = temp;
	bool flag = false;

	for(int i = 0; i < 15; i++)
	{
		while(*makeTemp != '\0' && *temp != '\0')
		{
			if(*makeTemp == *temp)
			{
				flag = true;
				makeTemp++;
				temp++;		
			}
			
			else
			{
				flag = false;
				break;
			}			
		}
		
		if(flag)
		{
			(*carTemp).print();
		}
		
		carTemp++;
		makeTemp = (*carTemp).getMake();
		temp = homeTemp;
	}	
}
