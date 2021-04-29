#include <stdio.h>

double power(int base, int exponent){
    double power_helper(int base, int exponent, int call);
    return power_helper(base, exponent, 1);
}

double power_helper(int base, int exponent, int call) 
{
    printf("calculate %d^%d call: %d\n", base, exponent, call);
    if (exponent == 1) return base;
    else if (exponent % 2 == 0) {
        double p = power_helper(base,exponent/2,call+1);
        return p*p;
    } else {
        return power_helper(base,exponent-1,call+1)*base;
    }
}

int main(void) {
    double power(int base, int exponent);
    double power_helper(int base, int exponent, int call);
    int b,e;
    printf("please input for power(base,exponent):\n");
    scanf(" %d %d", &b,&e);
    printf("power(%d,%d)=%.0f\n",b,e,power(b,e));
    return 0;
}