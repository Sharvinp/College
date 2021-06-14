#include <iostream>
using namespace std;

struct student
{
    int srno;
    char name[25];
    float sgpa;
};

class queue 
{
    struct student stud[6];
    int size, front, rear;
    
    public:
    queue()
    {
        size = 6;
        front = -1;
        rear = -1;
    }
    
    void enqueue(struct student);
    void dequeue();
    void display();
};

void queue :: enqueue(student temp)
{
    if((front==0 && rear==size-1) || (front==rear+1))
    {
        cout<<"No seats available!!"<<endl;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear = (rear+1)%size;
        stud[rear] = temp;
        display();
    }
}

void queue :: dequeue()
{
    if(front==-1)
    {
        cout<<"There are no pending admissions..."<<endl;
    }
    else
    {
        int i = front;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front = (front+1)%size;
        }
        cout<<"Admission allocated to "<<stud[i].name<<endl;
        display();
    }
}

void queue :: display()
{
    if(front==-1)
    {
        cout<<"There are no pending admissions..."<<endl;
    }
    else
    {
        int i = front;
        
        cout<<"\nStudents' List is as follows: "<<endl;
        cout<<"Sr.No.  Name  SGPA"<<endl;
        
        while(i!=rear)
        {
            cout<<"  "<<stud[i].srno<<"    "<<stud[i].name<<"   "<<stud[i].sgpa<<endl;
            
            i = (i+1)%size;
        }
        
        cout<<"  "<<stud[i].srno<<"    "<<stud[i].name<<"   "<<stud[i].sgpa<<endl;
    }
}

int main()
{
    int choice;
    student stud;
    
    queue que;
    
    do
    {
        cout<<"\n1.Enter student detals\n2.Allocate admission to student\n3.Display list of student\n4.Exit"<<endl;
        
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter student details:"<<endl;
                cout<<"Enter Sr. No. : ";
                cin>>stud.srno;
                cout<<"Enter Name: ";
                cin>>stud.name;
                cout<<"Enter SGPA: ";
                cin>>stud.sgpa;
                que.enqueue(stud);
                break;
            }
            
            case 2:
            {
                que.dequeue();
                break;
            }
            
            case 3:
            {
                que.display();
                break;
            }
            
            case 4:
            {
                cout<<"Done!!"<<endl;
                break;
            }
            
            default:
            {
                cout<<"Wrong choice!!"<<endl;
                break;
            }
        }
    }while(choice!=4);

    return 0;
}
