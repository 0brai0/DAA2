#include <stdio.h>
#include <stdbool.h>

#define N 8 // Number of queens

bool isSafe(int board[N][N], int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool solveNQueensUtil(int board[N][N], int row) {
    if (row == N) {
        printSolution(board);
        printf("\n");
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            res = solveNQueensUtil(board, row + 1) || res;
            board[row][col] = 0; // Backtrack
        }
    }

    return res;
}

void solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        printf("No solution exists for %d-Queens problem.\n", N);
    }
}

int main() {
    solveNQueens();
    return 0;
}
