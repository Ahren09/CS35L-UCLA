#include <stdio.h>
#include <stdlib.h>

const int SIZE=10;
int ARRAY[]={5,2,6,3,1,4,19,24,7,0};

int compare(const void* a, const void* b)
{
  return *(int*)a - *(int*)b;
}
int main()
{
  int i=0;
  qsort(ARRAY,SIZE,sizeof(int),compare);
  for (i = 0; i < SIZE; i++)
    printf("%d\n", ARRAY[i]);
  return 0;
}
