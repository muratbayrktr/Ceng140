#include<stdio.h>

#define PI 3.1415926535


/*
                    1                       -> 1st row
                1       1                   -> 2nd row
            1       2       1               -> 3rd row
        1       3       3       1           -> 4th row
    1       4       6       4       1       -> 5th row
1       5       10      10      5       1   -> 6th row

as it's seen above, if you pick an element,
its value equals to the sum of the two adjacent values 
above it.
For example consider 5th row:
The value 6 equals to the 3 + 3 above (4th row):
6 is the 3rd entry in 5th row, define it : func(6,3)
first 3 is the 2nd entry in the 4th row, define it : func(5,2)
second 3 is the 3rd entry in the 4th row, define it : func(5,3)

extract general formula :
    row, order
func(a ,   b) = func(a-1,b-1)+func(a-1,b)

Also, if a==b or b == 1 then result is 1
*/
int binomial_coefficient(int n, int k)
{
    if (n == 1 || n==k || k==1) return 1;
    return binomial_coefficient(n-1,k-1) + binomial_coefficient(n-1,k);
}

double arithmetic_sequences(int a, double d, int n)
{
    if (n == 1) return (double) a;
    return arithmetic_sequences(a, d, n-1) + d;
}

double geometric_sequences(int a, double d, int n)
{
    if (n == 1) return (double) a;
    return geometric_sequences(a, d, n-1)*d;
}
/*
Catalan number C(n) =  comb(2n,n)/(n+1) = 2n!/(n!*(n+1)!
               C(n-1) = comb(2n-1,n-1)/n = (2n-2)!/((n-1)!*n!)

        so, C(n) = C(n-1)*2*n*(2*n-1)/(n*(n+1))
*/
double catalan_num(int n)
{
    if (n==1) return 1;
    return catalan_num(n-1)*2*n*(2*n-1)/(n*(n+1)); 
}

/* fibonacci will be implemented */

int main(void) 
{
    double arithmetic_sequences(int a, double d, int n);
    double geometric_sequences(int a, double d, int n);

    printf("Binomial coefficients for: \nb(4,2): %d\nb(5,3): %d\nb(8,4): %d\n",
                                    binomial_coefficient(4,2),
                                    binomial_coefficient(5,3),
                                    binomial_coefficient(8,4));

    printf("\nRecursive defn for arithmetic sequences:\n");
    printf("a1 = 1, d = 2, 5th term = %.2f\na1 = 1, d = 0.5, 21st term = %.2f\na1 = 1, d = PI, 10th term = %.2f\n",
                        arithmetic_sequences(1,2.0,5),
                        arithmetic_sequences(1,0.5,21),
                        arithmetic_sequences(1,PI,10));


    printf("\nRecursive defn for geometric sequences:\n");
    printf("a1 = 1, d = 2, 5th term = %.2f\na1 = 1, d = 0.5, 21st term = %e\na1 = 1, d = PI, 10th term = %.2f\n",
                        geometric_sequences(1,2.0,5),
                        geometric_sequences(1,0.5,21),
                        geometric_sequences(1,PI,10));

    printf("\n5th Catalan Number: \n%f\n%f\n%f\n%f\n%f\n",
    catalan_num(1),
    catalan_num(2),
    catalan_num(3),
    catalan_num(4),
    catalan_num(5));
    return 0;
}