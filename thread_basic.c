#include<stdio.h>
#include<pthread.h>

void *thread_function(void *value)
{
	int *num = value;
	printf("Hello this is the first thread and the value of num is %d\n",*num);

}


int main()
{
	pthread_t thread;
	int num;
	num=123;
	int rel;
	rel = pthread_create(&thread, NULL, thread_function, &num);

	printf("Hello this is the main process\n");		

	if(rel==0)
		printf("Successful thread creation\n");

	else
		printf("Unsuccessful thread creation\n");
	pthread_join(thread, NULL);

	return 0;
}
