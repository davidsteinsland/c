#include <stdio.h>

/**
 * Prints the words given in the args array
 */
int main (int argc, char *args[])
{
	// as long as *args isn't a nullbyte
	while ( *args )
	{
		char *p = *args; 
		// as long as *p isn't a nullbyte
		while (*p)
		{
			// print the character representation of *p
			printf ("%c", *p++);
		}
		// increase the address (index) by one,
		// and print a newline
		args++;
		printf ("\n");
	}
}
