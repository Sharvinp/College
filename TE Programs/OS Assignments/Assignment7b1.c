/*
Problem Statement:
Assignment No. 7: Inter process communication in Linux using following.
(b) FIFOs: Full duplex communication between two independent processes. First process accepts sentences and writes on one pipe to be read by second process and second process counts number of characters, number of words and number of lines in accepted sentences, writes this
output in a text file and writes the contents of the file on second pipe to be read by first process and displays on standard output.

*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int fd1,fd2,i=0;
	char buff[1024],op[1024],ch;
	char myfifo1[20]="myfifo1";
	char myfifo2[20]="myfifo2";
	mkfifo(myfifo1, 0666);
	mkfifo(myfifo2, 0666);

	char c;
	
	printf("Enter the sentences:");
	while((ch=fgetc(stdin))!=EOF)
	{
	buff[i++]=ch;
	}
	//fgets(buff, sizeof(buff), stdin);

	fd1=open(myfifo1, O_WRONLY);	
	write(fd1,buff,strlen(buff)+1);
	close(fd1);
	printf("Data sent to server for processing.\n");

	printf("\n");
	printf("Press any key after server execution...\n");
	scanf("%c",&c);
	
	fd2=open(myfifo2, O_RDONLY);	
	read(fd2,op,sizeof(op));
	close(fd2);
	printf("***RESULT***\n%s",op);

	return 1;
}


/******OUTPUT******/
/*

Data sent to server for processing.

Press any key after server execution...
a
***RESULT***
Char count:10
Word count:2
Line count:2
*/
