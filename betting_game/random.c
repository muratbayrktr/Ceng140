#include "global.h"
#define MULTIPLIER 25173
#define INCREMENT 13849
#define MODULUS 65536

static unsigned int number = 1; 

void srand(unsigned int seed0) 
{
    number = seed0 % MODULUS;
}

double rand()
{
    number = (MULTIPLIER * number + INCREMENT) % MODULUS;
    return (double) number / (MODULUS - 1);
}