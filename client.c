#include <sys/shm.h>
#include <stdio.h>
#define SHMSZ 27
int main()
{
	int shmid;
	key_t key;
	char *shm,*s;
	key = 5678;

	/* Locate the segment. */
	if ((shmid = shmget(key, SHMSZ,	0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}

	/* * Now we attach the segment to our dataspace. */

	 if ((shm = shmat(shmid, NULL, 0))== (char *) -1)
	{
		perror("shmat");
		exit(1);
	}

	/* Now read what the server put in the memory. */
	for (s = shm; *s != NULL; s++)
	{
		putchar(*s);
		putchar(‘\n’);
	}
	/* Finally, change the segment to 'A…Z', indicating we have read the segment. */
	int i;
	for (i=65;i<91;i++)
	{
		*shm=(char)i;
		shm++;
	}
	return 0;
}
