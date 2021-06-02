#include <stdio.h>
#include <stdlib.h>

char** split(char *str, char delimeter) {
    int m = 0, k = 0, i = 0;
    char c = str[i];
    char **splitted_arr;
    splitted_arr  = (char **) malloc(sizeof(char *));
    *(splitted_arr) = (char * ) malloc(sizeof(char  ));
    **splitted_arr = '\0';
    while (c != '\0')
    {
        c = str[i];
        if (c == delimeter)
        {
            
            splitted_arr[k++][m] = '\0';
            splitted_arr = (char **) realloc(splitted_arr,sizeof(char *)*(k+1));
            m = 0;
            *(splitted_arr + k) = (char *) malloc(sizeof(char));
            *(*(splitted_arr + k)) = '\0';
            
        } else 
        {
            splitted_arr[k][m++] = c;
            *(splitted_arr + k)= (char *) realloc(*(splitted_arr + k),sizeof(char )*((m+1)));
        }
        i++;
    }
    splitted_arr[k++][m] = '\0';
    splitted_arr = (char **) realloc(splitted_arr,sizeof(char *)*(k+1));
    *(splitted_arr + k) = NULL;
    return splitted_arr;
}

int main(void)
{
    int i,j;
    char str[] = ",You see, madness, as you know, is like gravity. All it takes is a little push!";
    char **splitted_arr = split(str, ',');

    i = j = 0;
    
    while (splitted_arr[i] != 0)
    {
        printf("%s\n",splitted_arr[i++]);
    }
    return 0;
}