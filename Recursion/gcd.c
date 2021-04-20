#include<stdio.h>

int gcd(int k, int n)
{
    int smallest = ( k > n ) ? k : n;
    int greatest = ( k > n ) ? n : k;
    if (greatest == 0) return smallest;
    return gcd(n, k%n);
}

int main(void) 
{
    int gcd(int, int);
    printf("%d %d %d\n",gcd(192,72),gcd(72,192),gcd(16,15));
    return 0;
}