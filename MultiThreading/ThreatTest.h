#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

class ThreatTest
{
public:
	ThreatTest();
	~ThreatTest();

	void operator()(int , string);
};

