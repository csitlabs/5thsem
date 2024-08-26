// Lab 6: Write a C program to that tests random numbers for frequency using Kolmogorov S test

#include <stdio.h>
#define N 5
#define Dalpha 0.565

int main() {
    printf("Test random numbers for frequency\n");
    
    float R[N] = {0.05, 0.14, 0.44, 0.81, 0.93};
    float X[N], Y[N], Z[N];
    float D1, D2, D;
    int i;
    
    // Calculate X[i] = (i + 1) / N
    for (i = 0; i < N; i++) {
        X[i] = (float)(i + 1) / N;      
    }
    
    // Calculate Y[i] = X[i] - R[i]
    for (i = 0; i < N; i++) {
        Y[i] = X[i] - R[i];      
    }
    
    // Calculate Z[i] = R[i] - (i / N)
    for (i = 0; i < N; i++) {
        Z[i] = R[i] - (float)i / N;     
    }
    
    // Find maximum of Y[i]
    D1 = Y[0];
    for (i = 1; i < N; i++) {
        if (D1 < Y[i]) {
            D1 = Y[i];
        }
    }
    
    // Find maximum of Z[i]
    D2 = Z[0];
    for (i = 1; i < N; i++) {
        if (D2 < Z[i]) {
            D2 = Z[i];
        }
    }
    
    // D is the maximum of D1 and D2
    D = (D1 > D2) ? D1 : D2;
    printf("D = %0.2f\n", D);
    
    if (D < Dalpha) {
        printf("Random numbers are uniformly distributed\n");
    } else {
        printf("Random numbers are not uniformly distributed\n");
    }

    return 0;
}

