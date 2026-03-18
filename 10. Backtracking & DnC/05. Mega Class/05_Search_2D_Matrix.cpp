//leetcode: 240. Search a 2D Matrix II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0; 
        int j = matrix[0].size()-1;

        // Start from top-right corner
        // Move left if current > target
        // Move down if current < target
        while(i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size()) {

            // If target found
            if(matrix[i][j] == target) return true;

            // If current element is greater than target,
            // eliminate current column by moving left
            else if(matrix[i][j] > target) j--;

            // If current element is smaller than target,
            // eliminate current row by moving down
            else if(matrix[i][j] < target) i++;
        }

        // Target not found
        return false;
    }
};

int main() {

    // Hardcoded test case
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target = 5;

    Solution obj;

    bool result = obj.searchMatrix(matrix, target);

    if(result) cout << "Target found in matrix" << endl;
    else cout << "Target not found in matrix" << endl;

    return 0;
}