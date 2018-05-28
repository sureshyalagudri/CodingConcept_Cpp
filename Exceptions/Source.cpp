#include <stdio.h>
#include <iostream>
#include "CustomException.h"

class test
{
public:
	void test1() 
	{
		throw CustomException(__FILE__, __LINE__, 0);
	}

	void test2()
	{
		throw  CustomException(__FILE__, __LINE__, 0, "jhaskcjg");
	}
};

using namespace std;
int main()
{
	try
	{
		test t1;
		t1.test1();
		t1.test2();
	}
	catch (CustomException ex)
	{
		cout << ex.getFile().c_str() << endl;
		cout << ex.getLine() << endl;
		cout << ex.getStatus() << endl;
		cout << ex.getMessage().c_str()<<endl;
	}



	return 0;
}