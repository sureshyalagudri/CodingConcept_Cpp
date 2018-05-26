#include "AbstractClass.h"



AbstractClass::AbstractClass()
{
	cout << "AbstractClass" << endl;
}


AbstractClass::~AbstractClass()
{
	cout << "~AbstractClass" << endl;
}

int AbstractClass::Add(int a, int b)
{
	cout << "AbstractClass:Add" << endl;
	return a + b;
}
