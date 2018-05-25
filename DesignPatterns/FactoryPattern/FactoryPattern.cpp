#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

public enum EmployeeType { Permanent = 1, Contract };

public class IEmployee
{
private:

public:
	string Name;
	string Department;
	double Salary;
	virtual double CalculateBonus()
	{
		return 0;
	};

};

public class PermanantEmployee :public IEmployee
{
private:
public:
	PermanantEmployee(string name, string dept, double salary)
	{
		Name = name;
		Department = dept;
		Salary = salary;
	}
	virtual double CalculateBonus()
	{
		return Salary * 10;
	}
};

public class ContractEmployee :public IEmployee
{
private:
public:
	ContractEmployee(string name, string dept, double salary)
	{
		Name = name;
		Department = dept;
		Salary = salary;
	}

	virtual double CalculateBonus()
	{
		return Salary * 5;
	}
};


class EmployeeFactory
{
public:
	virtual IEmployee * GetEmployee(string name, string dept, double salary, int type)
	{
		//IEmployee  emp;
		return NULL;
	}
};

class ConcreteEmployeeFactory :EmployeeFactory
{
public:
	IEmployee * GetEmployee(string name, string dept, double salary, EmployeeType type)
	{
		IEmployee  * emp;

		switch (type)
		{
		case Permanent:
			emp = new PermanantEmployee(name, dept, salary);
			break;
		case Contract:
			emp = new ContractEmployee(name, dept, salary);
			break;
		default:
			break;
		}

		return emp;
	}
};

void main()
{
	cout << "Start Main" << endl;

	ConcreteEmployeeFactory * empFactory = new ConcreteEmployeeFactory();
	vector <IEmployee*> employees;

	employees.push_back(empFactory->GetEmployee("aa", "Dev", 1000, Permanent));
	employees.push_back(empFactory->GetEmployee("bb", "Dev", 500, Contract));
	employees.push_back(empFactory->GetEmployee("CC", "HR", 200, Permanent));

	for (int i = 0; i < employees.size(); i++)
	{
		std::cout << "Name: " << employees[i]->Name.c_str() << " Department " << employees[i]->Department.c_str() << " Salary: " << employees[i]->Salary << " Bonus: " << employees[i]->CalculateBonus() << endl;
	}

	//std::list<IEmployee*>::iterator * emp;
	//for (emp = employees->begin(); emp != employees->end(); ++emp)
	//{
	//	dynamic_cast < PermanantEmployee * >
	//	std::cout << "Name: " << emp->Name.c_str() << " Department " << emp->Department.c_str() << " Salary: " << emp->Salary << " Bonus: " << emp->CalculateBonus() << endl;
	//}
}