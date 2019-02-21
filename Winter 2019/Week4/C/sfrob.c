#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int frobChar(char const a)
{
	return (a^42);
}

int frobcmp(char const *a, char const *b)
{
	while(*a!=' ' && *b!=' ')
	{
		if(*b==' ' || frob(*a) > frob (*b))
			return 1;
		else if(*a==' ' || frob(*b) > frob (*a))
                        return -1;
		a++;
		b++;

	} 
	return 0;

}

void checkIO()
{
	if(ferror(stdin))
	{	fprintf(stderr,"Error: Bad stdin");
		exit(1);
	}

}


int main()
{
	char *word=(char*)malloc(sizeof(char));
	char **words=(char**)malloc(sizeof(char*));

	if(word == NULL || words == NULL)
	{
		fprintf(stderr,"Error: Bad memory allocation");
		exit(1);
	}

	
}

