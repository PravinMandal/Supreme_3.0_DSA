//279. Perfect Squares
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int solveUsingRec(int n) {
        if(n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        for(int i=1; i<=sqrt(n); i++) {
            int num = i*i;
            if(n-num >= 0) {
                int recAns = solveUsingRec(n-num);
                if(recAns != INT_MAX) {
                    ans = min(ans, 1 + recAns);
                }
            }
        }
        return ans;        
    }

    int solveUsingMem(int n, vector<int>& dp) {
        if(n == 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }

        int ans = INT_MAX;
        for(int i=1; i<=sqrt(n); i++) {
            int num = i*i;
            if(n-num >= 0) {
                int recAns = solveUsingMem(n-num, dp);
                if(recAns != INT_MAX) {
                    ans = min(ans, 1 + recAns);
                }
            }
        }
        dp[n] = ans;
        return dp[n];        
    }

    int solveUsingTab(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;

        for(int k=1; k<=n; k++) {
            int ans = INT_MAX;
            for(int i=1; i<=sqrt(k); i++) {
                int num = i*i;
                if(k-num >= 0) {
                    int recAns = dp[k-num];
                    if(recAns != INT_MAX) {
                        ans = min(ans, 1 + recAns);
                    }
                }
            }
            dp[k] = ans;
        }
        return dp[n];
    }

    int numSquares(int n) {
        //Recursion
        // int ans = solveUsingRec(n);

        //Memoisation
        vector<int> dp(n+1, -1);
        // int ans = solveUsingMem(n, dp);

        //Tabulation
        int ans = solveUsingTab(n);
        if(ans == INT_MAX) {
            return n;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 12; // you can change this value to test other cases
    cout << "Minimum number of perfect squares that sum up to " << n << " is: " << sol.numSquares(n) << endl;
    return 0;
}
