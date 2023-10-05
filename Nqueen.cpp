// N Queen problem using backtracking 
#include <bits/stdc++.h>
#include <iostream>
#define N 4
using namespace std;

// Print solution function
void printSol(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
           if(board[i][j])
            cout << "Q ";
           else cout<<". ";
        printf("\n");
    }
}

// Check if queen can be placed on board[row][col] function
bool isSafe(int board[N][N], int row, int col){
    int i;
    int j;
    
    // Check rows 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    // Check upper diagonal 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    // Check lower diagonal 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}

// Solve N-queen problem using backtracking function
bool nQueen(int board[N][N], int col)
{
    
    // base case: If all queens are placed = return true
    if (col >= N)           
        return true;
 
    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {       
         
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
             
            board[i][col] = 1;  // Place this queen in board[i][col]
 
            // recur to place rest of the queens
            if (nQueen(board, col + 1))
                return true;
 
            board[i][col] = 0; // BACKTRACK
        }
    }
 
    
    return false;   // If the queen cannot be placed in any row in this column col then return false
}

// Solves N-queen problem visually function
bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
 
    if (nQueen(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }
 
    printSol(board);
    return true;
}
int main() {
    
    solveNQ();
    return 0;

}