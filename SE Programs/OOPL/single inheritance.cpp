//Write a program to implement Single Inheritance and also resolve ambiguity in function overriding for employee data
#include<iostream>
#include<conio.h>

using namespace std;

class base
{
	char name[30];
public:
	void getdetails()
	{
		cout << "\nEnter the name of the employess: ";
		cin >> name;
	}
	void display()
	{
		cout << "\nName: " << name;
	}
};
class derived : public base
{
	char desig[30];
		double salary;
public:
	void getdetails()
	{
		cout << "\nEnter salary of the employee: ";
		cin >> salary;
		cout << "\nEnter designation of the employee: ";
		cin >> desig;
	}
	void display()
	{
		base::display();
		cout << "\nSalary: " << salary;
		cout << "\nDesignation: " << desig << endl;
	}
};
int main()
{
	derived d1, d2;
	d1.base::getdetails();
	d1.derived::getdetails();
	d2.base::getdetails();
	d2.derived::getdetails();
	cout << "\nDetails of the employees are: ";
	d1.display();
	d2.display();
}
