// Implementation of Destructors

#include<iostream>
using namespace std;

int count = 0;
class test
{
    public:
        test()
        {
            count++;
            cout<<"\n\nConstructor Msg: Object No: "<<count<<" created.";
        }
        ~test()
        {
            cout<<"\n\nDestructor Msg: Object No: "<<count<<" created.";
            count--;
        }
};

int main ()
{
    test T1;
    {
        test T2 ,T3;
    }
    return 0;
}