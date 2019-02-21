#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s string\n", argv[0]);
		return -1;
	}
	

	while (1)
	{
		printf("%d %s\n", i++, argv[1]);
	}

	return 0;
	
}
