#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_funcs.h"



int main(void)
{

    Np linked_list_1 = read_linked_list();
    Np linked_list_2 = read_linked_list();
    Np united, reversed;
    printf("Reverse recursive print\n");
    print_list_reverse_recursive(linked_list_1);
    printf("\n\n");

    printf("Normal recursive print\n");
    print_list_recursive(linked_list_1);
    printf("\n");
    print_list_recursive(linked_list_2);
    printf("\n\n");

    printf("Recursive member(65, linked_list_1): %d\n", member_recursive(65,linked_list_1));
    printf("Recursive member(64, linked_list_1): %d\n\n", member_recursive(64,linked_list_1));

    printf("Iterative member(65, linked_list_1): %d\n", member_iterative(65, linked_list_1));
    printf("Iterative member(64, linked_list_1): %d\n\n", member_iterative(64, linked_list_1));

    printf("Union iterative: \n");
    print_list_recursive(union_iterative(linked_list_1,linked_list_2));
    printf("\n\n");

    printf("Union recursive: \n");
    united=union_recursive(linked_list_1, linked_list_2);
    print_list(linked_list_1);
    print_list(linked_list_2);
    print_list(united);
    printf("\n\n");

    printf("Reverse list iterative:\n");
    reversed = reverse_list_iterative(united);
    print_list(reversed);

    printf("Reverse list recursive:\n");
    reverse_list_recursive(reversed);
    print_list(reversed);

    return 0;
}