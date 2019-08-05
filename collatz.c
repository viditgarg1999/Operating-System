// Collatz conjecture

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void collatz(int k)
{
	int n=k;
	while(n!=1)
	{
		if(n%2==0)
			n=n/2;
		else
			n=n*3 +1;
		printf("%d \t",n);
	}
	printf("\n");
}

int main()
{
	int n, status;
	printf("Main process with pid = %d\n",getpid());
	printf("Enter the number: \n");
	scanf("%d",&n);
	if(n>0)
	{
		int p = fork();
		if(p==0)
		{
			printf("Child Process! Task in progress.. \n");
			collatz(n);
			printf("Task completed! Child process terminates.\n");
		}
		else if(p>0)
		{	wait(&status);
			printf("Parent process terminates\n");
		}
	}
	else
		printf("Invalid Input! Please enter a number greater than 0.\n");

	return 0;
}
