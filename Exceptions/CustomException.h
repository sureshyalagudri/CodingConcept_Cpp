#pragma once
#include<exception>
#include <stdio.h>
#include <iostream>

using namespace std;

class CustomException: exception
{
private:
	string m_file;
	int m_line;
	int m_status;
	string m_message;
public:
	CustomException(const string file, int line, int status);
	CustomException(const string file, int line, int status, const string message);
	~CustomException();
	
	const string getFile();
	int getLine();
	int getStatus();
	const string getMessage();
};

