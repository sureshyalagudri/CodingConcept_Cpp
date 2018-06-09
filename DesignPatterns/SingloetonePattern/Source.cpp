#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <iostream>
#include "Singleton.h"

using namespace std;


int main()
{
	//Singleton * abc = Singleton::GetInstance();
	//abc->add(8, 6);
	//abc->Delete();
	Singleton::GetInstance();
	return 0;
}