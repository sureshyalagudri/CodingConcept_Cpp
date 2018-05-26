#include "Mystring.h"

Mystring::Mystring()
{
}

Mystring::Mystring(const char * value)
{
	data = new char[strlen(value) + 1];
	strcpy(data, value);
	
}

Mystring::Mystring(Mystring const & value)
{
	data = new char[strlen(value.data) + 1];
	strcpy(data, value.data);
	
	printf("Copy Constructor is called \n");
}

Mystring & Mystring::operator=(const Mystring & value)
{
	if (this->data != nullptr)
	{
		delete this->data;
		this->data = new char(strlen(value.data) + 1);
		strcpy(this->data, value.data);
	}
	else
	{
		this->data = new char(strlen(value.data) + 1);
		strcpy(this->data, value.data);
	}

	printf("Assignment operator is called \n");

	return *this;
}

bool Mystring::operator<(const Mystring & value)
{
	if (strlen(this->data) < strlen(value.data))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mystring::operator>(const Mystring & value)
{
	if (strlen(this->data) > strlen(value.data))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Mystring& Mystring::operator+(const Mystring & value)
{
	strcat(this->data, value.data);
	return *this;
}

char * Mystring::GetData()
{
	return data;
}

Mystring::~Mystring()
{
	
}

