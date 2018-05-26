#include "FunctionOverload.h"



FunctionOverload::FunctionOverload()
{
}


FunctionOverload::~FunctionOverload()
{
}

int FunctionOverload::Add(int a, int b)
{
	return a + b;
}

int FunctionOverload::Add(double a, double b)
{
	return a + b;
}

int FunctionOverload::Add(int a, int b, int c)
{
	return a + b + c;
}

double FunctionOverload::Add(int a, int b, double c)
{
	return a + b + c;
}
