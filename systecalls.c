// Program using I/O System calls

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd;
	/* Open and creating the file in Write mode only */

	fd = open("temp.txt", O_CREAT | O_WRONLY, 0600);
	if(fd==-1)
	{
		printf("Failed to Open and Create the file.\n");
		exit(0);
	}

	/* Writing the file */

	write(fd, "Hello World\n", 12);

	close(fd);

	/* Reading the file */

	fd = open("temp.txt", O_RDONLY, 0600);
	if(fd == -1)
	{
		printf("Failed to Open and Read the file.\n");
		exit(0);
	}
	char buffer[13];
	read(fd, buffer, 12);
	buffer[13] = '\0';
	close(fd);
	printf("Content: %s\n",buffer);
	return 0;
}
