//leetcode: 54. Spiral Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total_element = row*col;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;

        int count = 0;
        while(count < total_element) {

            //printing starting row
            for(int i=startingCol; i<=endingCol && count<total_element; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++; 
            //taaki next row mai chale jaye and same element repeat na ho
            //aisehi saare loop ke baad krna h 
            //issi se spiral banega
            //just dry run and know

            //printing ending col
            for(int i=startingRow; i<=endingRow && count<total_element; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            //printing ending row
            for(int i=endingCol; i>=startingCol && count<total_element; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            //printing starting col
            for(int i=endingRow; i>=startingRow && count<total_element; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};

int main() {
    // Example Test Case with a bigger matrix:
    // Input:
    // matrix = {
    //   { 1,  2,  3,  4,  5,  6},
    //   { 7,  8,  9, 10, 11, 12},
    //   {13, 14, 15, 16, 17, 18},
    //   {19, 20, 21, 22, 23, 24},
    //   {25, 26, 27, 28, 29, 30}
    // }
    // Expected Spiral Order Output:
    // [1 2 3 4 5 6 12 18 24 30 29 28 27 26 25 19 13 7 8 9 10 11 17 23 22 21 20 14 15 16]
    
    vector<vector<int>> matrix = {
        { 1,  2,  3,  4,  5,  6},
        { 7,  8,  9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}
    };
    
    Solution sol;
    vector<int> ans = sol.spiralOrder(matrix);
    
    cout << "Spiral Order: ";
    for(auto num : ans) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
