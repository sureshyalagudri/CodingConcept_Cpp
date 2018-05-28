#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include "ThreatTest.h"

using namespace std;

void ThreadasFunct1(int count, string s)
{
	try
	{
		for (int i = 0; i < count; i++)
		{
			cout << "Eecuting Thread: " << s.c_str() << "\n" << endl;
		}
	}
	catch (exception ex)
	{
		throw ex;
	}
}

void ThreadasFunct2(int count, string s)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Eecuting Thread: " << s.c_str() << "\n" << endl;
	}
}

int main()
{
	try
	{
		cout << "Main Start" << endl;

		// Use Thread with Function.
		thread t1(ThreadasFunct1, 4, "t1");
		thread t2(ThreadasFunct2, 4, "t2");
		thread::id  ii = t1.get_id();

		t1.join();
		t2.join();

		// Use Thread with Lambda Expression.
		auto a = [](int x, string s)
		{
			for (int i = 0; i < x; i++)
				cout << s.c_str() << ": Thread is executing from Lambda Expression \n" << endl;
		};
		thread t3(a, 4, "t3");
		thread t4(a, 4, "t4");
		t3.join();
		t4.join();

		// Use Thread with class object.
		thread t5(ThreatTest(), 4, "t5");
		thread t6(ThreatTest(), 4, "t6");
		t5.join();
		t6.join();

		// Loop of thread 
		std::thread threads[5];
		for (int i = 0; i < 5; ++i)
		{
			string s = to_string(i);
			threads[i] = std::thread(ThreadasFunct1, i + 1, s);
		}

		//Execute threads.
		for (int i = 0; i < 5; ++i)
		{
			threads[i].join();
		}

		cout << "Main End" << endl;
	}
	catch (exception ex)
	{
		cout << ex.what()<<endl;
	}
	return 0;
}