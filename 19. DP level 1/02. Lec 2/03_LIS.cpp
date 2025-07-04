//Leetcode: 300. Longest Increasing Subsequence
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& arr, int curr, int prev){
        //base case
        if(curr >= arr.size()) {
            return 0;
        }
        //prev-> index of element that was included in subsequence latest in the traversal

        int inc = 0;
        if(prev == -1 || arr[curr] > arr[prev] ){
            inc = 1 + solveUsingRec(arr,curr+1, curr);
        }
        int exc = 0 + solveUsingRec(arr, curr+1, prev);
        int finalAns = max(inc,exc);
        return finalAns;
    }//2d dp

    int solveUsingMem(vector<int>& arr, int curr, int prev, vector<vector<int> >& dp){
        //base case
        if(curr >= arr.size()) {
            return 0;
        }
        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }
        //prev-> index of element that was included in subsequence latest in the traversal

        int inc = 0;
        if(prev == -1 || arr[curr] > arr[prev] ){
            inc = 1 + solveUsingMem(arr,curr+1, curr, dp);
        }
        int exc = 0 + solveUsingMem(arr, curr+1, prev, dp);
        dp[curr][prev+1] = max(inc,exc);
        return dp[curr][prev+1];
    }

    int solveUsingTab(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        
        //Rec ranges
        //curr -> 0 to n
        //prev -> -1 to curr
        //reverse it and apply loop 
        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--) {
                int inc = 0;
                if(prev == -1 || arr[curr] > arr[prev] ){
                    inc = 1 + dp[curr+1][curr+1];
                }
                int exc = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(inc,exc);
            } 
        }
        //return dp[0][-1];
        //ye return krna tha but -1 thodi access hoga
        //toh ab jo column wale hai sabme +1 krdo
        return dp[0][0];
    }

    int solveUsingTabSO(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        
        //Rec ranges
        //curr -> 0 to n
        //prev -> -1 to curr
        //reverse it and apply loop 
        vector<int>currRow(n+1, 0);
        vector<int>next(n+1, 0);
        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--) {
                int inc = 0;
                if(prev == -1 || arr[curr] > arr[prev] ){
                    inc = 1 + next[curr+1];
                }
                int exc = 0 + next[prev+1];
                currRow[prev+1] = max(inc,exc);
            } 
            //shifting
            next = currRow;
        }

        return currRow[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        //lastIndex
        int prev = -1;
        //return solveUsingRec(nums,curr,prev);
        //OBSERVATION: prev hmesha curr se piche rehne wala h 
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        // return solveUsingMem(nums,curr,prev, dp);
        // return solveUsingTab(nums);

        //TabulationSO
        return solveUsingTabSO(nums);
    }
};

int main() {
    Solution sol;

    // fixed input
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int result = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}
