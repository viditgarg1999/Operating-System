//  Program executed as a Sigle thread of execution

#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main()
{
	double time_spent = 0.0;
	clock_t begin = clock();

	long p = 0;
	for(int i=0;i<100000;i++)
	{
		p =i; 		//  Perforing a very baisc operation
	}

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time taken by the main process is: %f\n", time_spent);
	return 0;
}
