#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    struct stat buf;
    f=open("./frosting-recipe.txt",O_RDONLY);
    fstat(f,&buf);
    printf("%s %d",)
    
    
}

