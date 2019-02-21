*** Results ***
time ./srt 1-test.ppm >1-test.ppm.tmp

real 0m41.863s
user 0m41.850s
sys  0m0.006s
mv 1-test.ppm.tmp 1-test.ppm
time ./srt 2-test.ppm >2-test.ppm.tmp

real 0m20.844s
user 0m41.540s
sys  0m0.004s
mv 2-test.ppm.tmp 2-test.ppm
time ./srt 4-test.ppm >4-test.ppm.tmp

real 0m11.461s
user 0m44.941s
sys  0m0.012s
mv 4-test.ppm.tmp 4-test.ppm
time ./srt 8-test.ppm >8-test.ppm.tmp

real 0m6.098s
user 0m47.263s
sys  0m0.006s
mv 8-test.ppm.tmp 8-test.ppm

I observe that the real time is approximately user time/number of threads
Additionally, user time slightly increases as I increase numebr of threads
This is the result of generating more threads.

************************
*** Things to Notice ***
************************

### 0
.tgz files can be untarred by
tar -xvzf srt.tgz

### 1

Something to notice in multi-threading

//WRONG version
for(i = 0; i < nthreads; i++)
    {
      if(pthread_create(&thread_id[i], NULL, func, i)
      {
          fprintf(stderr,"Error: Fail to create new thread");
          exit(1);
      }
}

//CORRECT version
int ID[nthreads];
for(i = 0; i < nthreads; i++)
    {
        ID[i]=i;
      if(pthread_create(&thread_id[i], NULL, func, &ID[i]))
      {
          fprintf(stderr,"Error: Fail to create new thread");
          exit(1);
      }
}

The key point is that since the function is multi-threaded,
we pass a pointer to an object as parameter into the func() function
Since all threads are running simultaneously, if the parameter is constantly 
modified, errors will occur.

### 2

We can declare global variables that can be accessed by several threads:

float*** ALL_SCALED_COLOR;
scene_t scene;

The ALL_SCALED_COLOR is used as a 3-D array of floats that stores the output,
which is modified by all threads at the same time
To enable all threads to use the scene_t object, we must declare it as a global
variable.

### 3
The dynamically allocated 3D array "ALL_SCALED_COLOR" can be used in a flexible
way if we change the number of pixels in the image.

However we must remember to free the memory afterwards:

    for(m=0;m<width;m++)
    {
        for(n=0;n<height;n++)
        {
            free(ALL_SCALED_COLOR[m][n]);
        }
        free(ALL_SCALED_COLOR[m]);
    }
    free(ALL_SCALED_COLOR);

It's easy to forget freeing the memory allocated to arrays of pointers, for
example, ALL_SCALED_COLOR[m] and ALL_SCALED_COLOR, after freeing the memory
these pointers point to. 

### Additional Comments
*** Check Memory Leak with Valgrind ***

To check memory leak on "make clean check", we type:
valgrind --leak-check=yes make clean check

If there's no memory leak, the result will be:
==22140== LEAK SUMMARY:
==22140==    definitely lost: 0 bytes in 0 blocks
==22140==    indirectly lost: 0 bytes in 0 blocks
==22140==      possibly lost: 0 bytes in 0 blocks
