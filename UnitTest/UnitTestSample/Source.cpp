#include<stdio.h>
#include<iostream>
#include<cassert>
#include<crtdbg.h>
using namespace std;

struct abc
{
	abc() {}
	~abc() {}
};

int main()
{
	try
	{
		// assert(4 == 7); // Doesnot show build time error 

		//_ASSERT(2 == 3);

		//static_assert(sizeof(double) == 4, "zZXC"); // Shows the error while debug 
		static_assert(sizeof(double) == 8, "zZXC");

	}
	catch (const std::exception ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}