//leetcode: 3702. Longest Subsequence With Non-Zero Bitwise XOR

#include <bits/stdc++.h>
using namespace std;


// TLE deta hai, this is not the correct way
class Solution {
public:
    int solve(vector<int>& nums, int i, int x,
              vector<unordered_map<int, int>>& dp) {

        // End of array
        if (i == nums.size()) {
            // Current XOR is valid only if non-zero
            // saare subSequence try karlo and agar last mai non zero aaya toh sahi hai
            //, warna -1e9 return kardo
            return x != 0 ? 0 : -1e9;
        }

        // Already calculated
        if (dp[i].count(x))
            return dp[i][x];

        // Take nums[i]
        int take = 1 + solve(nums, i + 1, x ^ nums[i], dp);

        // Don't take nums[i]
        int skip = solve(nums, i + 1, x, dp);

        return dp[i][x] = max(take, skip);
    }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        // dp[i] stores answers for every XOR value encountered
        // starting from index i.
        vector<unordered_map<int, int>> dp(n);

        // Try every possible subsequence by either taking
        // or skipping each element.
        int ans = solve(nums, 0, 0, dp);

        // If no subsequence with non-zero XOR exists, return 0.
        return max(0, ans);
    }
};

// optimal solution
class Solution2 {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        bool nonZero = false;

        // Calculate XOR of all elements.
        // If XOR becomes non-zero at any point, there exists
        // a non-zero XOR subsequence.
        for(int i : nums) {
            x ^= i;
            if(x != 0) nonZero = true;
        }

        // If XOR of the complete array is non-zero,
        // the entire array is the longest valid subsequence.
        if(x != 0) return n;

        // If the total XOR is zero but some prefix XOR was non-zero,
        // removing one suitable element can make the XOR non-zero.
        return nonZero ? n-1 : 0;
    }
};


int main() {

    Solution2 obj;

    // Hardcoded Test Case 1
    vector<int> nums1 = {1, 2, 3};

    // Hardcoded Test Case 2
    vector<int> nums2 = {2, 3, 4};

    // Hardcoded Test Case 3
    vector<int> nums3 = {0, 0, 0};

    // Hardcoded Test Case 4
    vector<int> nums4 = {1, 1, 1, 1};

    cout << "Test Case 1 Output: " << obj.longestSubsequence(nums1) << endl;
    cout << "Test Case 2 Output: " << obj.longestSubsequence(nums2) << endl;
    cout << "Test Case 3 Output: " << obj.longestSubsequence(nums3) << endl;
    cout << "Test Case 4 Output: " << obj.longestSubsequence(nums4) << endl;

    return 0;
}