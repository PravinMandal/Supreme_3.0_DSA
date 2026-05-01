//leetcode: 96. Unique Binary Search Trees

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(int n) {
        if(n <= 1) return 1; // Base case: 0 or 1 node has exactly 1 unique BST

        int sum = 0;

        // Try every number as root
        for(int i=1; i<=n; i++) {
            // Left subtree size = i-1, Right subtree size = n-i
            // Total ways = (ways of left) * (ways of right)
            sum += solveUsingRec(i-1) * solveUsingRec(n-i);
        }

        return sum; // Total unique BSTs
    }

    int solveUsingMem(int n, vector<int>& dp) {
        if(n <= 1) return 1;

        // If already computed, return stored value
        if(dp[n] != -1) return dp[n];

        int sum = 0;

        for(int i=1; i<=n; i++) {
            sum += solveUsingMem(i-1, dp) * solveUsingMem(n-i, dp);
        }

        // Store result
        dp[n] = sum;

        return sum;
    }

    int solveUsingTab(int N) {
        // dp[n] = number of unique BSTs using n nodes
        vector<int> dp(N+1, -1);

        dp[0] = 1; // Empty tree
        dp[1] = 1; // Single node tree

        for(int n=2; n<=N; n++) {
            int sum = 0;

            // Consider each node as root
            for(int i=1; i<=n; i++) {
                sum += dp[i-1] * dp[n-i];
            }

            dp[n] = sum; // Store computed value
        }

        return dp[N];
    }
    
    int numTrees(int n) {
        // return solveUsingRec(n);

        // vector<int> dp(n+1, -1);
        // return solveUsingMem(n, dp);

        return solveUsingTab(n); // Using tabulation (most efficient here)
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    int n1 = 3;
    int n2 = 5;

    cout << "Number of unique BSTs for n = " << n1 << " is: " << obj.numTrees(n1) << endl;
    cout << "Number of unique BSTs for n = " << n2 << " is: " << obj.numTrees(n2) << endl;

    return 0;
}