#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRINGSIZE 10
char * a, * b, * c;
int main(void)
{
	a = (char *) malloc(STRINGSIZE * sizeof(char));
	b = (char *) malloc(STRINGSIZE * sizeof(char));
	c = (char *) malloc(STRINGSIZE * sizeof(char));
	printf("ptr value of a: %p, b: %p, c: %p\n", a, b, c);
	strcpy(a, "hello");
	strcpy(b, a);
	c = a;
	printf("value of a: %s, b: %s, c: %s\n", a, b, c);
	printf("ptr value of a: %p, b: %p, c: %p\n", a, b, c);
}
