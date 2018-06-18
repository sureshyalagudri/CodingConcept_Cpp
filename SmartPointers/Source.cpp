#include<stdio.h>
#include<Windows.h>
#include<memory> 
#include<iostream> 
#include<string> 
using namespace std;

struct Employee
{
	unsigned id;
	string Name;
	float Salary;

	Employee(unsigned _id, string _name, float _salary) :id{ _id }, Name{ _name }, Salary{ _salary }
	{}
};

int main()
{

#pragma region MyRegion
	char date[10];
	cin.getline(date, 10);

	char * day;
	char * month;
	char * year;

	day = strtok(date, " ");
	month = strtok(NULL, " ");
	year = strtok(NULL, " ");

	int d = atoi(day);
	d = d - 1;

	char buffer[10];
	_itoa(d, buffer, 10);

	strcat(buffer, " ");
	strcat(buffer, month);
	strcat(buffer, " ");
	strcat(buffer, year);


	cout << buffer;


#pragma endregion

#pragma region Uniq PTR
	// Exclusively owns object to which it points
	// Can’t be copied
	// Can be moved
	// make_unique
	
	auto emp1 = make_unique<Employee>(1, "suresh", 29.78f);

	if (emp1) cout << "Created" << endl;

	//auto emp2 = emp1; // build error 
	// use move to resolve copy constructor issue 
	auto emp2 = move(emp1);
	if (emp1) cout << "Created" << endl;


	// Get method.
	auto emp12 = unique_ptr<Employee>{ new Employee(1, "suresh", 29.78f)};
	Employee * emp3 = emp1.get();
	cout << emp3->Name << endl;


#pragma endregion



	return 0;
}