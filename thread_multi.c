#include<stdio.h>
#include<pthread.h>

void *print_id (void *id)
{
	int *tid = id;
	printf("Thread is %d \n ",*tid);
}

int main()
{
	pthread_t threads[3];
	int i;
	printf("Main Process\n");
	for(i=0;i<3;i++)
	{
		pthread_create(&threads[i],NULL, print_id,&i);

	}

//	pthread_join(threads[2],NULL);
			
	pthread_exit(NULL);
	return 0;
}
