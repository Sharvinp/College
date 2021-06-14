#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct DoB  //structure for storing date of birth 
{
    int day;
    int month;
    int year;
};

struct student  //structure for storing student details
{
    int rn;
    string name;
    string adr;
    char division;
    DoB dob;
    float percent;
    char grade;
};

class seqfile   //class for performing file operations
{
    public:
    student stud;
    //ofstream outfile;
    //ifstream infile;
    fstream file, temp;
    
    void create();
    void display();
    void add();
    void search(int);
    void modify(int);
    void Delete(int);
};

//Function for creating the StudRecord.txt file
void seqfile :: create()
{
    cout<<"\nEnter Student Details:";
    cout<<"\nEnter Roll Number : ";
    cin>>stud.rn;
    cout<<"\nName : ";
    cin>>stud.name;
    cout<<"\nDivision: ";
    cin>>stud.division;
    cout<<"\nAddress: ";
    cin>>stud.adr;
    cout<<"\nDate of Birth (dd mm yyyy): ";
    cin>>stud.dob.day>>stud.dob.month>>stud.dob.year;
    cout<<"\nPercentage: ";
    cin>>stud.percent;
    cout<<"\nGrade: ";
    cin>>stud.grade;
    
    file.open("StudRecord.txt",ios::out);
    file.write((char*)&stud,(sizeof(stud)));
    file.close();
}

//Function to display all StudRecords
void seqfile :: display()
{
    file.open("StudRecord.txt",ios::in);
    file.read((char*)&stud,(sizeof(stud)));
    cout<<"\nStudent Details: ";
    while(!file.eof())
    {
        cout<<"\nRoll No: "<<stud.rn<<"\nName: "<<stud.name<<"\nDivision: "<<stud.division<<"\nAddress: "<<stud.adr;
        cout<<"\nDoB: "<<stud.dob.day<<"/"<<stud.dob.month<<"/"<<stud.dob.year;
        cout<<"\nPercentage: "<<stud.percent<<"%\nGrade: "<<stud.grade;
        cout<<endl;
        file.read((char*)&stud,(sizeof(stud)));
    }
    file.close();
}

//Function to add a StudRecord in the file 
void seqfile :: add()
{
    cout<<"\nEnter new Student Details:";
    cout<<"\nRoll Number : ";
    cin>>stud.rn;
    cout<<"\nName : ";
    cin>>stud.name;
    cout<<"\nDivision: ";
    cin>>stud.division;
    cout<<"\nAddress: ";
    cin>>stud.adr;
    cout<<"\nDate of Birth (dd mm yyyy): ";
    cin>>stud.dob.day>>stud.dob.month>>stud.dob.year;
    cout<<"\nPercentage: ";
    cin>>stud.percent;
    cout<<"\nGrade: ";
    cin>>stud.grade;
    
    file.open("StudRecord.txt",ios::app);
    file.write((char*)&stud,(sizeof(stud)));
    file.close();
}

//Function to search and display a StudRecord from file
void seqfile :: search(int key)
{
    int flag = 0;
    file.open("StudRecord.txt",ios::in);
    file.read((char *)&stud,sizeof(stud));
    while(!file.eof())
    {
        if(stud.rn==key)
        {
            cout<<"\nStudent details found:\n";
            flag = 1;
            cout<<"\nRoll No: "<<stud.rn<<"\nName: "<<stud.name<<"\nDivision: "<<stud.division<<"\nadr: "<<stud.adr;
            cout<<"\nDoB: "<<stud.dob.day<<"/"<<stud.dob.month<<"/"<<stud.dob.year;
            cout<<"\nPercentage: "<<stud.percent<<"%\nGrade: "<<stud.grade;
            cout<<"\n";
            break;
        }
	file.read((char *)&stud,sizeof(stud));
    }
    if(flag==0)
    {
        cout<<"\nStudent Record not found!!";
    }
    file.close();
}

//Function to modify a StudRecord
void seqfile :: modify(int key)
{
    int flag = 0;
    file.open("StudRecord.txt",ios::in);
    temp.open("Temp.txt",ios::out);
    file.read((char*)&stud,sizeof(stud));
    while(!file.eof())
    {
        //file.read((char*)&stud,sizeof(stud));
        if (stud.rn == key)
        {
            flag = 1;
            cout<<"\nEnter updated Details:";
            cout<<"\nRoll Number : ";
            cin>>stud.rn;
            cout<<"\nName : ";
            cin>>stud.name;
            cout<<"\nDivision: ";
            cin>>stud.division;
            cout<<"\nAddress: ";
            cin>>stud.adr;
            cout<<"\nDate of Birth (dd mm yyyy): ";
            cin>>stud.dob.day>>stud.dob.month>>stud.dob.year;
            cout<<"\nPercentage: ";
            cin>>stud.percent;
            cout<<"\nGrade: ";
            cin>>stud.grade;
            
            temp.write((char *)&stud,sizeof(stud));
            file.read((char*)&stud,sizeof(stud));
        }
        else
        {
            temp.write((char *)&stud,sizeof(stud));
            file.read((char*)&stud,sizeof(stud));
        }
    }
    if(flag==0)
    {
        cout<<"\nStudent Record not found";
    }
    else
    {
        cout<<"\nThe Record with the Roll No. "<<key<<" has been modified ";
    }
    file.close();
    temp.close();
    remove("StudRecord.txt");
    rename("Temp.txt","StudRecord.txt");
}

//Function to delete a StudRecord
void seqfile :: Delete(int key)
{
    int flag = 0;
    file.open("StudRecord.txt",ios::in);
    temp.open("Temp.txt",ios::out);
    file.read((char *)&stud,sizeof(stud));
    while(!file.eof())
    {
        flag = 1;
        if (stud.rn != key)
        {
            temp.write((char *)&stud,sizeof(stud));
        }
	file.read((char *)&stud,sizeof(stud));
    }
    if(flag==0)
    {
        cout<<"\nStudent Record not found!!";
    }
    else
    {
        cout<<"\nThe Record with the Roll No. "<<key<<" has been deleted ";
    }
    file.close();
    temp.close();
    remove("StudRecord.txt");
    rename("Temp.txt","StudRecord.txt");
}

int main()
{
    int key, choice;
    student stud;
    seqfile S;
    S.create();
    
    do
    {
        cout<<"***************************";
        cout<<"\n1) Display the file";
        cout<<"\n2) Add record";
        cout<<"\n3) Search record";
        cout<<"\n4) Modify record";
        cout<<"\n5) Delete record";
        cout<<"\n6) Exit";
        cout<<"***************************"<<endl;
        
        cout<<"\nEnter choice of operation: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            {
                S.display();
                break;
            }
            case 2:
            {
                S.add();
                break;
            }
            case 3:
            {
                cout<<"\nEnter the Roll No of Student to be searched: ";
                cin>>key;
                S.search(key);
                break;
            }
            case 4:
            {
                cout<<"\nEnter the Roll No of Student to be modified: ";
                cin>>key;
                S.modify(key);
                break;
            }
            case 5:
            {
                cout<<"\nEnter the Roll No of Student to be deleted: ";
                cin>>key;
                S.Delete(key);
                break;
            }
            case 6:
            {
                cout<<"Done!!";
                break;
            }
        }
        cout<<"\n\n";
        
    } while(choice != 6);
    
    return 0;
}
