#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* 
inp:
    This is C

out:
    This
    is
    C
*/
int main() {

    char *s;
    int i = 0;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    //Write your logic to print the tokens of the sentence here.
    while (*(s+i) != '\0')
    {
        if (*(s+i) == ' ') { printf("\n"); i++;}
        else printf("%c",*(s+i++));        
    }
    printf("\n");
    return 0;
}