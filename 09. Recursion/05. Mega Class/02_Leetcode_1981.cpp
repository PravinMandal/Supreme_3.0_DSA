//1981. Minimize the Difference Between Target and Chosen Elements
// You are given an m x n integer matrix mat and an integer target.

// Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.

// Return the minimum absolute difference.

// The absolute difference between two numbers a and b is the absolute value of a - b.

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>>&mat , int& target,int sum , int row ){
    //base case
    if(row==mat.size()){
        return abs(target-sum);
    }

    int ans=INT32_MAX;
    for(int col=0 ; col<mat[row].size() ; col++){
        int reAns=solve(mat,target,sum+ mat[row][col] , row+1);
        ans=min(ans,reAns);
    }
    return ans;
}

int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum=0 , row=0;
        return solve(mat,target,sum, row);

    }


int main(){

    vector<vector<int>> mat={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int target=13;

    int ans=minimizeTheDifference(mat,target);
    cout<<ans;

    return 0;
}