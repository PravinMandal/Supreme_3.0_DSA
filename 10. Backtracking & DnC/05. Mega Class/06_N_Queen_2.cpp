//leetcode: 52. N-Queens II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> leftCheck;
    unordered_map<int, bool> upperLeftDiagonal;
    unordered_map<int, bool> lowerLeftDiagonal;

    // This function checks if placing a queen at (row, col) is safe
    // We use hash maps to track:
    // 1. Rows (leftCheck)
    // 2. Upper-left diagonals (row - col)
    // 3. Lower-left diagonals (row + col)
    bool isSafe(int row, int col) {
        if(leftCheck[row] == true) return false;
        if(upperLeftDiagonal[row-col] == true) return false;
        if(lowerLeftDiagonal[row+col] == true) return false;
        return true;
    }

    // Backtracking function to place queens column by column
    void solve(vector<vector<char>>& board, int n, int j, int& ans) {

        // If all columns are filled, we found a valid configuration
        if(j>=n) {
            ans++;
            return;
        }

        // Try placing queen in every row of current column
        for(int i=0; i<n; i++) {

            // Check if position is safe
            if(isSafe(i, j)) {

                // Place queen
                board[i][j] = '1';

                // Mark row and diagonals as occupied
                leftCheck[i] = true;
                upperLeftDiagonal[i-j] = true;
                lowerLeftDiagonal[i+j] = true;

                // Move to next column
                solve(board, n, j+1, ans);

                // Backtracking: remove queen and unmark
                leftCheck[i] = false;
                upperLeftDiagonal[i-j] = false;
                lowerLeftDiagonal[i+j] = false;
                board[i][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        int ans = 0;

        // Initialize empty board
        vector<vector<char>> board(n, vector<char>(n, '.'));

        // Start placing queens from column 0
        solve(board, n, 0, ans);

        return ans;
    }
};

int main() {

    // Hardcoded test case
    int n = 4;

    Solution obj;

    int result = obj.totalNQueens(n);

    cout << "Total number of distinct solutions: " << result << endl;

    return 0;
}