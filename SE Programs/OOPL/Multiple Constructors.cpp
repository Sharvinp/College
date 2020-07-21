#include<iostream>
#include<stdio.h>

using namespace std;
class add;
{
	private;
	int x, y;
	public;
	add()
		add(int a, int b);
	add(add & a);

	void sum();
};
add::add()
{
	x = 0;
	y = 0;
	cout << "\nDefault constructor used";
}
add::add(int a, int b)
{
	cout << "\nParameterized constructor used";
	x = a;
	y = b;

}
add::add(add& a)
{
	cout << "\nCopy constructor used";
	x = a.x;
	y = a.y;
}
void add::sum()
{
	cout << endl << "Sum:" << (x + y);
}
int main()
{
	add obj1;
	obj1.sum();

	add obj2(10, 20);
	obj2.sum();

	add obj3(obj2);
	obj3.sum();

	return 0;

}
