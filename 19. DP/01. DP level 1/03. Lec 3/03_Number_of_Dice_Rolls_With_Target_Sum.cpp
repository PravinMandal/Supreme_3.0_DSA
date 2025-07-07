//leetcode: 1155. Number of Dice Rolls With Target Sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long int mod = 1000000007;

    int solveRec(int n, int k, int target) {
        //base case
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;

        int ans = 0;
        for(int i=1; i<=k; i++) {
            ans += solveRec(n-1, k, target-i);
        }
        return ans%mod;
    }

    //2D DP
    int solveMem(int n, int k, int target, vector<vector<long long int>>& dp) {
        //base case
        if(target<0 || n<0) return 0;
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0;
        if(n!=0 && target==0) return 0;

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        long long int ans = 0;
        for(int i=1; i<=k; i++) {
            ans += solveMem(n-1, k, target-i, dp);
        }
        dp[n][target] = (ans%mod)%mod;
        return dp[n][target];
    }

    int solveTabulation(int n, int k, int target) {
        vector<vector<long long int>> dp(n+10, vector<long long int>(target+10, 0));

        dp[0][0] = 1;

        for(int j=1; j<=n; j++) {
            for(int trgt=1; trgt<=target; trgt++) {
                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    if(trgt-i >= 0) {
                        ans += dp[j-1][trgt-i];
                    }
                }
                dp[j][trgt] = ans%mod;
            }
        }
        return dp[n][target];
    }

    int solveTabulationSO(int n, int k, int target) {
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int j=1; j<=n; j++) {
            for(int trgt=1; trgt<=target; trgt++) {
                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    if(trgt-i >= 0) {
                        ans += prev[trgt-i];
                    }
                }
                curr[trgt] = ans%mod;
            }
            //shifting
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // return solveRec(n, k, target);

        vector<vector<long long int>> dp(n+10, vector<long long int>(target+10, -1));
        // return solveMem(n, k, target, dp);

        // return solveTabulation(n, k, target);

        return solveTabulationSO(n, k, target);
    }
};

int main() {
    Solution sol;

    int n = 2;      // Number of dice
    int k = 6;      // Number of faces on each die
    int target = 7; // Desired sum

    int ways = sol.numRollsToTarget(n, k, target);
    cout << "Number of ways to get sum " << target << " with " << n << " dice having " << k << " faces: " << ways << endl;

    return 0;
}
