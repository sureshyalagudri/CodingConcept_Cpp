#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
#pragma region Write code to reverse string 
	string str = "Hello world!";

	//getline(cin, str);

	//simple way
	//reverse(str.begin(), str.end());
	cout << str<<endl;
	int length = str.length();
	//for (size_t i = 0; i < length /2; i++)
	//{
	//	char temp = str[i];
	//	str[i] = str[length - i - 1];
	//	str[length - i - 1] = temp;
	//}

	for (int i = 0; i<length / 2; i++)
	{
		std::swap(str[i], str[length - i - 1]);
	}

	cout << str << endl;
#pragma endregion

#pragma region Write code which take date as "DD MM YYYY" and return date by less then one day 
	// e.g input 8 9 1986 should print 7 9 1986

	string date = "8 9 1986";

	//getline(cin, date);
	char* day = NULL;
	char* month = NULL;
	char* year = NULL;
	char * data;
	char * temp = const_cast<char*> (date.c_str());
	
	day = strtok_s(temp, " ", &data);
	month = strtok_s(NULL, " ", &data);
	year = strtok_s(NULL, " ", &data);

	int d = atoi(day);
	d -= 1;

	char * buffer = new char[10];
	_itoa_s(d, buffer, sizeof buffer,  10);

	strcat_s(buffer, 10, " ");
	strcat_s(buffer, 10, month);
	strcat_s(buffer, 10, " ");
	strcat_s(buffer, 10, year);

	cout << "converted string: "<<buffer << endl;

#pragma endregion

#pragma region Code to 
	// Man travels X steps upward in day time 
	// Y step downwards in night 
	// for given steps N how many days he will take 

	double up = 5;
	double down = 2;
	double steps = 10;

	//cin >> up;
	//cin >> down;
	//cin >> steps;

	double dailyTravel = up - down;
	double days = steps/dailyTravel;

	cout << days << endl;

#pragma endregion


	return 0;
}