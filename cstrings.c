#include <stdio.h> /* printf() */

void toLowerCase (const char* s, char* output);
void copyString (const char *s, char *o, int length);

int main ()
{
	const char* name = "DAVID";
	char cased[6];
	toLowerCase (name, cased);
	
	printf ( "%s = %s\n", name, cased);
	char *o;
	copyString (name, o, 6);
	printf ("%s\n", o);
}

void copyString (const char *s, char *o, int length)
{
	o[length];

	while (*s)
	{
		*o++ = *s++;
	}
}

void toLowerCase (const char* s, char* output)
{
	// cannot modify a char literal.
	// We have to copy it to a char array
	int i = 0;
	while (*(s+i))
	{
		output[i] = *(s+i);

		if (output[i] >= 'A' && output[i] <= 'Z')
			output[i] += 32;
		i++;
	}
	// the null-byte has to be included also
	output[i] = '\0';
}
