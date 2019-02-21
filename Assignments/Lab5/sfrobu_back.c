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
void checkMem(void* p);
int ignoreCase=0;
size_t initLinebuf(char** linebuf, char* buf, size_t n_lines);
int sort(const void* a, const void* b);

int main(int argc, char* argv[])
{
    
    //Check number of args
    if(argc!=2){
        if(argc==3)
        {
            //if "-f" option is selected
            if(strncmp(argv[1],"-f",2) == 0)
                ignoreCase=1;
        }
        else printErr("Wrong number of args");
    }
    
    
    ssize_t c,cur;
    char* word = (char*)malloc(sizeof(char));
    char** words = (char**)malloc(sizeof(char*));
    ssize_t i, lineNum=0, lineSize=0, bufferSize=0, fileSize=0;
    int isEOF=0;
    char readbuf[2];
    
    //Convention for using qsort
    int (*cmp) (const void*, const void*);
    
    //To use stat, we "#include <sys/stat.h>"
    struct stat buf;
    //Or we use: struct stat *buf = malloc(sizeof(struct stat));
    
    //Set frobcmp pointer
    cmp = &sort;
    
    //Get file info
    c=fstat(STDIN_FILENO,&buf);
    checkIO(c);
    fileSize=buf.st_size+1;
    
    //Initialize buffer
    char* input = (char*)malloc(sizeof(char) * fileSize);
    char* temp;   //For resizing buffer
    checkMem(input);
    word=input;
    
    //while not reaching end of file, get next char
    while(!isEOF)
    {
        //Get first char
        c = read(STDIN_FILENO,readbuf,1);
        checkIO(c);
        cur=readbuf[0];
        
        //check EOF
        isEOF=!c;
        
        //If length of current line is 0 AND current char is SP
        //CONTINUE next loop
        if(lineSize==0 && cur==SP)
            continue;
        
        //If buffer is full, resize to twice
        if(bufferSize == fileSize)
        {
            fileSize *= 2;
            temp = (char*) realloc(input, sizeof(char) * fileSize);
            checkMem(temp);
            input=temp;
        }
        
        //Store current char
        if(!isEOF)
        {
            input[bufferSize++] = cur;
            lineSize++;
            if(cur!=SP)
                continue;
        }
        else{
            if(bufferSize == 0)
            {
                free(input);
                return 0;
            }
            
            //Append SP
            if(input[bufferSize-1] != SP)
                input[bufferSize++] = SP;
            if(lineSize == 0)
                break;
            
        }
        
        //Create new line
        lineNum++;
        lineSize=0;
    }
    
    words = (char**) malloc(sizeof(char*) * lineNum);
    checkMem(words);
    
    if (lineNum != initLinebuf(words, input, bufferSize))
        printErr("Wrong Line Number.");
    
    //Sort input
    qsort(words,lineNum,sizeof(char*),cmp);
    
    //Write Output
    ssize_t ch;
    for(i=0;i<lineNum;i++)
    {
        while(*words[i]!=SP)
        {
            ch=write(STDOUT_FILENO,words[i],1);
            words[i]++;
        }
    }
    free(words);
    free(input);
    return 0;
    
}



//frob
int frob(char c)
{
    if(ignoreCase==1 && islower(c)){
        c=toupper(c);
    }
    char ch=c^42;
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
