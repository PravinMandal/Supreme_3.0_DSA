//79. Word Search
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word, int row, int col, int i) {
        // Base case: If the entire word is found
        if (i == word.size()) return true;

        // Check boundaries and if the current cell matches the word character
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[i] || board[row][col] == '%') {
            return false;
        }

        // Mark the current cell as visited
        char temp = board[row][col];
        board[row][col] = '%';

        // Recursively check in all four directions
        bool found = solve(board, word, row, col - 1, i + 1) // left
                  || solve(board, word, row, col + 1, i + 1) // right
                  || solve(board, word, row - 1, col, i + 1) // up
                  || solve(board, word, row + 1, col, i + 1); // down

        // Unmark the cell (backtracking)
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(board, word, i, j, 0)) { // Start searching from the current cell
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // Initialize the board
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    // Word to search
    string word="ABFDE";
    

    // Create an instance of the Solution class
    Solution solution;

    // Check if the word exists in the board
    bool result = solution.exist(board, word);

    // Print the result
    if (result) {
        cout << "The word \"" << word << "\" exists in the board." << endl;
    } else {
        cout << "The word \"" << word << "\" does not exist in the board." << endl;
    }

    return 0;
}
