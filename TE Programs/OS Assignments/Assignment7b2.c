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
	int fd1,fd2;
	char buff[1024],op[1024];
	char myfifo1[20]="myfifo1";
	char myfifo2[20]="myfifo2";
	mkfifo(myfifo1, 0666);
	mkfifo(myfifo2, 0666);

	int char_count=0,word_count=0,line_count=0;
	int len,i,n=0;
	char c;

	fd1=open(myfifo1, O_RDONLY);
	read(fd1,buff,sizeof(buff));
	close(fd1);
	printf("Data read from FIFO.\n");
	
	len=strlen(buff);
	
	//Calculating  no of characters
	for(i=0;i<len;i++)
	{
		if((buff[i]>='a' && buff[i]<='z') || (buff[i]>='A' && buff[i]<='Z'))
			char_count+=1;
	}

	//Calculating no of words
	for(i=0;i<len;i++)
	{
		if((buff[i]!=' ' && buff[i+1]==' ') || (buff[i]!=' ' && buff[i+1]=='\n' ))
			word_count+=1;
	}

	//Calculating no of lines
	for(i=0;i<len;i++)
	{
		if(buff[i]=='\n')
			line_count+=1;
	}
	
	FILE* fp;
	fp=fopen("opfile.txt","w");
	fprintf(fp,"Char count:%d\n",char_count);
	fprintf(fp,"Word count:%d\n",word_count);
	fprintf(fp,"Line count:%d\n",line_count);
	fclose(fp);
	
	fp=fopen("opfile.txt","r");
	while((c=fgetc(fp)) != EOF)
		op[n++]=c;
			
	op[n]='\0';
	fclose(fp);

	fd2=open(myfifo2, O_WRONLY);	
	write(fd2,op,strlen(op)+1);
	close(fd2);
	
	printf("Data sent to client.\n");
	
	return 1;
}
/************OUTPUT******/
/*

Data read from FIFO.
Data sent to client.

*/















