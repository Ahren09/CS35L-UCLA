#include <stdio.h>
#include <stdlib.h>

int foo(void)
{
	printf("inside foo!\n");
}

void bar(void)
{
	printf("inside bar!\n");
}


int main(void)
{
	int i = 0;
	foo();
	bar();

	for (i = 0; i < 10; i++)
	{
		printf("i is %d\n", i);
	}
}
