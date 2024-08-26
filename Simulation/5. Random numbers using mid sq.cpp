// Lab 5: Write a C program to generate 10 random numbers using mid square method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long int i, s, x, y, z, seed;
    int n;
    seed = 61;
    printf("Generate random numbers using mid square method\n");
    printf("How many random numbers to be generated: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        s = (seed * seed);
        y = s / 10.0;
        z = y / 100.;
        x = (int)((y / 100. - z) * 100.);
        printf("x = %ld\n", x);
        seed = x;
        printf(" %4ld ", x);
    }
    return 0;
}

