// Lab 9: Write a program to test whether the given matrix is Markov or not

#include <stdio.h>

#define N 3
#define M 3

int isMarkovMatrix(float m[][N]) {
    int i, j;
    float s;
    int t = 1;

    for (i = 0; i < M; i++) {
        s = 0;
        for (j = 0; j < N; j++) {
            if (m[i][j] < 0) {
                t = 0;
                break;
            }
            s = s + m[i][j];
        }
        if (s != 1.0f) {
            t = 0;
            break;
        }
    }

    return t;
}

void read(float m[][N]) {
    printf("Enter elements of %d x %d matrix:\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &m[i][j]);
        }
    }
}

int main() {
	printf("Test whether the given matrix is Markov or not.\n");
    float matrix[M][N];
    read(matrix);
    
    if (isMarkovMatrix(matrix)) {
        printf("The matrix is a Markov Matrix\n");
    } else {
        printf("The matrix is not a Markov Matrix\n");
    }

    return 0;
}

