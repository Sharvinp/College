#include <iostream>
using namespace std;
class node
{
 public:
 int data;
 node* next;
};
class queuenode
{
 node *front, *rear;
 public:
 queuenode()
 {
 front = NULL;
 rear = NULL;
 }

 void enqueue(int value);
 void dequeue();
 void displayqueue();
};
void queuenode :: enqueue(int value)
{
 node *temp;
 temp = new node();
 temp->data = value;
 temp->next = NULL;

 if(front==NULL)
 {
 front = temp;
 rear = temp;
 }
 else
 {
 rear->next = temp;
 rear = temp;
 }
 displayqueue();
}
void queuenode :: dequeue()
{
 if(front==NULL && rear==NULL)
 {
 cout<<"Queue is Empty!"<<endl;
 return;
 }
 else if(front==rear)
 {
 free(front);
 front=rear=NULL;
 }
 else
 {
 node* temp;
 temp = front;
 front = front->next;
 temp->next = NULL;
 cout<<"Element dequeued is: "<<temp->data;
 }
 displayqueue();
}
void queuenode :: displayqueue()
{
 if(front==NULL && rear==NULL)
 {
 cout<<"Queue is empty!"<<endl;
 return;
 }
 else
 {
 node* temp;
 temp = front;
 cout<<"\nLinked list: "<<endl;
 while(temp!=NULL)
 {
 //cout<<"Linked list: "<<endl;
 cout<<temp->data<<" ";
 temp = temp->next;
 }
 }
}
int main()
{
 queuenode q;
 int x, choice;
 cout<<"\n1.Enqueue\n2.Dequeue\n3.Exit\n";
 do
 {
 cout<<"\nEnter operation to be performed: ";
 cin>>choice;
 switch(choice)
 {
 case 1:
 {
 cout<<"Enter element to be enqueued: ";
 cin>>x;
 q.enqueue(x);
 break;
 }

 case 2:
 {
 q.dequeue();
 break;
 }

 case 3:
 {
 cout<<”Operation completed!!”;
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
