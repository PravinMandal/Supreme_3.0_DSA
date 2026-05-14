//leetcode: 312. Burst Balloons

#include <bits/stdc++.h>
using namespace std;

//isme dp lagane ke baad bhi nhi chalega, bohot zyada brute force hai
class Solution {
public:

    int solveUsingRec(vector<int>& nums, vector<bool>& visited) {

        // Start with 1 because final answer subtracts this extra initialization
        int sum = 1;

        // Try bursting every unvisited balloon
        for(int i=0; i<nums.size(); i++) {

            if(visited[i]) continue;

            int left = i-1;
            int right = i+1;

            // Find nearest unburst balloon on left
            while(left>=0 && visited[left]) left--;

            // Find nearest unburst balloon on right
            while(right<nums.size() && visited[right]) right++;

            // Boundary balloons contribute 1
            left = left==-1 ? 1 : nums[left];
            right = right==nums.size() ? 1 : nums[right];

            // Mark current balloon as burst
            visited[i] = true;

            // Burst current balloon + solve remaining balloons
            sum = max(sum, (left*nums[i]*right) + solveUsingRec(nums, visited ));

            // Backtrack
            visited[i] = false;
        }

        return sum;
    }
    
    int solveUsingMem(vector<int>& nums, vector<bool>& visited, map<vector<bool>, int>& dp) {

        // Return cached result if state already computed
        if(dp.find(visited) != dp.end()) return dp[visited];

        int sum = 1;

        for(int i=0; i<nums.size(); i++) {

            if(visited[i]) continue;

            int left = i-1;
            int right = i+1;

            // Find nearest active balloon on left
            while(left>=0 && visited[left]) left--;

            // Find nearest active balloon on right
            while(right<nums.size() && visited[right]) right++;

            // Use 1 for out-of-bound virtual balloons
            left = left==-1 ? 1 : nums[left];
            right = right==nums.size() ? 1 : nums[right];

            // Mark balloon as burst
            visited[i] = true;

            // Try this bursting order
            sum = max(sum, (left*nums[i]*right) + solveUsingMem(nums, visited, dp));

            // Undo change for backtracking
            visited[i] = false;
        }

        // Store computed answer
        dp[visited] = sum;

        return sum;
    }

    int maxCoins(vector<int>& nums) {
        // return solveUsingRec(nums, visited)-1;

        // Track which balloons are burst
        vector<bool> visited(nums.size()+1, 0);

        // Memoization map using visited state
        map<vector<bool>, int> dp;

        return solveUsingMem(nums, visited, dp)-1;
    }
};

class Solution2 {
public:
    int solveUsingRec(vector<int>& nums, int start, int end) {
        if(start>end) return 0; // Base case: no balloons left to burst

        int sum = 0;

        // Try every balloon in current range as the LAST balloon to burst
        for(int i=start; i<=end; i++) {

            // If balloon i is burst last,
            // its adjacent balloons will be nums[start-1] and nums[end+1]
            int coins = (nums[start-1] * nums[i] * nums[end+1]) + (solveUsingRec(nums, start, i-1)) + (solveUsingRec(nums, i+1, end));

            // Keep maximum coins
            sum = max(sum, coins);
        }
        return sum;
    }
    
    int solveUsingMem(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if(start>end) return 0; // Base case

        // Return cached result if already computed
        if(dp[start][end] != -1) return dp[start][end];

        int sum = 0;

        for(int i=start; i<=end; i++) {

            // Same logic as recursion:
            // choose current balloon as last burst in this interval
            int coins = 
                (nums[start-1] * nums[i] * nums[end+1]) 
                + (solveUsingMem(nums, start, i-1, dp)) 
                + (solveUsingMem(nums, i+1, end, dp)
            );

            sum = max(sum, coins);
        }

        // Store computed result
        dp[start][end] = sum;

        return sum;
    }

    int solveUsingTab(vector<int>& nums) {
        int n = nums.size();

        // dp[start][end] stores max coins for interval [start...end]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Fill smaller intervals first
        for(int start = n-2; start>=1; start--) {
            for(int end=start; end<=n-2; end++) {
                // if(start>end) continue;

                int sum = 0;

                for(int i=start; i <= end; i++) {

                    // Consider balloon i as last balloon to burst
                    int coins = 
                        (nums[start-1] * nums[i] * nums[end+1]) 
                        + (dp[start][i-1]) 
                        + (dp[i+1][end])
                    ;

                    sum = max(sum, coins);
                }

                dp[start][end] = sum;
            }
        }

        return dp[1][n-2];
    }

    int maxCoins(vector<int>& nums) {

        // Add virtual balloons with value 1 at both ends
        // This avoids special boundary handling
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        // return solveUsingRec(nums, 1, n-2);

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveUsingMem(nums, 1, n-2, dp);

        return solveUsingTab(nums);
    }
};

int main() {

    Solution2 obj;

    // Hardcoded test cases
    vector<int> nums1 = {3,1,5,8};
    vector<int> nums2 = {1,5};
    vector<int> nums3 = {7};

    cout << "Test Case 1 Output: " << obj.maxCoins(nums1) << endl;
    cout << "Test Case 2 Output: " << obj.maxCoins(nums2) << endl;
    cout << "Test Case 3 Output: " << obj.maxCoins(nums3) << endl;

    return 0;
}