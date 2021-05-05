#include <stdio.h>

int arr[] = {44, -3, 8, 222, 7, 65};

void bubble_sort(int arr[], int size)
{
    int i, k, temp;
    for (i = 0; i < size; i++)
    {
        for (k = 1; k < size; k++)
        {
            if (arr[k-1] > arr[k]) 
            {
                temp = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = temp; 
            }
        }
    }
}

int main(void)
{
    void bubble_sort(int arr[], int size);
    int size = sizeof(arr)/sizeof(int);
    
    bubble_sort(arr,size);
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}