#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 10
//const int ARRAYSIZE=10;
int a[ARRAYSIZE] = {1, 8, 7, 6, 2, 3, 5, 7, 3, 4};
int compare (const void *A, const void * B)
{
  return *(int *) A - *(int *) B;
}
int main(void)
{
	int i = 0;
	qsort(a, ARRAYSIZE , sizeof(int), compare);
	for (i = 0; i < ARRAYSIZE ; i++) 
	    printf("%d\n", a[i]);
	return 0;
} 
