//leetcode: 494. Target Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& nums, int target, int i) {
        if(i>= nums.size()) return target == 0; // Base case: all numbers used, valid only if target becomes 0

        // Choose current number as positive
        int pos = solveUsingRec(nums, target+nums[i], i+1);

        // Choose current number as negative
        int neg = solveUsingRec(nums, target-nums[i], i+1);

        // Total possible ways
        return pos+neg;
    }
    
    int solveUsingMem(vector<int>& nums, int target, int i, unordered_map<int, unordered_map<int, int>>& dp) {
        if(i>= nums.size()) return target == 0; // Base case

        // Return memoized answer
        if(dp.count(target) && dp[target].count(i)) return dp[target][i];

        // Try positive sign
        int pos = solveUsingMem(nums, target+nums[i], i+1, dp);

        // Try negative sign
        int neg = solveUsingMem(nums, target-nums[i], i+1, dp);

        // Store computed result
        dp[target][i] = pos + neg;

        return pos+neg;
    }

    int solveUsingTab(vector<int>& nums, int& mainTarget) {

        /*
            dp[target][i] = number of ways to achieve "target"
            starting from index i
        */
        unordered_map<int, unordered_map<int, int>> dp;

        // Base case:
        // At end of array, only target 0 has 1 valid way
        dp[0][nums.size()] = 1;

        // Total sum helps define target search range
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Bottom-up DP
        for(int i=nums.size()-1; i>=0; i--) {

            for(int target=-total; target<=total; target++) {

                // If choosing '+' sign
                int pos = (dp.count(target+nums[i]) && dp[target+nums[i]].count(i+1)) ? dp[target+nums[i]][i+1] : 0;

                // If choosing '-' sign
                int neg = (dp.count(target-nums[i]) && dp[target-nums[i]].count(i+1)) ? dp[target-nums[i]][i+1] : 0;

                dp[target][i] = pos + neg;
            }
        }

        return dp[mainTarget][0];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // return solveUsingRec(nums, target, 0);

        // unordered_map<int, unordered_map<int, int>> dp;
        // return solveUsingMem(nums, target, 0, dp);

        return solveUsingTab(nums, target);
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;

    vector<int> nums2 = {1};
    int target2 = 1;

    vector<int> nums3 = {2, 3, 5, 6, 8, 10};
    int target3 = 10;

    cout << "Test Case 1 Output: " << obj.findTargetSumWays(nums1, target1) << endl;
    cout << "Test Case 2 Output: " << obj.findTargetSumWays(nums2, target2) << endl;
    cout << "Test Case 3 Output: " << obj.findTargetSumWays(nums3, target3) << endl;

    return 0;
}