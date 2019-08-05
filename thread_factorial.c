// Program to create a thread to find the factorial of a given number 

#include<stdio.h>
#include<pthread.h>

void * factorial(void * num)
{
	int * p = num;
	int k = *p;
	int factorial = 1;
	for(int i=2;i<=k;i++)
	{ 
		factorial = factorial  * i;
	}

	printf("Factorial of the given number is : %d\n",factorial);

}

int main()
{
	pthread_t thread;
	int n;
	printf("Enter the value of Natural Number: \n");
	scanf("%d",&n);
	pthread_create(&thread, NULL, factorial, &n);
	pthread_join(thread,NULL);

	return 0;

}
