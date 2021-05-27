#include <stdio.h>
#include <stdlib.h>

void input_grades(int **students, int no_of_students)
{
    int no_of_grades, i, j;
    for (i = 0; i < no_of_students; i++)
    {
        /* read the # of grades */
        scanf("%d", &no_of_grades);
         /* allocate memory for the grades */
        *(students + i) = (int *) malloc(sizeof(int)*no_of_grades);
        /* get the grades */
        for (j = 0; j < no_of_grades; j++)
        {
            int grade;
            scanf("%d",&grade);
            *(*(students + i) + j) = grade;
        }
    }
    return ;
}

int main(void)
{
    int no_of_students;
    int ** students;

    /* read the # of students */
    scanf("%d", &no_of_students);
    /* allocate memory for the pointer to grades of the relevant student */
    students = (int **) malloc(sizeof(int *)*no_of_students);

    input_grades(students, no_of_students);

    
    return 0;
}