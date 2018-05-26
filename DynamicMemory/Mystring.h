#pragma once
#include <stdio.h>
#include <string.h>
using namespace std;

class Mystring
{
private:
	char * data;
public:
	Mystring();
	Mystring(const char * value);
	Mystring(Mystring const & value);
	Mystring & operator =(const Mystring &value);
	bool operator <(const Mystring &value);
	bool operator >(const Mystring &value);
	Mystring & operator +(const Mystring &value);
	 
	char * GetData();

	~Mystring();
};

