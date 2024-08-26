//Program 11: Write C program to simulate single server queuing system


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int run = 10;
    float x, iat, st, awt, pcu, wt = 0, it = 0;
    float mean = 10.0, sd = 1.5, mue = 9.5, sigma = 1.0;
    float sb = 0.0, se = 0.0, cit = 0, cat = 0, cwt = 0;
	printf("Simulate single server queuing system\n");
    printf("\nIAT     CAT     SB     ST     SE     CWT     CIT");

    for (int j = 1; j <= run; ++j) {
        float sum = 0;

        // Generate inter-arrival time (IAT)
        for (int i = 1; i <= 12; ++i) {
            x = rand() / (float)RAND_MAX;
            sum += x;
        }
        iat = mean + sd * (sum - 6.0);
        cat += iat;

        if (cat <= se) {
            sb = se;
            wt = se - cat;
            cwt += wt;
        } else {
            sb = cat;
            it = sb - se;
            cit += it;
        }

        // Generate service time (ST)
        sum = 0;
        for (int i = 1; i <= 12; ++i) {
            x = rand() / (float)RAND_MAX;
            sum += x;
        }
        st = mue + sigma * (sum - 6.0);
        se = sb + st;

        // Print the results for this iteration
        printf("\n%5.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f", iat, cat, sb, st, se, cwt, cit);
    }

    // Calculate average waiting time and percentage capacity utilization
    awt = cwt / run;
    pcu = ((cat - cit) * 100.0) / cat;

    // Print final results
    printf("\nAverage waiting time = %6.2f", awt);
    printf("\nPercentage capacity utilization = %6.2f\n", pcu);

    return 0;
}

