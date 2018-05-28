#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
class Class1
{

private:
	int b;
	int d;
	char a;
	char c;
	const int u=0;
	static int f;
	//double w;
	//static int e;
public:
	Class1();
	~Class1();
	void show() { cout << "Show" << endl; }
};

