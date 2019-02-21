#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void printErr(char* msg)
{
    fprintf(stderr,"Error: %s",msg);
    exit(1);
}

void checkIO()
{
    if(ferror(stdin))
        printErr("I/O failure!");
}


int main(int argc, char** argv)
{
    
    if(argc!=3)
        printErr("Wrong number of parameters!");
    char* from=argv[1], *to=argv[2];
    size_t len1=strlen(from);
    size_t len2=strlen(to);
    if(len1!=len2)
        printErr("Incompatible conversion sets!");
    
    char c;
    c=getchar();
    checkIO();
    
   
    int i,j;
    while(c!=EOF)
    {
        for(i=0;i<len1;i++)
        {
            if(c==from[i])
                c=to[i];
        }
        putchar(c);
        c=getchar();
    }
    
    
}
