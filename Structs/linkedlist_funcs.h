
#ifndef linkedlist_funcs
#define linkedlist_funcs
#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    /* data */
    int datum;
    struct Node *link;

} Node, *Np;

#define data(p) ((p)->datum)
#define link(p) ((p)->link)

/* returns either 1 or 0 */
int member_recursive(int x, Np P);

int member_iterative(int x, Np P);
/* merge */
Np union_recursive(Np first, Np second);

Np union_iterative(Np first, Np second);

/* O(n) and malloc not allowed */
Np reverse_list_recursive(Np linkedlist);

Np reverse_list_iterative(Np linkedlist);


#endif