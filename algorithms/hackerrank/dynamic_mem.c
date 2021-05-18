#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int i;
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    /* allocate memory for the books and init to 0 */
    total_number_of_books = (int *) calloc(total_number_of_shelves, sizeof(int));

    total_number_of_pages = (int **) malloc(sizeof(int*)*total_number_of_shelves);
    
    /* creating array pointing the second array which contains the number of pages */
    for(i = 0; i < total_number_of_shelves; i++) *(total_number_of_pages + i) = (int *) malloc(sizeof(int));
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            /* update the book number in the shell*/
            *(total_number_of_books + x) += 1;
            
            /* reallocate the array inside the x'th shell */
            *(total_number_of_pages + x) = (int *) realloc(*(total_number_of_pages + x), *(total_number_of_books + x)*sizeof(int));
            
            /* modify the last Val in the array */
            *(*(total_number_of_pages + x) + total_number_of_books[x] - 1) = y;
            
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}