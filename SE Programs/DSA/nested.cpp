//Write a program to generate following output using 2 nested for loops
#include<iostream>

using namespace std;

int main()
{
    int i, j;
    for (i=0; i<=1; i++)
    {   for (j=1; j<=3; j++)
        {
            cout<<i<<" "<<j;
            cout<<"\n";
        }
    }
    return 0;
    
}
