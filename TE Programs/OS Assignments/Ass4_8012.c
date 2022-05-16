/*

Name:Siddharth Bondarde
Class:TE-IT
R.No:8012

Assignment No. 4: 

Thread synchronization using counting semaphores. Application to demonstrate:
producer-consumer problem with counting semaphores and mutex.

*/



#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

sem_t mutex,full,empty;
int buffer[5],front=0,rear=0,count=1;

void *producer(void *p);
void *consumer(void *p);

int main(int argc,char *argv[])
{
	int ch,i;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	do
	{
		pthread_t tid_p[3];
		pthread_attr_t attr_p;
		pthread_attr_init(&attr_p);
		for(i=0;i<3;i++)
		{   
			void *p=i;
			pthread_create(&tid_p[i],&attr_p,producer,p);
			pthread_join(tid_p[i],NULL);
		}
		pthread_t tid_c[3];
		pthread_attr_t attr_c;
		pthread_attr_init(&attr_c);
		for(i=0;i<3;i++)
		{          
			void *c=i;
			pthread_create(&tid_c[i],&attr_c,consumer,c);
			pthread_join(tid_c[i],NULL);
		}    
		printf("\n");
		for(i=0;i<5;i++)
		{
			printf("\t %d",buffer[i]);
		}
	}
	while(1);
}

void *producer(void *p)
{
	int t=p;
	printf("\n Producer %d Start",t);
	sem_wait(&empty);
	sem_wait(&mutex);
	buffer[rear]=count;
	printf("\t  Produced Element: %d ",buffer[rear]);
	rear=(rear+1)%5;
	count++;
	sem_post(&mutex);
	sem_post(&full);
	printf("\n Producer End");
	sleep(4);
	pthread_exit(0);
}

void *consumer(void *p)
{
	int t=p;
	printf("\n Consumer %d Start",t);
	sem_wait(&full);
	sem_wait(&mutex);
	printf("\t  Consumed Element: %d ",buffer[front]);
	buffer[front]=0;
	front=(front+1)%5;
	sem_post(&mutex); 
	sem_post(&empty);
	printf("\n Consumer End");
	sleep(2);
	pthread_exit(0);
}



/*

Output:




 Producer 0 Start	  Produced Element: 1 
 Producer End
 Producer 1 Start	  Produced Element: 2 
 Producer End
 Producer 2 Start	  Produced Element: 3 
 Producer End
 Consumer 0 Start	  Consumed Element: 1 
 Consumer End
 Consumer 1 Start	  Consumed Element: 2 
 Consumer End
 Consumer 2 Start	  Consumed Element: 3 
 Consumer End
	 0	 0	 0	 0	 0
 Producer 0 Start	  Produced Element: 4 
 Producer End
 Producer 1 Start	  Produced Element: 5 
 Producer End
 Producer 2 Start	  Produced Element: 6 
 Producer End
 Consumer 0 Start	  Consumed Element: 4 
 Consumer End
 Consumer 1 Start	  Consumed Element: 5 
 Consumer End
 Consumer 2 Start	  Consumed Element: 6 
 Consumer End
	 0	 0	 0	 0	 0
 Producer 0 Start	  Produced Element: 7 
 Producer End
 Producer 1 Start	  Produced Element: 8 
 Producer End
 Producer 2 Start	  Produced Element: 9 
 Producer End
 Consumer 0 Start	  Consumed Element: 7 
 Consumer End
 Consumer 1 Start	  Consumed Element: 8 
 Consumer End
 Consumer 2 Start	  Consumed Element: 9 
 Consumer End
	 0	 0	 0	 0	 0
 Producer 0 Start	  Produced Element: 10 
 Producer End
 Producer 1 Start	  Produced Element: 11 
 Producer End
 Producer 2 Start	  Produced Element: 12 
 Producer End
 Consumer 0 Start	  Consumed Element: 10 
 Consumer End
 Consumer 1 Start	  Consumed Element: 11 
 Consumer End
 Consumer 2 Start	  Consumed Element: 12 
 Consumer End
	 0	 0	 0	 0	 0
 Producer 0 Start	  Produced Element: 13 


*/
