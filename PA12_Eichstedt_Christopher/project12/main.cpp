#include "inheritance.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char file[25];
	int size, shapeType;
	float x, y, z;
	ifstream fin;
	
	cout << "enter a file: ";
	cin >> file;
	fin.open(file);
	
	if (!fin)
	{
		cout << "file does not exist" << endl;
		return 0;
	}
	
	
	fin >> size;
	Shape **temp = new Shape*[size];
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		fin >> shapeType;
		
		switch (shapeType)
		{
			case 1:
			{
				fin >> x;
				fin >> y;
				temp[i] = new Rectangle(x, y);
				break;
			}
			case 2:
			{
				fin >> x;
				fin >> y;
				fin >> z;
				temp[i] = new RectangularPrism(x, y, z);
				break;
			}
			case 3:
			{
				fin >> x;
				temp[i] = new Circle(x);
				break;
			}
			case 4:
			{
				fin >> x;
				fin >> y;
				temp[i] = new Cylinder(x, y);
				break;
			}
			default:
			{
				cout << "incorrect shape ID" << endl;
				return 0;
			}
		}
	}
	
	for(int i = 0; i < size; i++)
	{
		if (temp[i]->is3D())
		{
			cout << "The Volume of a ";
			temp[i]->print();
			cout << " is " << temp[i]->calculateAreaOrVolume() << endl;
		}
		
		else
		{
			cout << "The Area of a ";
			temp[i]->print();
			cout << " is " << temp[i]->calculateAreaOrVolume() << endl;
		}
	}
	
	cout << endl;
	
	for(int i = 0; i < size; i++)
	{
		if (temp[i]->is3D())
		{
			cout << "The Surface Area of a ";
			temp[i]->print();
			cout << " is " << temp[i]->calculatePerimeterOrSurfaceArea() << endl;
		}
		
		else
		{
			cout << "The Perimeter of a ";
			temp[i]->print();
			cout << " is " << temp[i]->calculatePerimeterOrSurfaceArea() << endl;
		}
	}
	
	cout << endl;
	
	for(int i  = 0; i < size; i++)
	{
		delete temp[i];
	}
	
	delete [] temp;
	fin.close();
	return 0;
}
