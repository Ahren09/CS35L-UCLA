#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>

#define SP ' '

void printErr(const char* msg);
int frob(const char c);
int frobcmp(const char* a, const char* b);
void checkIO(ssize_t in);

int ignoreCase=0;

int main(int argc, char* argv[])
{
    char c;
    char* word = (char*)malloc(sizeof(char));
    char** words = (char**)malloc(sizeof(char*));
    ssize_t lineNum, lineSize, bufferSize, i, fileSize, ret;
    
    
    //To use stat, we "#include <sys/stat.h>"
    struct stat buf;
    //Or we use: struct stat *buf = malloc(sizeof(struct stat));
    
    checkIO(ret);
    fileSize=buf.st_size+1;
    int w_num;
    
    
    //Check number of args
    if(argc>2)
    {
        //if "-f" option is selected
        if(strcmp(argv[1],"-f") == 0)
        {
            ignoreCase=1;
        }
        else
        {
            fprintf(stderr,"Error: Wrong number of arguments");
        }
    }
    
    ret=fstat(STDIN_FILENO,&buf);
    
    
    
    //while not reaching end of file, get next char
    while(!feof(stdin))
    {
        c = read(STDIN_FILENO,buf,1);
        checkIO(ret);
        
        //If line is empty, or the next char is a space, continue next loop
        if()
        {
        }
        
    }
    
    qsort(words,w_num,sizeof(char*),sort);
    //Write Output
    
    
    for(i=0;i<w_num;i++)
    {
        
        
    }
    
}



//frob
int frob(const char c)
{
    char ch=c^42;
    if(ignoreCase==1 && islower(c)){
        ch=toupper(c);
    }
    return ch;
}

//Compare two strings
int frobcmp(const char* a, const char* b)
{
    for(;*a == *b; a++, b++)
        if(*a==SP) //Now both *a and *b must equal SP
            return 0;
    return frob(*a)>frob(*b) ? 1 : -1;
}

//Wrapper function
inline
int sort(const void* a, const void* b)
{
    return frobcmp(*(const char**)a, *(const char**)b);
}

//Check Memory Allocation
inline
void checkMem(void* p)
{
    if(!p) printErr("Memory Allocation");
}

//Print error message
inline
void printErr(const char* msg)
{
    fprintf(stderr,"Error: %s\n", msg);
    exit(1);
}
           
inline


//Check IO
inline
void checkIO(ssize_t ch)
{
    if(ch<0) //This means ferror returns a non-0 value
    {
        printErr("Input failure");
    }
}

//Count the number of lines separated by SP
size_t initLinebuf(char** linebuf, char* buf, size_t n_lines)
{
    size_t i, lineNumber;
    char* line=buf;
    for(i=0,lineNumber=0;i<n_lines;i++)
    {
        //IF we encounter a SP, store the chars preceding the SP in buf into linebuf
        //AND read newline into char* line
        if(buf[i] == SP)
        {
            linebuf[lineNumber++] = line;
            line=buf+i+1;
        }
    }
    return lineNumber;
    
}
