#include <stdio.h>

int main(void)
{
  printf("Hello, world!\n");
  int i=0x12345678;
  long k=i*i;
  printf("%d\n",i);
  printf("%ld\n",k);
  char a[5]="hello";
  printf("%s",a);
}
