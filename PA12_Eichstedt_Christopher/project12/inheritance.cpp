#include "inheritance.h"
#include <iostream>

using namespace std;

Rectangle :: Rectangle(float x, float y)
{
	length = x;
	width = y;
	isThreeDimensional = false;
}

float Rectangle :: calculateAreaOrVolume()
{
	return length * width;
}

float Rectangle :: calculatePerimeterOrSurfaceArea()
{
	return (2*length) + (2*width);
}

void Rectangle :: print()
{
	cout << "Rectangle that has a length of " << length << ", and width of " << width;
}

RectangularPrism :: RectangularPrism(float x, float y, float z)
{
	length = x;
	width = y;
	height = z;
	isThreeDimensional = true;
}

float RectangularPrism :: calculateAreaOrVolume()
{
	return length * width * height;
}

float RectangularPrism :: calculatePerimeterOrSurfaceArea()
{
	return 2 * (width * length + height * length + height * width);
}

void RectangularPrism :: print()
{
	cout << "Rectangular Prism that has a length of " << length << ", width of " << width << ", and height of "  << height;
}

Circle :: Circle(float x)
{
	radius = x;
	isThreeDimensional = false;
}

float Circle :: calculateAreaOrVolume()
{
	return 3.14159 * (radius * radius);
}

float Circle :: calculatePerimeterOrSurfaceArea()
{
	return 2 * 3.14159 * radius;
}

void Circle :: print()
{
	cout << "Circle has a radius of " << radius;
}

Cylinder :: Cylinder(float x, float y)
{
	radius = x;
	height = y;
	isThreeDimensional = true;
}

float Cylinder :: calculateAreaOrVolume()
{
	return 3.14159 * (radius * radius) * height;
}

float Cylinder :: calculatePerimeterOrSurfaceArea()
{
	return 2 * (3.14159 * radius * height) + 2 * (3.14159 * (radius * radius));
}

void Cylinder :: print()
{
	cout << "Cylinder that has a radius of " << radius << ", and the height of " << height;
}
