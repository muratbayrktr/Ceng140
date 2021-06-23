
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

union read_data
{
    /* data */
    int data;
    char stop_char;
};

Np read_linked_list();

void print_list_reverse_recursive(Np start);

/* returns either 1 or 0 */
int member_recursive(int x, Np P);

int member_iterative(int x, Np P);
/* merge */
Np union_recursive(Np first, Np second);

Np union_iterative(Np first, Np second);

void print_list_recursive(Np start);

void print_list(Np start);

/* O(n) and malloc not allowed */
Np reverse_list_recursive(Np linkedlist);

Np reverse_list_iterative(Np linkedlist);


#endif