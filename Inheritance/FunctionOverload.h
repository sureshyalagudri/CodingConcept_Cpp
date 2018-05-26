#pragma once
class FunctionOverload
{
public:
	FunctionOverload();
	~FunctionOverload();

	int Add(int a, int b);
	int Add(double a, double b);
	// double Add(int a, int b); //Gives compile time error 
	int Add(int a, int b, int c);
	double Add(int a, int b, double);
};

