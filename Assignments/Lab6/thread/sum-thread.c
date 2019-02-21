#include <stdio.h>
#include <stdlib.h>

#define MAX_ITERATION 40000000000
#define NUM_OF_THREAD 4

long sum = 0;

void add_to_sum(void)
{
	long i = 0;
	unsigned long tmp = 0;
	for (i = 0; i < MAX_ITERATION/NUM_OF_THREAD; i++)
	tmp++;

	sum += tmp;
}

void * thread_routine(void * dummy)
{
	add_to_sum();
}

pthread_t thread_id[NUM_OF_THREAD - 1];

int main(void)
{
	int i = 0;
	for (i = 0; i < NUM_OF_THREAD - 1; i++)
		pthread_create(&thread_id[i], NULL, thread_routine, NULL);

	add_to_sum();

	for (i = 0; i < NUM_OF_THREAD - 1; i++)
		pthread_join(thread_id[i], NULL);

	printf("Sum is %ld\n", sum);
	return 0;
}
