//Program to create  Child Process

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Before Forking:\n");
	printf("Main process with pid = %d\n",getpid());

	int p = fork();
	printf("After Froking");
	if(p==0)
	{	printf("Child process with pid = %d and ppid = %d\n",getpid(),getppid());
		printf("Child process terminates\n");
	}
	else if(p>0)
	{	printf("Parent process with pid = %d\n", getpid());
		printf("Parent process terminates\n");
	}
	return 0;
}
