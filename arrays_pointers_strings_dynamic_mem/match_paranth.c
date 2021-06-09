#include <stdio.h>

int find_matching_par(char *s, int k)
{
    char *start = s;
    int count;
    
    for (count = 1, s += k + 1; *s; s++)
    {
        switch (*s)
        {
        case '(':
            {
                count++;
                break;
            }
        case ')':
            {
                count--;
                break;
            }
        default:
            break;
        }
        if (count == 0) return s - start;
    }
    return s-start;
}

int main(void)
{
    int matching_par;
    char string[] = "A(b(c((de)(fk(t)))ds)abk)";

    matching_par = find_matching_par(string, 3);

    printf("%d\n", matching_par);
    return 0;
}