#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class base
{
private:
public:
	void PrintData() { cout << "Base PrintData" << endl; }
};

class Derived1: virtual public base
{
private:
public:
};

class Derived2 : virtual public base
{
private:
public:
};

class DiamondInheritance: public Derived1, public Derived2
{
public:
	DiamondInheritance();
	~DiamondInheritance();
};

