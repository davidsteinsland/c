#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Swaps the contents of two
 * integer pointers
 */
void swap (int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

/**
 * Returns a new int pointer
 */
int* increase (int *a)
{
	int *b;
	b = (int*)malloc (sizeof (int*));
	*b = *a + 1;
	return b;
}

/**
 * Appends a string to another string,
 * storing the result in a pointer
 */
char* appendString (const char* string, const char* message)
{
	int length = strlen (string) + strlen (message);

	// allocate memory for output
	char *output;
	output = (char*) malloc ( length + 1);
	
	int i, j = 0;
	for (i = 0; i < strlen(string); i++)
	{
		output[j++] = string[i];
		//*(output + j++) = *(string + i);
	}

	for (i = 0; i < strlen (message); i++)
	{
		output[j++] = message[i];
		//i*(output + j++) = *(message + i);
	}
	
	output[j] = '\0';

	return output;
}

/**
 * Appends a string to another string,
 * storing the result in a given pointer.
 * When we want to modify a pointer, we need to get a 
 * pointer to that pointer (hence **output).
 */
void appendStringp (const char* input, char **output, const char *message)
{
	*output = appendString (input, message);
}

int main()
{
	int a = 5;
	int b = 10;
	
	printf ( "a = %d\tb = %d\n", a, b);

	swap (&a, &b);

	printf ( "a = %d\tb = %d\n", a, b );

	int *c;
	c = (int*)malloc(1 * sizeof(int));
	*c = 20;
	int *d = increase (c);

	printf ("c = %d\td = %d\n", *c, *d);
	
	// free d
	free(d);

	const char* name = "Github";
	const char* txt = ", is really cool!";
	char *msg = appendString (name, txt);

	printf ( "name = %s\n", &name[0]);
	printf ( "txt = %s\n", txt);
	printf ( "msg = %s\n", msg);

	char *msg2;
	appendStringp (name, &msg2, txt);
	printf ( "msg2 = %s\n", msg2);
	
	printf("\n");

	while ( *msg )
	{
		printf ("*msg = %c\tmsg =: %s\n", *msg, msg);
		msg++;
	}

	return 0;
}
