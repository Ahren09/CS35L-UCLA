
#include <pthread.h>
#include <stdio.h>

#define NUM_ELEMENTS 4000000000
#define NUM_THREADS 4
int a[NUM_ELEMENTS];

pthread_t th[NUM_THREADS-1];

void* t(void* arg)
{
  int thread_num=(int)arg;
  int i=0;
  int step=NUM_ELEMENTS/NUM_THREADS;
  int start=step*thread_num;
  int end=start+step;
}
int main(void)
{
  int i;
  for(i=0;i<NUM_THREADS-1;i++)
    pthread_create(&th[i],NULL,t,(void *) i);
  
  t((void*)0);
  for(i=0;i<NUM_THREADS-1;i++)
    pthread_join(th[i],NULL);

}
