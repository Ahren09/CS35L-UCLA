#include <stdio.h>
#include <stdlib.h>

long factor(int n);

int main(int argc, char * argv[])
{
	int n = atoi(argv[1]);
	long res = factor(n);

	printf("%ld\n", res);
	return 0;
}
