

#include<iostream>
#include<string>

using namespace std;

class student
{
protected:
	int roll_no;
public:
	void getroll(int rn)
	{
		roll_no = rn;
	}
	void putroll(void)
	{
		cout << "Roll No. of student is " << roll_no << endl;
	}
};
class test :virtual public student
{
protected:
	int test_marks;
public:
	void getinfo(int m)
	{
		test_marks = m;
	}
	void putinfo()
	{
		cout << "Test marks of student are " << test_marks << endl;
	}
};

class score :public virtual student
{
protected:
	int marks;
public:
	void getscore(int y)
	{
		marks = y;
	}
	void putscore()
	{
		cout << "Score of student is " << marks << endl;
	};
};

class result :public test, public score
{
private:
	int total;
public:
	void display()
	{
		total = test_marks + marks;
		putroll();
		putinfo();
		putscore();
		cout << "Total score is " << total << endl;
	}
};

int main()
{
	result student;
	student.getroll(22);
	student.getinfo(65);
	student.getscore(77);
	student.display();
	return 0;
}
