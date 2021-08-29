#include <stdio.h>


void print_bin(unsigned int n)
{
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf("\n");
}


int main(void)
{
    char e1 = 'A', e2 = 'B';

    printf("e1: "); print_bin(e1);
    printf("e2: "); print_bin(e2);
    printf("e1 ^ e2: "); print_bin((e1 ^ e2) ^ e2);

    return 0;
}