/*
Name:Siddharth Bondarde
Class:TE-IT
R.No:8012

Assignment:5
*/


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/unistd.h>

int data=0;
pthread_mutex_t mutex;
sem_t wrt;
int readcount=0;

void *reader(void *rno)
{
  int rn=*(int *)rno;
  //printf("\nReader %d is arrived",rn);
  int limit=1;
  do
  {
    pthread_mutex_lock(&mutex);
    readcount++;
    if(readcount==1)
    {
      sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    
    printf("\nReader %d is reading %d",rn,data);
    
    pthread_mutex_lock(&mutex);
    readcount--;
    if(readcount==0)
    {
     sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);     
    sleep(2);
    limit++;
  }  while(limit<3);
}

void *writer(void *wno)
{
  int wn=*(int *)wno;
  int limit1;
  do
  {
   // printf("\nWriter %d is arrived",wn);
    sem_wait(&wrt);
    printf("\nWriter %d is Entering in critical section",wn);    
    data++; 
    printf("\nWriter %d is writing %d",wn,data);
    printf("\nWriter %d is Leaving from critical section",wn);
    sem_post(&wrt);
    sleep(2); 
    limit1++;
  } while(limit1<3); 
}

void main()
{
 pthread_t rd[3];
 pthread_t wr[3];
 char buff[20];
 int i;
 
 pthread_mutex_init(&mutex,NULL);
 sem_init(&wrt,0,1);
 
 
 for(i=0;i<3;i++)
 {
   pthread_create(&wr[i],NULL,writer,&i);
   pthread_create(&rd[i],NULL,reader,&i);
 }  
 
 for(i=0;i<3;i++)
 {
   pthread_join(wr[i],NULL);
   pthread_join(rd[i],NULL);
 }  
 
} 



/* OUTPUT:

Writer 1 is Entering in critical section
Writer 1 is writing 1
Writer 1 is Leaving from critical section
Reader 1 is reading 1
Reader 2 is reading 1
Reader 0 is reading 1
Writer 1 is Entering in critical section
Writer 1 is writing 2
Writer 1 is Leaving from critical section
Writer 2 is Entering in critical section
Writer 2 is writing 3
Writer 2 is Leaving from critical section
Reader 2 is reading 3
Reader 1 is reading 3
Reader 0 is reading 3
Writer 1 is Entering in critical section
Writer 1 is writing 4
Writer 1 is Leaving from critical section
Writer 1 is Entering in critical section
Writer 1 is writing 5
Writer 1 is Leaving from critical section
Writer 2 is Entering in critical section
Writer 2 is writing 6
Writer 2 is Leaving from critical section
Writer 1 is Entering in critical section
Writer 1 is writing 7
Writer 1 is Leaving from critical section
Writer 1 is Entering in critical section
Writer 1 is writing 8
Writer 1 is Leaving from critical section
Writer 2 is Entering in critical section
Writer 2 is writing 9

*/
