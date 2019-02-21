#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>

#define SP ' '

int flag = 0;
//Print error message
void printErr(char* msg)
{
    fprintf(stderr,"Error: %s",msg);
}

//Check IO
void checkIO(ssize_t ret)
{
    if(ret<0)
        printErr("I/O failure!");
    
}

//frob
//flag=1 signifies uppercase; flag=0 means otherwise
char frob(char c)
{
    c=c^42;
    if(flag==1)
        c=toupper(c);
    return c;
}

//Compare two strings
int frobcmp(char* a, char* b)
{
    
    for(;*a==*b;a++,b++)
        if(*a==SP)
            return 0;
    return frob(*a)<frob(*b) ? -1 : 1;
    
}



//Wrapper function
int sortcmp(char* a, char* b){
    return frobcmp(*(char**)a, *(char**)b);
}



int main()
{
    //Variable declaration
    char c;
    char* line;
    char* linebuf;
    char** lines;
    char* buf; // For storing buffer of all lines
    int line_num;
    
    ssize_t ret;
    
    
    
    //check bad malloc()
	
    
    //while
    do
    {
        ret=read(STDIN_FILENO,c,1);
        if(c==SP)
        {
            
        }
        
        
        
    }while(ret!=0);
        //Store one char in c
    
        
        //End of word of more than 1 char
    
            //insert the new word into words
                    //if both the new word and the words array are valid
    
    //Sort the array and print
    qsort(lines,line_num,sizeof(char*),&sortcmp);
    
    //Free memory
    
}

