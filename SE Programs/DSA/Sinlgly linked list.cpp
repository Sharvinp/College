#include <iostream>
using namespace std;
class node
{
public:
	int no;
	node* next;
};
class list
{
	node* head, * temp, * add;
	int key;
public:
	void create_list();
	void display();
	void insert_before();
	void insert_after();
	void delete_node();
};
void list::create_list() //Function to create a linked list.
{
	int n, i;
	cout << "Enter the number of nodes in the linked list: ";
	cin >> n;
	head = new node;
	temp = head;
	cout << "Enter the value of node 1 : ";
	cin >> head->no;
	for (i = 1; i < n; i++)
	{
		head->next = new node;
		head = head->next;
		cout << "Enter the value of node " << i + 1 << " : ";
		cin >> head->no;
	}
	head->next = NULL;
}
void list::insert_before() //Function to insert a node before an element.
{
	add = new node;
	cout << "\nEnter the value to be inserted: ";
	cin >> add->no;
	cout << "Enter before which number do you want to insert " << add->no << " : ";
	cin >> key;
	head = temp;
	if (head->no == key)
	{
		add->next = head;
		head = add;
		cout << "Linked List:" << endl;
		while (head != NULL)
		{
			cout << head->no << " ";
			head = head->next;
		}
		cout << endl;
	}
	else
	{
		while (head->next->no != key)
		{
			head = head->next;
		}
		add->next = head->next;
		head->next = add;
		display();
	}
}
void list::insert_after() //Function to insert a node after an element.
{
	add = new node;
	cout << "\nEnter the value to be inserted: ";
	cin >> add->no;
	cout << "Enter after which number do you want to insert " << add->no << " : ";
	cin >> key;
	head = temp;
	while (head->no != key)
	{
		head = head->next;
	}
	add->next = head->next;
	head->next = add;
	display();
}
void list::delete_node() //Function to delete a node.
{
	cout << "\nEnter value to be deleted: ";
	cin >> key;
	head = temp;
	if (head->no == key)
	{
		head = head->next;
		cout << "Linked List:" << endl;
		while (head != NULL)
		{
			cout << head->no << " ";
			head = head->next;
		}
		cout << endl;
	}
	else
	{
		while (head->next->no != key)
		{
			head = head->next;
		}
		if (head->next->next == NULL)
		{
			head->next = NULL;
		}
		else
		{
			head->next = head->next->next;
		}
		display();
	}
}
void list::display() //Function to display linked list.
{
	cout << "Linked List:" << endl;
	head = temp;
	while (head != NULL)
	{
		cout << head->no << " ";
		head = head->next;
	}
	cout << endl;
}
int main()
{
	int choice;
	list L;
	L.create_list();
	do
	{
		cout << "\nEnter choice of operation to be performed: ";
		cout << "\n1)Display Linked List. \n2)Insert node before a number.";
		cout << "\n3)Insert node after a number. \n4)Delete a node. \n5)Exit." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			L.display();
			break;
		case 2:
			L.insert_before();
			break;
		case 3:
			L.insert_after();
			break;
		case 4:
			L.delete_node();
			break;
		case 5:
			break;
		default:
			cout << "Enter valid choice.";
		}
	} while (choice != 5);
	return 0;
}
