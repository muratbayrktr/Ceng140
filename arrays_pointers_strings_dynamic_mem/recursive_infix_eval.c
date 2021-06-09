#include <stdio.h>
#include <ctype.h>

char expr[] = "((61-(75+((-15*2)/4)))+5)";
char *Curpos = expr;

long int read_and_eval_from_curpos()
{
    long int left, right, result;
    char oper;

    if (*Curpos == '(')
    {
        Curpos++;
        left = read_and_eval_from_curpos();
        printf("left: %ld\n", left);
        oper = *Curpos++;
        right = read_and_eval_from_curpos();
        printf("right: %ld\n", right);
        Curpos++;
        switch (oper)
        {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/': result = left / right; break;
        }
    } else 
    {
        sscanf(Curpos, "%ld ", &left);
        printf("value found : %ld\n", left);
        if (*Curpos == '-') Curpos++;
        while(isdigit(*Curpos)) Curpos++;
        return left;
    }
    return result;
}

int main(void)
{
    long int result;
    result = read_and_eval_from_curpos();
    printf("%ld \n",result);
    
    return 0;
}