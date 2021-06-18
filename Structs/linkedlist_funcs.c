#include "linkedlist_funcs.h"


int member_recursive(int x, Np P)
{
    if(P)
    {
        if (data(P) == x) return 1;
        else return member_recursive(x, link(P));
    }
    return 0;
}

int member_iterative(int x, Np P)
{
    while(P)
    {
        if (data(P) == x) return 1;
        else P = link(P);
    }
    return 0;
}

Np union_iterative(Np first, Np second)
{
    Np new;
    new = first;
    while(first)
    {
        if (link(first) == NULL)
        {
            printf("datum:%d\n",data(first));
            link(first) = second;
            break;
        }
        first = link(first);
    }
    return new;
}