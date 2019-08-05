// Program to executed with multiple prcess(parent-child concept)

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	double time_spent = 0.0;
	int status;
	clock_t begin = clock();

	int rel = fork();

	if(rel == 0)
	{
		long p =0;
		for(int i=0;i<100000;i++)
		{
			p = i;
		}
		clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Time taken by  child process with pid %d is %f seconds \n",getpid(), time_spent);
	}

	else if(rel >0)
	{
		wait(&status);
	        clock_t end = clock();
	        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
       		printf("Time taken by the patent process with pid %d is %f seconds \n",getpid(), time_spent);
	}
	else
	{
		printf("Bad Fork\n");
		exit(1);
	}
	return 0;
}
