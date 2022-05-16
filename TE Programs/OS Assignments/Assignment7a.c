/*

Assignment No. 7: 

Inter process communication in Linux using following.

a. Pipes: Full duplex communication between parent and child processes. Parent process writes a
pathname of a file (the contents of the file are desired) on one pipe to be read by child process
and child process writes the contents of the file on second pipe to be read by parent process and
displays on standard output.

*/



#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{	
	int p[2],c[2],ret,ret1;
	char filepath[100];
	char ch;
	pid_t pid;
	FILE *fp;
	ret=pipe(p);
	ret1=pipe(c);
	if(ret==-1 || ret1==-1)
	{	
		printf("Error");
		return 0;
	}
	pid = fork();
	if(pid==0)
	{	
		close(p[0]);  
	   	printf("\nEnter File Name : ");
		scanf("%s",filepath);		
		write(p[1],filepath,strlen(filepath)+1);		
		while(read(c[0],&ch,1)>0) 
		{
			printf("\nParent : %c",ch);
		}
	}
	else if (pid > 0)
	{	
		read(p[0],filepath,sizeof(filepath));		
		fp = fopen(filepath , "r");
		if(fp == NULL)
		{
			perror("Error Opening the File ");			
		}
		while( !feof (fp) )
		{
			ch=fgetc(fp);
			write(c[1],&ch,1);
			sleep(1);
		}
		fclose(fp);
	}
	return 0;
}



/*

Output:



Enter File Name : assign7a.txt

Parent : P
Parent : V
Parent : G
Parent :  
Parent : C
Parent : O
Parent : E
Parent : T
Parent : 



*/
