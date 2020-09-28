#include <iostream>
#include<string>

using namespace std;

class Employee
{
    private:
    int employee_id;
    string name;
    string department;
    string designation;
    int salary;

    public:
    void getdata();
    void display();
};

void Employee::getdata()
{
    cout<<"Enter employee details here: "<<endl;
    cout<<"Enter employee id: "<<endl;
    cin>>employee_id;
    cout<<"Enter employee Name: "<<endl;
    cin>>name;
    cout<<"Enter employee department: "<<endl;
    cin>>department;
    cout<<"Enter employee designation: "<<endl;
    cin>>designation;
    cout<<"Enter salary of employee: "<<endl;
    cin>>salary;
};

void Employee::display()
{
    cout<<"Employee details are: "<<endl;
    cout<<"Employee id is:"<<employee_id<<endl;
    cout<<"Name of employee is:"<<name<<endl;
    cout<<"Department:"<<department<<endl;
    cout<<"Designation:"<<designation<<endl;
    cout<<"Salary:"<<salary<<endl;
};

int main()
{
    int i;
    Employee emp[5];
    for ( i = 1; i < 5; i++)
    {
        emp[i].getdata();
    }
    for ( i = 1; i < 5; i++)
    {
        emp[i].display();
    }
    return 0;
}
    
