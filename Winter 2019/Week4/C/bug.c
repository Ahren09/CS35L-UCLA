#include <stdio.h>
#define MAXARRAY 10000
int a[MAXARRAY];


int main(void)
{
	int i = 0, k = 0;
	scanf("%d",&k);

	for (i = 1; i < k; i++)
	{
		a[i] = a[i-1] + i; 
		printf("%d\n", a[i]); 		
	}

	return 0;
}
