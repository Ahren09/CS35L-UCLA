#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum{false=0,true=!false} bool;

//Check IO

void checkIO(ssize_t in)
{
    if(in==-1)
    {
        fprintf(stderr, "Error: Invalid stdin");
        exit(1);
    }
}

int main(int argc, const char * argv[]) {
    
    //Check number of arguments
    if(argc!=3)
    {
        fprintf(stderr,"Error: Number of arguments must equal 2");
        exit(1);
    }
    
    //Initialize from and to
    const char* from=argv[1], *to=argv[2];
    int len1=strlen(argv[1]);
    int len2=strlen(argv[2]);
    
    //Check: Length = 0
    if(len1 == 0 || len2 == 0)
    {
        fprintf(stderr,"Error: Length of operands must not be 0");
        exit(1);
    }
    
    //Check: Different length
    if(len1!=len2)
    {
        fprintf(stderr,"Error: Length of arguments must be the same");
        exit(1);
    }
    
    int i=0, j=0;
    //Check: duplicate bytes
    for(i=0;i<len1;i++)
    {
        for(j=i+1;j<len1;j++)
        {
            if(from[i]==from[j])
            {
                fprintf(stderr,"Error: Duplicate bytes");
                exit(1);
            }
        }
    }
    
    
    char c; //Indicates currently read char
    
    //While not reaching the end of file
    //a positive value indicates that position is not at EOF
    while(true)
    {
        //Check IO
        if(read(STDIN_FILENO,&c,1)<=0)
        {
            fprintf(stderr, "Error: Input failure");
            exit(1);
        }
        
        for(i=0;i<len1;i++)
        {
            if(c==from[i])
            {
                //Replace char
                c=to[i];
                break;
            }
        }
        
        if(write(STDOUT_FILENO,&c,1)<0)
        {
            fprintf(stderr, "Error: Output failure");
            exit(1);
        }
    }
    return 0;
    
}

