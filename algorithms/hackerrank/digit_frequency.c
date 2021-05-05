#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* 
inp:
a11472o5t6 

out:
0 2 1 0 1 1 1 1 0 0
*/
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char *s;
    int i = 0;
    int count[10] = {0};
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    while (*(s+i) != '\0')
    {
        if (((int) *(s+i) >= 48 ) && ((int) *(s+i) <= 57 ))
        {
            count[*(s+i)-48] += 1;
            
        }
        i++;
    }

    for (i = 0; i< 10; i++) printf("%d ",count[i]);
    return 0;
}
