#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <unistd.h>

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
    if(len1!=len2||len1==0)
        printErr("Incompatible conversion sets!");
    
    
    int i,j;
    for(i=0;i<len1;i++)
        for(j=0;j<len1;j++)
            if(from[i]==to[i])
                printErr("Duplicated arguments!");
    
    char c;
    ssize_t ret;
    while(1)
    {
        ret=read(STDIN_FILENO,&c,1);
        if(ret==0)
            break;
        else if(ret<0)
            printErr("Input failure");
        for(i=0;i<len1;i++)
        {
            if(c==from[i])
                c=to[i];
        }
        ret=write(STDOUT_FILENO,&c,1);
        if(ret<0)
            printErr("Output failure");
    }
    return 0;
    
    
    
    
    
    
    
}
