#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int board[MAX][MAX];
// Function to print the solution
void printSolution(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%s ", board[i][j] ? "Q" : ".");
        printf("\n");
    }
}
// Function to check if a queen can be placed on board[row][col]
bool isSafe(int row, int col, int N) {
    int i, j;
    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
// A recursive utility function to solve the N-Queens problem
bool solveNQueensUtil(int col, int N) {
    // If all queens are placed then return true
    if (col >= N)
        return true;
    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(i, col, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;
            // Recur to place the rest of the queens
            if (solveNQueensUtil(col + 1, N))
                return true;
            // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0; // Remove the queen from board[i][col]
        }
    }
    // If the queen cannot be placed in any row in this column, then return false
    return false;
}
// This function solves the N-Queens problem using backtracking. It mainly uses solveNQueensUtil()
bool solveNQueens(int N) {
    // Initialize the board with zeros
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    if (solveNQueensUtil(0, N) == false) {
        printf("Solution does not exist\n");
        return false;
    }
    printSolution(N);
    return true;
}
int main() {
    int N;
    // Take input from the user for the size of the board
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);
    // Solve the N-Queens problem
    solveNQueens(N);
    return 0;
}
