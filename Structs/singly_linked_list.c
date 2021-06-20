#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_funcs.h"

union read_data
{
    /* data */
    int data;
    char stop_char;
};


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


int main(void)
{

    Np linked_list_1 = read_linked_list();
    Np linked_list_2 = read_linked_list();
    Np united;

    printf("Reverse recursive print\n");
    print_list_reverse_recursive(linked_list_1);
    printf("\n\n");

    printf("Normal recursive print\n");
    print_list_recursive(linked_list_1);
    printf("\n\n");

    printf("Recursive member(65, linked_list_1): %d\n", member_recursive(65,linked_list_1));
    printf("Recursive member(64, linked_list_1): %d\n\n", member_recursive(64,linked_list_1));

    printf("Iterative member(65, linked_list_1): %d\n", member_iterative(65, linked_list_1));
    printf("Iterative member(64, linked_list_1): %d\n\n", member_iterative(64, linked_list_1));

    printf("Union iterative: \n");
    print_list_recursive(union_iterative(linked_list_1,linked_list_2));
    printf("\n\n");

    printf("Union recursive: \n");
    united = union_recursive(linked_list_1,linked_list_2);
    print_list_recursive(united);
    printf("\n\n");

    return 0;
}