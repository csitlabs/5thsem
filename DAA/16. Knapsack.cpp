//16. Dynamic Programming - 0/1 Knapsack

#include <iostream>
using namespace std;

const int MAX_ITEMS = 100; // Adjust as needed
const int MAX_WEIGHT = 1000; // Adjust as needed

int knapsack(int W, int wt[], int val[], int n) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W, n;
	cout << "Dynamic Programming - 0/1 Knapsack Problem" << endl;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    int wt[MAX_ITEMS], val[MAX_ITEMS];

    cout << "Enter weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }

    cout << "Enter values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    cout << "Maximum value in the knapsack is " << knapsack(W, wt, val, n) << endl;

    return 0;
}

