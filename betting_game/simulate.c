#include "global.h"

static int play(void);
static char toss(void);

int simulate(int kitty, int games) 
{
    int i, heads, balance;

    for (i = 1, balance = kitty; i <= games; i++) 
    {
        heads = play();
        if (heads == 1) heads = play();
        (heads == 2) ? balance ++ : balance -- ;
    }
    return balance;
}

static int play(void)
{
    int flip1, flip2;

    flip1 = toss();
    flip2 = toss();

    if (flip1 == 'H' && flip2 == 'H') return 2;
    if (flip1 == 'T' && flip2 == 'T') return 0;
    return 1;
}

static char toss(void)
{
    return rand() <= 0.5 ? 'H' : 'T';
}
