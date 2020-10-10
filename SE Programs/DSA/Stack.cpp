#include <iostream>
using namespace std;
class node
{
 public:
 int data;
 node* next;
};
class stacknode
{
 node* head;
 public:
 stacknode()
 {
 head = NULL;
 }

 void push(int value);
 void pop();
 void display();
};
void stacknode :: push(int value)
{
 node *temp;
 temp = new node();
 temp->data = value;
 if(head==NULL)
 {
 temp->next = NULL;
 }
 else
 {
 temp->next = head;
 }
 head = temp;
 display();
}
void stacknode :: pop()
{
 node* temp;
 if(head==NULL)
 {
 cout<<"\nStack Underflow!!"<<endl;
 return;
 }
 else
 {
 temp = head;
 head = head->next;
 temp->next = NULL;
 cout<<"\nElement popped is: "<<temp->data;
 }
 display();
}
void stacknode :: display()
{
 node* temp;
 if(head==NULL)
 {
 cout<<"\nStack Underflow!!"<<endl;
 return;
 }
 else
 {
 cout<<"\nLinked List: "<<endl;
 temp = head;
 while(temp!=NULL)
 {
 cout<<temp->data<<" ";
 temp = temp->next;
 }
 }
}
int main()
{
 int x, choice;
 stacknode st;

 cout<<"1.Push Element in stack\n2.Pop Element in stack\n3.Exit"<<endl;

 do
 {
 cout<<"\nEnter operation to br performed:";
 cin>>choice;

 switch(choice)
 {
 case 1:
 {
 cout<<"Enter element to be pushed: ";
 cin>>x;
 st.push(x);
 break;
 }

 case 2:
 {
 st.pop();
 break;
 }

 case 3:
 {
 cout<<"Operation completed!!"<<endl;
 break;
 }

 default:
 {
 cout<<"Wrong option!!"<<endl;
 break;
 }
 }
 }while(choice!=3);

 return 0;
}
