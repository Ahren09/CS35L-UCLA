#define NUM_OF_ELEMENTS 400000000
#define NUM_OF_THREAD 8

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a[NUM_OF_ELEMENTS];
void * thread_routine(void * arg)   
{
	long thread_num = (long) arg, i = 0; 
	long step= NUM_OF_ELEMENTS/NUM_OF_THREAD;
	long start = thread_num * step, end = start + step;
	for (i = start; i < end; i++) a[i]++;
}

pthread_t thread_id[NUM_OF_THREAD - 1];

int main(void)  
{
	long i = 0;
	for (i = 1; i < NUM_OF_THREAD; i++)
		pthread_create(&thread_id[i-1], NULL,thread_routine, (void *) i);

	thread_routine((void *) 0);
	for (i = 0; i < NUM_OF_THREAD - 1; i++)
		pthread_join(thread_id[i], NULL);
}

