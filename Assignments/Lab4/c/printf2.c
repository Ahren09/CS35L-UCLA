#include <stdio.h>
long a[10];
int main(void)
{
	int i = 0;
	for (i = 0; i < 10; i++) a[i] = i * i;
	for (i = 0; i < 10; i++)
		printf("value of a[%d] is %ld\n", i, a[i]);
}
