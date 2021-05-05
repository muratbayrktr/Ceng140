#include <stdio.h>
#include <stdlib.h>

/* 
in:

7
1 13 15 20 12 13 2 

out:

2 13 12 20 15 13 1
*/

int main()
{
    int num, *arr, i, *backup_arr;
    scanf("%d", &num);
    arr = (int *) malloc(num * sizeof(int));
    backup_arr = (int *) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    for(i = num-1; i >= 0; i--) {
        *(backup_arr + num - 1 - i) = *(arr+i);
    }
    for(i = 0; i < num; i++) {
        *(arr+i) = *(backup_arr + i);
    }    



    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
