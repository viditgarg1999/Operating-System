// Program to create orphan process

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Before forking:\n");
	printf("I am the parent process with pid = %d\n",getpid());

	int p = fork();
	printf("After forking: \n");

	if(p==0)
	{
		sleep(2);  // TO ensure that parent process terminates before child process
		printf("I am the child process with pid = %d and ppid= %d",getpid(), getppid()); 
	}

	else if(p>0)
	{
		printf("I am the parent process\n");
		printf("Parent process terminates before child process.\n");
	}

	return 0;
}
