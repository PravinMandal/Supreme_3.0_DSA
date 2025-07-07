//gfg: Painting the Fence
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, int k) {
        if(n == 1) return k;
        if(n == 2) return k + (k*(k-1));
        
        int ans = (k-1) * (solve(n-1, k) + solve(n-2, k));
        return ans;
    }
    
    //1D dp
    int solveMem(int n, int k, vector<int>& dp) {
        if(n == 1) return k;
        if(n == 2) return k + (k*(k-1));
        
        dp[1] = k;
        dp[2] = k + (k*(k-1));
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        dp[n] = (k-1) * (solveMem(n-1, k, dp) + solveMem(n-2, k, dp));
        return dp[n];
    }
    
    int solveTabulation(int n, int k) {
        vector<int> dp(n+10, -1);
        
        dp[1] = k;
        dp[2] = k + (k*(k-1));
        
        for(int i=3; i<=n; i++) {
            dp[i] = (k-1) * (dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
    
    //space optimized
    int solveTabulationSO(int n, int k) {
        // vector<int> dp(n+10, -1);
        
        int prev2 = k;
        int prev1 = k + (k*(k-1));
        if(n == 1) return prev2;
        if(n == 2) return prev1;
        int curr = 0;
        for(int i=3; i<=n; i++) {
            curr = (k-1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int countWays(int n, int k) {
        // return solve(n,k);

        vector<int>dp(n+10, -1);
        // return solveMem(n, k, dp);
        
        // return solveTabulation(n, k);
        
        return solveTabulationSO(n, k);
    }
};

int main() {
    Solution sol;

    int n = 4; // number of posts
    int k = 3; // number of colors

    int ways = sol.countWays(n, k);
    cout << "Number of ways to paint " << n << " posts using " << k << " colors: " << ways << endl;

    return 0;
}
