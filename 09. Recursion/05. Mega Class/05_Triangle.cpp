//leetcode: 120. Triangle
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<vector<int>>&triangle,int row, int col){
    
    //base case
    if(row==triangle.size()-1){
        return triangle[row][col];
    }

    int down=triangle[row][col]+solve(triangle,row+1,col);
    int downPlus=triangle[row][col]+solve(triangle,row+1,col+1);

    return min(down,downPlus);
}

int solveMem(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
    if(row == triangle.size()-1) 
        return triangle[row][col];

    if(dp[row][col] != -1) {
        return dp[row][col];
    }

    int down = triangle[row][col] + solveMem(triangle, row+1, col, dp);
    int downplus = triangle[row][col] + solveMem(triangle, row+1, col+1, dp);
    dp[row][col] = min(down, downplus);
    return dp[row][col];
}

int solveTab(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int col=0; col<n; col++) {
        dp[n-1][col] = triangle[n-1][col];
    }

    for(int row=n-2; row>=0; row--) {
        for(int col=row; col>=0; col--) {
            int down = triangle[row][col] + dp[row+1][col];
            int downplus = triangle[row][col] + dp[row+1][col+1];
            dp[row][col] = min(down, downplus);
        }
    }
    return dp[0][0];
}

int minimumTotal(vector<vector<int>>& triangle) {
    int row = 0;
    int col = 0;
    // int ans = solve(triangle, row, col);

    //Memoisation
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // int ans = solveMem(triangle, row, col, dp);

    //Tabulation
    int ans = solveTab(triangle);
    return ans;
}

int main(){

    vector<vector<int>>triangle={
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    int ans=minimumTotal(triangle);
    cout<<ans;

    return 0;
}