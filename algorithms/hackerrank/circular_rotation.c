
/* The first line contains 3 space-separated integers, n, k, and q, 
the number of elements in the integer array, the rotation count and the number of queries 

The second line contains n space-separated integers, where each integer i describes array element a[i] (where 0 <= a[i] <= n). 

Each of the q subsequent lines contains a single integer, queries[i], an index of an element in a[] to return.
*/

int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count) {
    int i, *b;
    b = (int *) malloc(sizeof(int)*queries_count);
    for (i = 0; i <queries_count; i++)
    {
        int index = *(queries + i) - k;
        while (index < 0) {
            index = a_count + index;
        }
        *(b + i)= *(a + index);
    }
    *result_count = queries_count;

    return b;
}