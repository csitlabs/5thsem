//17. N-queen

#include <iostream>
using namespace std;

const int MAX_N = 100; // Maximum board size

// Function to print the board
void printSolution(int board[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Check if a queen can be placed on board[row][col]
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) return false;
    }
    return true;
}

// Solve N-Queens problem using backtracking
bool solveNQueensUtil(int board[MAX_N][MAX_N], int col, int N) {
    if (col >= N) return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, N)) return true;
            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

bool solveNQueens(int N) {
    if (N > MAX_N) {
        cout << "N is too large" << endl;
        return false;
    }
    int board[MAX_N][MAX_N] = {0}; // Initialize board with 0
    if (solveNQueensUtil(board, 0, N)) {
        printSolution(board, N);
        return true;
    } else {
        cout << "No solution exists" << endl;
        return false;
    }
}

int main() {
    int N;
    cout << "N-Queens Problem" << endl;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}

