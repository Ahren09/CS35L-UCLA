#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int frob(char const a)
{
	return (a^42);
}

int frobcmp(char const *a, char const *b)
{
	while(*a!=' ' && *b!=' ')
	{
		if(*b==' ' || frob(*a) > frob (*b))
			return 1;
		else if(*a==' ' || frob(*b) > frob (*a))
                        return -1;
		a++;
		b++;

	} 
	return 0;

}

int sort(const void *a, const void *b) {
    return frobcmp(*(const char**) a, *(const char**) b);
}

void checkIO()
{
	if(ferror(stdin))
	{	fprintf(stderr,"Error: Bad stdin");
		exit(1);
	}

}


int main()
{
    
    char c;
	char *word=(char*)malloc(sizeof(char));
	char **words=(char**)malloc(sizeof(char*));
    int c_num=0,w_num=0;
    
    //check bad malloc()
	if(word == NULL || words == NULL)
	{
		fprintf(stderr,"Error: Bad memory allocation");
		exit(1);
	}
    
    while(!feof(stdin))
    {
        
        //get next char
        c=getchar();
        checkIO();
        
        //End of word of more than 1 char
        if(c_num>0 && (c==' ' || feof(stdin) || c==EOF))
        {
            word=(char*)realloc(word, (c_num+1)*sizeof(char));
            word[c_num]=' ';
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
                fprintf(stderr,"Error: Bad memory allocation");
                free(word);
                exit(1);
            }
        }
        else
        {
            word=(char*)realloc(word, (c_num+1)*sizeof(char));
            if(word)
            {
                word[c_num]=c;
                c_num++;
            }
            else{
                fprintf(stderr, "Error: Bad memory allocation");
                exit(1);

            }
            
            
        }
    }
    
    
    //Sort the array and print
    qsort(words,w_num,sizeof(char*),sort);
    
    int i=0,j=0;
    for(i=0;i<w_num;i++)
    {
        for(j=0;j<w_num;j++)
        {
            if(words[i][j]=='\0')
                break;
            else if(words[i][j]==' ')
            {
                putchar(words[i][j]);
                break;
            }
            else
                putchar(words[i][j]);
            
        }
        
    }
    
    //Free memory
    for(i=0;i<w_num;i++)
    {
        free(words[i]);
    }
    free(words);
    exit(0);
}

