/*

Assignment No. 9: 

Implement an assignment using File Handling System Calls (Low level system calls like
open, read, write, etc).

*/



#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct entry
{
	char name[20];
	char num[13];
}entry;

entry data;
char bf[31];

void insert()
{
	int file_id,i;
	file_id = open("test.txt", O_RDWR|O_APPEND|O_CREAT,0777);
	printf("Enter the name\n");
	scanf("%s", data.name);
	printf("Enter the phone number\n");
	scanf("%s", data.num);
	for(i=0;i<30;i++)
	{
		if(i<strlen(data.name))
			bf[i] = data.name[i];
		else if(i<20)
			bf[i] = '.';
		else
			bf[i] = data.num[i-20];
	}
	//bf[i] = '\0';
	printf("Entering data %s\n", bf);
	write(file_id,bf,sizeof(bf));
	close(file_id);
}

void display()
{
	int file_id;
	file_id = open("test.txt", O_RDWR);
	printf("The Address Book:\n");
	if(!read(file_id,bf,sizeof(bf)))
			printf("No entries to display\n");
	else
	{
		printf("Name\t\t Phone Number\n");
		do
		{
			printf("%s\n", bf);									
		}while(read(file_id,bf,sizeof(bf)));
	}
	close(file_id);
}

int search()
{
	int file_id,i,flag = 1;
	file_id = open("test.txt", O_RDWR);
	char name[20];
	printf("The Address Book:\n");
	if(!read(file_id,bf,sizeof(bf)))
			printf("No entries present\n");
	else
	{
		printf("Enter the name to search\n");
		scanf("%s", name);
		do
		{
				flag = 1;
				for(i=0;i<strlen(name);i++)
				{
					if(name[i] != bf[i])
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					printf("Record found!\n %s\n", bf);
					break;
				}
		}while(read(file_id,bf,sizeof(bf)));
		if(flag == 0)
			printf("Record not found. Check if the name entered was correct");
	}
	close(file_id);
}

void modify()
{
	int ch;
	int file_id,i,flag = 1;
	file_id = open("test.txt", O_RDWR,0777);
	char name[20];
	printf("The Address Book:\n");
	if(!read(file_id,bf,sizeof(bf)))
			printf("No entries present\n");
	else
	{
		printf("Enter the name to search\n");
		scanf("%s", name);
		do
		{
				flag = 1;
				for(i=0;i<strlen(name);i++)
				{
					if(name[i] != bf[i])
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					printf("Record found!\n %s\n", bf);
					printf("Enter your choice to change field\n");
					printf("1: Name\n");
					printf("2: Number\n");
					printf("0: Exit\n");
					scanf("%d", &ch);
					switch(ch)
					{
						case 1:
										printf("Enter the name\n");
										scanf("%s", data.name);
										lseek(file_id, -sizeof(bf), SEEK_CUR);
										for(i=0;i<20;i++)
										{
											if(i<strlen(data.name))
												bf[i] = data.name[i];
											else
												bf[i] = '.';
										}
										write(file_id,bf,sizeof(bf));
										printf("Modifications made\n");
										break;
						case 2:
										printf("Enter the number\n");
										scanf("%s", data.num);
										lseek(file_id, -sizeof(bf),SEEK_CUR);
										for(i=20;i<30;i++)
												bf[i] = data.num[i-20];
										write(file_id,bf,sizeof(bf));
										printf("Modifications made\n");
										break;
						case 0: printf("No modifications made\n");
										break;
						default:
										printf("Wrong input\n");
					}
					break;
				}
		}while(read(file_id,bf,sizeof(bf)));
		if(flag == 0)
			printf("Record not found. Check if the name entered was correct");
	}
}


void deletion()
{
	int file_id,file_id2,i,flag = 1;
	file_id = open("test.txt", O_RDWR,0777);
	file_id2 = open("test2.txt", O_CREAT,0777);
	close(file_id2);		//creates the file
	file_id2 = open("test2.txt", O_RDWR|O_APPEND,0777);
	char name[20];
	printf("The Address Book:\n");
	if(!read(file_id,bf,sizeof(bf)))
			printf("No entries present\n");
	else
	{
		printf("Enter the name to search\n");
		scanf("%s", name);
		do
		{
				flag = 1;
				for(i=0;i<strlen(name);i++)
				{
					if(name[i] != bf[i])
					{
						flag = 0;
						break;
					}
					//else 
					//{
						printf("Data not found");
					//}

				}
				if(flag != 1)
				{
					write(file_id2,bf,sizeof(bf));
				}
				else
					printf("Entry deleted\n");
		}while(read(file_id,bf,sizeof(bf)));
	}
	remove("test.txt");
	rename("test2.txt", "test.txt");
	close(file_id2);
}
int main()
{
	int ch,val;
	do
	{
		printf("Welcome to your Phone Book\n");
		printf("Choose your option\n");
		printf("1: Insert a new entry\n");
		printf("2: Display all entries\n");
		printf("3: Search an entry\n");
		printf("4: Update an entry\n");
		printf("5: Delete an entry\n");
		printf("0: Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: 
							insert();
							break;
			case 2:
							display();
							break;
			case 3:
							search();		
							break;
			case 4:
							modify();
							break;
			case 5: 
							deletion();
							break;
			case 0:
							printf("Byeee\n");
							break;
			default:
							printf("Wrong INPUT\n");
		}
	}while(ch!=0);
	exit(0);
}



/*

OUTPUT:



Welcome to your Phone Book
Choose your option
1: Insert a new entry
2: Display all entries
3: Search an entry
4: Update an entry
5: Delete an entry
0: Exit
1
Enter the name
Manali
Enter the phone number
9876543210
Entering data Manali..............9876543210
Welcome to your Phone Book
Choose your option
1: Insert a new entry
2: Display all entries
3: Search an entry
4: Update an entry
5: Delete an entry
0: Exit
1
Enter the name
Apoorva
Enter the phone number
9867452310
Entering data Apoorva.............9867452310
Welcome to your Phone Book
Choose your option
1: Insert a new entry
2: Display all entries
3: Search an entry
4: Update an entry
5: Delete an entry
0: Exit
2
The Address Book:
Name		 Phone Number
Manali..............9876543210
Apoorva.............9867452310
Welcome to your Phone Book
Choose your option
1: Insert a new entry
2: Display all entries
3: Search an entry
4: Update an entry
5: Delete an entry
0: Exit
3
The Address Book:
Enter the name to search
Manali
Record found!
 Manali..............9876543210
Welcome to your Phone Book
Choose your option
1: Insert a new entry
2: Display all entries
3: Search an entry
4: Update an entry
5: Delete an entry
0: Exit
4
The Address Book:
Enter the name to search
Apoorva
Record found!
 Apoorva.............9867452310
Enter your choice to change field
1: Name
2: Number
0: Exit
2
Enter the number
9182736450
Modifications made
Welcome to your Phone Book
Choose your option
1: Insert a new entry
2: Display all entries
3: Search an entry
4: Update an entry
5: Delete an entry
0: Exit
2
The Address Book:
Name		 Phone Number
Manali..............9876543210
Apoorva.............9182736450
Welcome to your Phone Book
Choose your option
1: Insert a new entry
2: Display all entries
3: Search an entry
4: Update an entry
5: Delete an entry
0: Exit
0
Byeee



*/
