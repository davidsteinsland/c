#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	// *(argv + n) ==  *(&argv[0 + n]) == argv[n]
	
	if ( argc < 2 )
	{
		printf ("Usage: %s <number of iterations>\n", argv[0]);
		exit (1);
	}
	
	printf ( "%s\n", argv[1] );

	return 0;
}
