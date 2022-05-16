//ASSIGNMENT 2A
/*Implement the C program in which main program accepts the integers to be sorted. Main
program uses the FORK system call to create a new process called a child process. Parent process
sorts the integers using sorting algorithm and waits for child process using WAIT system call to
sort the integers using any sorting algorithm. Also demonstrate zombie and orphan states.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>	//Declaration of all necessary libraries

void quick(int arr[10],int u,int v)	//function for quick sort
{
	int i,j,p,temp;
	if(u<v)		//if lower limit is less than upper limit
	{
		p=u;
		i=u;
		j=v;
		while(i<j)	//while pointers of lower limit is less than that of upper limit
		{
			while(arr[i]<=arr[p] && i<v)	//move the lower limit pointer forward until a smaller element is found
				i++;
			while(arr[j]>arr[p])	//move the upper limit pointer backward until a larger element is found
				j--;
			if(i<j)		//for swapping larger and smaller elements encountered
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[p];
		arr[p]=arr[j];
		arr[j]=temp;
		quick(arr,u,v-1);	//recursive call quick() for elements before mid
		quick(arr,u+1,v);	//recursive call quick() for elements after mid
	}
	
}

void merge(int arr[],int u,int mid,int v)	//function for merge sort
{
	int i,j,k;
	int n1=mid-u+1;
	int n2=v-mid;
	int U[n1],V[n2];
	for (i = 0; i < n1; i++) 	//get all elements in U[] array
		U[i] = arr[u + i]; 
    	for (j = 0; j < n2; j++) 	//get all elements after mid in V[] array
    		V[j] = arr[mid + 1+ j]; 
	i=0;
	j=0;
	k=u;
	while (i < n1 && j < n2) //till limit
	{ 
		if (U[i] <= V[j]) 	//if the element is smaller then store respective array element in resultant array
		{ 
			arr[k] = U[i]; 
			i++; 
		} 
		else	 	//if the element is larger then store respective array element it in resultant array
		{ 
			arr[k] = V[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) 	//if elements from 1st group are yet to sort
	{ 
		arr[k] = U[i]; 
		i++;
		k++; 
	} 
	while (j < n2) 	//if elements from 2nd array is yet to sort
	{ 
		arr[k] = V[j]; 
		j++;
		k++; 
	} 
} 
	
void part(int arr[],int u,int v)		//function for dividing elements
{
	int mid;
	if(u<v)
	{
		mid=(u+v)/2;
		part(arr,u,mid);		//recursive call to part for elements before mid
		part(arr,mid+1,v);		//recursive call to part for elements after mid
		merge(arr,u,mid,v);	//call to merge() function
	}
}

int main()	//main function
{
	int ch,pid;
	int i,arr[10],n;
	printf("Enter number of elements:");	//take input of array
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	pid=fork();		//store fork() result in pid
	if(pid==0)	//child process initiated
	{
		quick(arr,0,n-1);
		printf("\nPID:%d\nPPID:%d\nQuick sort by child:\n",(int)getpid(),(int)getppid());
		for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
	}
	else if(pid>0)	//parent process initiated after 10 seconds
	{
		sleep(10);
		part(arr,0,n-1);
		printf("\nPID:%d\nPPID:%d\nMerge sort by parent:\n",(int)getpid(),(int)getppid());
		for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
	}
	return 0;
}


/*
***ZOMBIE***

Enter number of elements:5
Enter array elements:2 7 4 1 5

PID:4171
PPID:4170
Quick sort by child:
1	2	4	5	7	
PID:4170
PPID:3682
Merge sort by parent:
1	2	4	5	7	

***ORPHAN***

Enter number of elements:5
Enter array elements:0 4 7 1 9

PID:4456
PPID:4439
Merge sort by parent:
0	1	4	7	9	exam@lab2-ThinkCentre-M700:~/Documents/TE-7056$ 
PID:4459
PPID:929
Quick sort by child:
0	1	4	7	9	
PID:4459
PPID:929
Quick sort by child:
0	1	4	7	9	
PID:4459
PPID:929
Quick sort by child:
0	1	4	7	9	
PID:4459
PPID:929
Quick sort by child:
0	1	4	7	9	
*/
