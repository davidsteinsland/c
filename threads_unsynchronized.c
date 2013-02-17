#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g_ant = 0;

void *writeloop (void *arg)
{
	while (g_ant < 10)
	{
		g_ant++;
		usleep (rand() % 10);
		printf ("%d\n", g_ant);
	}

	exit(0);
}

int main ()
{
	pthread_t tid;
	pthread_create (&tid, NULL, writeloop, NULL);
	writeloop (NULL);
	pthread_join (tid, NULL);

	return 0;
}
