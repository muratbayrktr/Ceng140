#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compactify(char *sentence)
{
    int i, m, last_was_blank;
    for (i = 0, m = 0, last_was_blank = 0; sentence[i]; i++)
    {
        if (sentence[i] == ' ')
        {
            if (last_was_blank) continue;
            else last_was_blank = 1;
        }
        else sentence[m++] = sentence[i];
        last_was_blank = 0;
    }
    sentence[m] = '\0';    

    sentence = (char * ) realloc(sentence, m);

    return ;
}


int main(void)
{
    char *sentence;
    
    sentence = (char *) malloc(256);

    strcpy(sentence, "Nerd  today     boss  tomorrow  .");
    
    compactify(sentence);

    printf("%s\n",sentence);


    return 0;
}