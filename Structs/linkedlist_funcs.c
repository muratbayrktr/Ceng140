#include "linkedlist_funcs.h"

Np read_linked_list()
{
    Np start = NULL, new;
    union read_data val;

    while (scanf("%d",&val.data), val.stop_char != '#')
    {
        new = malloc(sizeof(Node));
        data(new) = val.data;
        link(new) = start;
        start = new;
    }
    
    return start;
}

void print_list_reverse_recursive(Np start)
{
    
    if(start)
    {
        print_list_reverse_recursive(link(start));
        printf("%d ",data(start));
    }
    return;
}

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
    printf("\n");
}


Np union_recursive(Np a, Np b)
{
    Np temp1 = a;
    Np temp2 = b;
    if (temp2)
    {
        union_recursive(temp1, link(temp2));
    } else temp2 = temp1;
    return temp1;
}

Np reverse_list_iterative(Np linkedlist)
{
    Np prev=NULL, current=linkedlist, next = link(current);
    while(next)
    {
        link(current) = prev;
        prev = current;
        current = next;
        next = link(next);
    }
    link(current) = prev;
    return current;
}


Np reverse_list_recursive(Np linkedlist)
{

    
    return NULL;
}
