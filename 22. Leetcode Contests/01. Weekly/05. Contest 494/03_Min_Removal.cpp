//leetcode: 3877. Minimum Removals to Achieve Target XOR

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int INF = 1e9;
    vector<vector<int>> dp;

    // This recursive function decides for each index:
    // whether to REMOVE the element or KEEP it
    // x = required XOR we still need to achieve using removed elements
    int solve(vector<int>& nums, int i, int x) {

        // Base case: if all elements processed
        if(i == n) {

            // If required XOR becomes 0 → valid removal set
            // else not possible
            return (x == 0) ? 0 : INF;
        }

        // Memoization check
        if(dp[i][x] != -1) return dp[i][x];

        // Option 1: Remove current element
        // So XOR gets updated: x ^ nums[i]
        // +1 because we removed one element
        int incl = 1 + solve(nums, i+1, x ^ nums[i]);

        // Option 2: Do not remove current element
        int excl = solve(nums, i+1, x);

        // Take minimum removals
        return dp[i][x] = min(incl, excl);
    }

    int minRemovals(vector<int>& nums, int target) {

        n = nums.size();

        // Calculate total XOR of array
        int totalXor = 0;
        for(int i : nums) {
            totalXor ^= i;
        }

        // ---------------- CORE IDEA ----------------
        // We want final XOR = target
        // Let removed elements XOR = R
        // Then:
        // totalXor ^ R = target
        // ⇒ R = totalXor ^ target
        int xorRemovalTarget = totalXor ^ target;
        
        // Maximum XOR range (given constraint ~ 2^14)
        int maxiXor = 1 << 14; // 16384
        
        // Initialize DP table with -1
        dp.assign(n, vector<int>(maxiXor, -1));

        // Solve using recursion + memoization
        int ans = solve(nums, 0, xorRemovalTarget);
    
        // If not possible, return -1
        return (ans >= INF) ? -1 : ans;
    }
};

int main() {

    // Hardcoded test case
    vector<int> nums = {1, 2, 3, 4};
    int target = 4;

    Solution obj;

    int result = obj.minRemovals(nums, target);

    cout << "Minimum removals required: " << result << endl;

    return 0;
}