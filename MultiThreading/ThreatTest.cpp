#include "ThreatTest.h"



ThreatTest::ThreatTest()
{
}


ThreatTest::~ThreatTest()
{
}

void ThreatTest::operator()(int count, string s)
{
	for (int i = 0; i < count; i++)
	{
		cout<< s.c_str()<<":Thread Executing from Class object \n" << endl;
	}
}
