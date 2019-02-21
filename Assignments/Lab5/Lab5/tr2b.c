#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{false=0,true=!false} bool;

//Check IO

void checkIO()
{
    if(ferror(stdin))
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
    
    int i=0,j=0;
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
    
    char c=getchar();
    
    checkIO();
    //While not reaching the end of file
    while(!feof(stdin))
    {
        for(i=0;i<len1;i++)
        {
            if(c==from[i])
            {
                c=to[i];
                break;
            }
        }
        
        putchar(c);
        
        //Get next char
        c=getchar();
        checkIO();
    }
    return 0;
    
}
