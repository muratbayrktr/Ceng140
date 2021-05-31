#include <stdio.h>
#include "math.h"

int main()
{
    int i = 0, num = 0;
    char name[] = "3475";
    int len = sizeof(name) - 1;
    printf("len is %d \n", len);
    while (name[i] != '\0')
    {
        int temp;
        temp = (int) name[i] - 48;
        temp *= (pow(10.0,(double) len - i - 1));
        printf("%c %d\n", name[i], temp);
        num += temp;
        i++;
    }
    printf("%d\n", num);


    return 0;
}

