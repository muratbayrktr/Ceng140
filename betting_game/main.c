#include "global.h"

static void initialize(void);

int main(void)
{
    int balance;

    initialize();

    balance = simulate(KITTY,GAMES);
    printf("kitty = %d; take home = %d\n",KITTY,balance);
    
}

static void initialize(void)
{
    srand(SEED);
}