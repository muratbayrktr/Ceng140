#include<stdio.h>

void hanoi(int num_of_disks, char from, char to, char mid)
{
    if (num_of_disks > 0)
    {
        hanoi(num_of_disks-1, from, mid, to);
        printf("Move disk %d from %c to %c\n", num_of_disks, from, to);
        hanoi(num_of_disks - 1, mid, to, from);
    }
}

int main(void)
{

    void hanoi(int num_of_disks, char rod1, char rod2, char rod3);

    hanoi(4, 'A', 'B', 'C');
    
    return 0;
}

