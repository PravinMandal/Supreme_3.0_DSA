//gfg: 0 - 1 Knapsack Problem
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int solveUsingRec(vector<int>& val, vector<int>& wt, int capacity, int index) {
        //base case
        int n = val.size();
        if(index >= n) return 0;
        
        //incl/ excl
        int incl = 0;
        if(wt[index] <= capacity) {
            incl = val[index] + solveUsingRec(val, wt, capacity-wt[index], index+1);
        }
        int exc = 0 + solveUsingRec(val, wt, capacity, index+1);
        int finalAns = max(incl, exc);
        return finalAns;
    }
    
    //2D dp
    int solveMem(vector<int>& val, vector<int>& wt, int capacity, int index, vector<vector<int>>& dp) {
        //base case
        int n = val.size();
        if(index >= n) return 0;
        
        if(dp[capacity][index] != -1) {
            return dp[capacity][index];
        }
        
        //incl/ excl
        int incl = 0;
        if(wt[index] <= capacity) {
            incl = val[index] + solveMem(val, wt, capacity-wt[index], index+1, dp);
        }
        int exc = 0 + solveMem(val, wt, capacity, index+1, dp);
        dp[capacity][index] = max(incl, exc);
        
        return dp[capacity][index];
    }
    
    //tabulation 
    int solveTabulation(vector<int>& val, vector<int>& wt, int capacity) {
        //create a dp array
        int n = val.size();
        vector<vector<int>> dp(capacity+10, vector<int>(n+10, 0));
        
        //analyse base case and array update kro
        //humne 0 se hi initialize kr diya kyuki sabko jo n se bada hota 0 hi krna pdta
        
        //rec range
        //capacity: capacity->0
        //index: 0->n
        
        for(int cpty=0; cpty<=capacity; cpty++) {
            for(int index=n-1; index>=0; index--) {
                //incl/ excl
                int incl = 0;
                if(wt[index] <= cpty) {
                    incl = val[index] + dp[(cpty-wt[index])] [index+1];
                }
                int exc = 0 + dp[cpty][index+1];
                dp[cpty][index] = max(incl, exc);
            }
        }
        return dp[capacity][0];
    }
    
    //space optimized
    int solveTabulationSO(vector<int>& val, vector<int>& wt, int capacity) {
        //create a dp array
        int n = val.size();
        // vector<vector<int>> dp(capacity+10, vector<int>(n+10, 0));
        vector<int> prev(capacity+10, 0);
        vector<int> curr(capacity+10, 0);
        
        //analyse base case and array update kro
        //humne 0 se hi initialize kr diya kyuki sabko jo n se bada hota 0 hi krna pdta
        
        //rec range
        //capacity: capacity->0
        //index: 0->n
        
        for(int index=n-1; index>=0; index--) {
            for(int cpty=0; cpty<=capacity; cpty++) {
                //incl/ excl
                int incl = 0;
                if(wt[index] <= cpty) {
                    incl = val[index] + curr[(cpty-wt[index])];
                }
                int exc = 0 + curr[cpty];
                prev[cpty] = max(incl, exc);
                
            }
                //shifting, very important
                curr = prev;
        }
        return curr[capacity];
    }
    
    int solveTabulationSO2(vector<int>& val, vector<int>& wt, int capacity) {
        //create a dp array
        int n = val.size();
        // vector<vector<int>> dp(capacity+10, vector<int>(n+10, 0));
        // vector<int> prev(capacity+10, 0);
        vector<int> curr(capacity+10, 0);
        
        //analyse base case and array update kro
        //humne 0 se hi initialize kr diya kyuki sabko jo n se bada hota 0 hi krna pdta
        
        //rec range
        //capacity: capacity->0
        //index: 0->n
        
        for(int index=n-1; index>=0; index--) {
            for(int cpty=capacity; cpty>=0; cpty--) {
                //incl/ excl
                int incl = 0;
                if(wt[index] <= cpty) {
                    incl = val[index] + curr[(cpty-wt[index])];
                }
                int exc = 0 + curr[cpty];
                curr[cpty] = max(incl, exc);
                
            }
                //shifting, very important
                // curr = prev;
        }
        return curr[capacity];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        int capacity = W;
        int index = 0;
        // int ans = solveUsingRec(val, wt, capacity, index);
        
        vector<vector<int>> dp(capacity+10, vector<int>(n+10, -1));
        // int ans = solveMem(val, wt, capacity, index, dp);
        
        // int ans = solveTabulation(val, wt, capacity);
        
        // int ans = solveTabulationSO(val, wt, capacity);
        
        int ans = solveTabulationSO2(val, wt, capacity);
        return ans;
        
    }
};

int main() {
    Solution sol;

    // fixed input
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    int result = sol.knapsack(W, val, wt);
    cout << "Maximum value in 0-1 Knapsack: " << result << endl;

    return 0;
}
