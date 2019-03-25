#include <stdlib.h>
#include <stdio.h>

static void init(void) __attribute__((constructor))
{
  fprintf(stderr, "In %s \n", __func__);
}

static void finalize(void) __attribute__((destructor))
{
  fprintf(stderr, "In %s \n", __func__);

}

int main(void)
{

  printf("Begin!");
  printf("End!");
  return 0;
}
