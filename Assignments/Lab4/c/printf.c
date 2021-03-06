#include <stdio.h>
int foo(int in)
{
  return in*in;
}

int main(void)
{
	int i = 0x12345678;
	long k = ( (long) i << 32) | i;
	char c = 'c';
	double d = 1.0/3;
	int (*pfoo)(int);
	pfoo=&foo;
	printf("%d\n", (*pfoo)(4));

	printf("%d\n", i); //305419896 
	printf("%x\n", i); //12345678	

	printf("%ld\n", k); //1311768465173141112
	printf("%lx\n", k); //1234567812345678

	printf("%c\n", c); //c
	printf("%d\n", c); //asc ii of c

	printf("%lf\n", d); //0.3333333
}
