#include <iostream>
using namespace std;
class sort
{ protected:
 int i, j, temp;
 public:
 void bubble(int arr[], int n)
 { for(i=0; i<=n-1; i++)
 { for(j=0; j<=n-2-i; j++)
 { if (arr[j]>arr[j+1])
 { temp = arr[j];
 arr[j] = arr[j+1];
 arr[j+1] = temp;
 }
 }
 }
 }
};
class sets : public sort
{ protected:
 int i, j, k, flag, c[30];
 public:
 void setunion(int[], int[], int, int);
 void setintersection(int[], int[], int, int);
 void setsymdiff(int[], int[], int, int);
};
void sets :: setunion(int a[], int b[], int len1, int len2)
{ 
 k = 0;
 for(i=0; i<len1; i++)
 { c[k] = a[i];
 k++;
 }
 for (i=0; i<len2; i++)
 { flag = 1;
 for(j=0; j<len1; j++)
 { if(b[i] == a[j])
 { flag = 0;
 break;
 }
 }
 if (flag == 1)
 { c[k] = b[i];
 k++;
 }
 }
 bubble(c, k);
 cout<<"Union:"<<endl;
 if(k==0)
 cout<<"Null set";
 for(i=0; i<k; i++)
 { cout<<c[i]<<" ";
 }
}
void sets :: setintersection(int a[], int b[], int len1, int len2)
{ 
 k = 0;
 for (i=0; i<len1; i++)
 { for(j=0; j<len2; j++)
 { if(b[j] == a[i])
 { c[k] = b[j];
 k++;
 }
 }
 }
 bubble(c, k);
 cout<<"Intersection:"<<endl;
 if(k==0)
 cout<<"Null set";
 for(i=0; i<k; i++)
 { cout<<c[i]<<" ";
 }
}
void sets :: setsymdiff(int a[], int b[], int len1, int len2)
{ 
 k = 0;
 for (i=0; i<len1; i++)
 { flag = 1;
 for(j=0; j<len2; j++)
 { if(a[i] == b[j])
 { flag = 0;
 break;
 }
 }
 if (flag == 1)
 { c[k] = a[i];
 k++;
 }
 }
 for (i=0; i<len2; i++)
 { flag = 1;
 for(j=0; j<len1; j++)
 { if(b[i] == a[j])
 { flag = 0;
 break;
 }
 }
 if (flag == 1)
 { c[k] = b[i];
 k++;
 }
 }
 bubble(c, k);
 cout<<"Symmetric Difference:"<<endl;
 if(k==0)
 cout<<"Null set";
 for(i=0; i<k; i++)
 { cout<<c[i]<<" ";
 }
}
int main()
{ int choice, i, j, k, x[30], y[30], n, m;
 char t;
 sets S;
 cout<<"Enter number of elements in first array: ";
 cin>>n;
 cout<<"Enter first array: "<<endl;
 i = 0;
 for(i=0; i<m; i++)
 { cout<<"Enter element at position "<<i<<": ";
 cin>>y[i];
 if(i>2)
 { for(j=0; j<i; j++)
 { if(y[j] != y[i])
 { continue;
 }
 else
 { cout<<"Same elements are not allowed!"<<endl;
 i--;
 }
 }
 }
 }
 cout<<"Enter number of elements in second array: ";
 cin>>m;
 cout<<"Enter second array: "<<endl;
 for(i=0; i<m; i++)
 { cout<<"Enter element at position "<<i<<": ";
 cin>>y[i];
 if(i>2)
 { for(j=0; j<i; j++)
 { if(y[j] != y[i])
 { continue;
 }
 else
 { cout<<"Same elements are not allowed!"<<endl;
 i--;
 }
 }
 }
 }
 do
 { cout<<"\nChoose operation: 1-Union, 2-Intersection, 3-Symmetric Difference"<<endl;
 cin>>choice;
 switch(choice)
 { case 1: 
 S.setunion(x,y,n,m);
 break;
 case 2:
 S.setintersection(x,y,n,m);
 break;
 case 3:
 S.setsymdiff(x,y,n,m);
 break;
 }
 cout<<"\nDo you want to continue: y/n "<<endl;
 cin>>t;
 } while(t == 'y');
 return 0;
}
