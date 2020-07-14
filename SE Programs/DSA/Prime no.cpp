//Write a program to display first 'n' prime numbers.
#include<iostream>

using namespace std;

int main()
{
    int n, i, j, temp;
    cout<<"ENter a number: ";
    cin>>n;
    for(i = 2; i<=n; i++)
    {
        temp = 0;
        for(j = 2; j<i; j++)
            {
                if (i%j == 0)
                {
                    temp = 1;
                        break;
                }
                
            }
            if (temp == 0)
            {
                cout<<i<<" ";
            }
    }
    return 0;        
            
}
