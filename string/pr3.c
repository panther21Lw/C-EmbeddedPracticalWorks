#include <stdio.h>

#define MAXLEN	1000

char uppercase(int);

int main()
{
	char input[MAXLEN];
	char output[MAXLEN];
	int i;
	
	printf("Input a text... ");
	fgets(input, MAXLEN, stdin);
	
	for (i = 0; input[i] != '\0'; ++i)
	{
		output[i] = uppercase(input[i]);
	}
	output[i] = '\0';
	
	printf("Result is: %s\n", output);
	
	return 0;
}

char uppercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A');
	return c;
}


