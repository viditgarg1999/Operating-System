// Program to create a process

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Hello World! I am the main process");
	printf("\n My process id is %d",getpid());
	return 0;
}



