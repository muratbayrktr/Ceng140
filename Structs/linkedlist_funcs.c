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
            link(first) = second;
            break;
        }
        first = link(first);
    }
    return new;
}
void print_list_recursive(Np start)
{
    if(start)
    {
        printf("%d ",data(start));
        print_list_recursive(link(start));
    }
    return;
}

void print_list(Np start)
{
    while(start)
    {
        printf("%d ", data(start));
        start = link(start);
    }
}


Np union_recursive(Np first, Np second)
{
    Np next = link(first);
    printf("\nSecond:\n");
    print_list(second);
    link(first) = second;
    if (link(second))
    {
        Np temp;
        temp = union_recursive(second, next);
    printf("\n---Stack:---\n");
    print_list(temp);
    printf("\n---------\n\n");
    }
    else if (link(first))
    {   
        printf("First:\n");
        print_list(first);
        printf("\nSecond:\n");
        print_list(second);
        printf("\n\n");
    }
    return first;
}