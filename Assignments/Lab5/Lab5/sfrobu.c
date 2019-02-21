#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>

#define SP ' '

int ignoreCase = 0;

//Print error message
void printErr(const char* msg)
{
    fprintf(stderr,"Error: %s\n", msg);
    exit(1);
}

//Check IO
void checkIO(ssize_t ch)
{
    if(ch==-1)
    {
        printErr("Input failure");
    }
}

//frob
int frob(const char c)
{
    char ch=c^42;
    if(ignoreCase==1 && islower(ch)){
        ch=toupper(ch);
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
int sort(const void *a, const void *b) {
    return frobcmp(*(const char**) a, *(const char**) b);
}



int main()
{
    
    char c;
	char *word=(char*)malloc(sizeof(char));
	char **words=(char**)malloc(sizeof(char*));
    int c_num=0,w_num=0,cc_num=0;
    ssize_t in=1;
    
    //check bad malloc()
	if(word == NULL || words == NULL)
	{
        printErr("Memory Allocation");
	}
    
    while(in)
    {
        //Store one char in c
        in = read(STDIN_FILENO,&c,1);
        checkIO(in);
        
        //End of word of more than 1 char
        if(c_num>0 && (c==SP || in == 0))
        {
            word=(char*)realloc(word, (c_num+1)*sizeof(char)); //$
            word[c_num] = SP;
            char *newword=(char*)malloc(sizeof(char));
            words=(char**)realloc(words,(w_num+1)*sizeof(char*));
            
            //insert the new word into words
            if(newword && words)  //if both the new word and the words array are valid
            {
                words[w_num]=word;
                w_num++;
                word=newword;
                c_num=0;
                
            }
            else
            {
                free(word);
                printErr("Bad Memory Allocation");
            }
        }
        else
        {
            word=(char*)realloc(word, (c_num+1)*sizeof(char));
            if(word)
            {
                word[c_num++]=c;
                cc_num++;
            }
            else{
                printErr("Bad Memory Allocation");
            }
        }
    }
    //Sort the array and print
    qsort(words,w_num,sizeof(char*),sort);
    
    int i=0,j=0;
    for(i=0;i<w_num;i++)
    {
        for(j=0;words[i][j]!='\0';j++)
        {
            in = write(STDOUT_FILENO,&words[i][j],1);
            checkIO(in);
            if(words[i][j]==SP)
                break;
        }
    }
    
    //Free memory
    for(i=0;i<w_num;i++)
    {
        free(words[i]);
    }
    free(words);
    free(word);
    exit(0);
}

