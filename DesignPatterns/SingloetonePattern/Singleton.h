#pragma once
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <iostream>

using namespace std;

class Singleton
{
private:
	Singleton();
	~Singleton();
	static Singleton * m_instance;
public:
	static Singleton * Singleton::GetInstance();
	static int add(int a, int b);
	void Singleton::Delete();
};

