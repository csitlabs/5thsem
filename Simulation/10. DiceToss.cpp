// Lab 10:  Write a program to simulate the game called DiceToss

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Arand() {
    return 1 + rand() % 6;
}

int Brand() {
    return 1 + rand() % 6;
}

int main() {
    srand(time(0));
    
    int sa = 0, sb = 0;
    int a, b, x, y;

    a = Arand();
    b = Arand();
    sa = a + b;

    x = Brand();
    y = Brand();
    sb = x + y;

	printf("Simulate DiceToss\n");
    if (sa > sb) {
        printf("A wins the game by %d points.\n", sa - sb);
    } else {
        printf("B wins the game by %d points.\n", sb - sa);
    }

    return 0;
}

