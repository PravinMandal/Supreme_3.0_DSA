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

int minimumTotal(vector<vector<int>>&triangle){
    int row=0;
    int col=0;

    return solve(triangle,row,col);
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