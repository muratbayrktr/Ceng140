#include <stdio.h>
#include <stdlib.h>

char* pile(char* str1, char* str2) {
    int i = 0, j = 0, m = 0;
    int first_finished = 0, second_finished = 0;
    char *piled = (char *) malloc(sizeof(char));
    while (1)
    {
        if (str1[i] == '\0') {
            first_finished = 1;
        }
        if (str2[j] == '\0') {
            second_finished = 1;
        }
        if (first_finished && second_finished) break;
        if (first_finished) {
            if (str2[j] == ' ') {j++; continue;}
            piled[m++] = str2[j++];
            piled = (char *) realloc(piled, sizeof(char)*(m+1));
        } else if (second_finished) {
            if (str1[i] == ' ') {i++; continue;}
            piled[m++] = str1[i++];
            piled = (char *) realloc(piled, sizeof(char)*(m+1));
        } else {
            if (m%2 == 0) { 
                if (str1[i] == ' ') {i++; continue;}
                piled[m++] = str1[i++]; 
                }
            else { 
                if (str2[j] == ' ') {j++; continue;}
                piled[m++] = str2[j++]; 
                }
            piled = (char *) realloc(piled, sizeof(char)*(m+1));
        }
    }
    piled[m] = '\0';
    return piled;
}

int main(void)
{
    char str1[] = "<<";
    char str2[] = ">>>>";

    char *str3 = pile(str1, str2);

    printf("%s\n",str3);
    return 0;
}