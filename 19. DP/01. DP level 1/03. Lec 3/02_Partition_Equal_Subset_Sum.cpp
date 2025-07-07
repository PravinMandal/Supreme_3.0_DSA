//leetcode: 416. Partition Equal Subset Sum
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool solveRec(vector<int>& nums, int target, int i) {
        if(target < 0 || i >= nums.size()) return false;
        if(target == 0) return true;

        //nums[i] ko include kiya isiliye target mai se minus kiya
        bool inc = solveRec(nums, target-nums[i], i+1);
        bool exc = solveRec(nums, target, i+1);
        bool ans = inc || exc;
        return ans;
    }

    //2D DP
    bool solveMem(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if(target < 0 || i >= nums.size()) return false;
        if(target == 0) return true;

        if(dp[target][i] != -1) {
            return dp[target][i];
        }

        //nums[i] ko include kiya isiliye target mai se minus kiya
        bool inc = solveMem(nums, target-nums[i], i+1, dp);
        bool exc = solveMem(nums, target, i+1, dp);
        dp[target][i] = inc || exc;
        return dp[target][i];
    }

    bool solveTabulation(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(target+10, vector<bool>(n+10, 0));

        for(int i=0; i<=nums.size(); i++) {
            dp[0][i] = true;
        }

        for(int trgt=1; trgt<=target; trgt++) {
            for(int i=n-1; i>=0; i--) {
                bool inc = 0;
                if(trgt-nums[i] >= 0) {
                    inc = dp[trgt-nums[i]][i+1];
                }
                bool exc = dp[trgt] [i+1];
                dp[trgt][i] = inc || exc;
            }
        }
        return dp[target][0];
    }

    //space optimized
    bool solveTabulationSO(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<bool>> dp(target+10, vector<bool>(n+10, 0));
        vector<bool> curr(target+1, 0);
        vector<bool> next(target+1, 0);

            next[0] = true;

        for(int i=n-1; i>=0; i--) {
            for(int trgt=1; trgt<=target; trgt++) {
                bool inc = 0;
                if(trgt-nums[i] >= 0) {
                    inc = next[trgt-nums[i]];
                }
                bool exc = next[trgt];
                curr[trgt] = inc || exc;
            }
            //shifting
            next = curr;
        }
        return next[target];
    }

    bool solveTabulationSO2(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<bool>> dp(target+10, vector<bool>(n+10, 0));
        vector<bool> curr(target+1, 0);
        // vector<bool> next(target+1, 0);

            curr[0] = true;

        for(int i=n-1; i>=0; i--) {
            for(int trgt=target; trgt>=0; trgt--) {
                //target wale loop ko reverse kr diye
                //niche se upr jaa rhe h isme toh pehle ke ans overwrite nhi ho rhe
                bool inc = 0;
                if(trgt-nums[i] >= 0) {
                    inc = curr[trgt-nums[i]];
                }
                bool exc = curr[trgt];
                curr[trgt] = inc || exc;
            }
            //shifting
            // next = curr;
        }
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        //ye hume sum krke de dega starting se end tak end 0 se add krna chalu krega mtlb 0+ sum

        //agar array ka sum odd aata h toh hum usse 2 part mai divide kr hi nhi payenge
        // odd+odd= even
        // even+even= even
        // toh agar sum krke odd aaya toh hum nhi bana payenge aise 2 subset joki equal ho 
        if(sum%2 != 0) return false;
        int index = 0;
        int target = sum/2;
        int n = nums.size();
        // return solveRec(nums, target, index);

        vector<vector<int>> dp(target+1, vector<int>(n+1, -1));
        // return solveMem(nums, target, index, dp);

        // return solveTabulation(nums, target);

        // return solveTabulationSO(nums, target);

        return solveTabulationSO2(nums, target);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 5, 11, 5};  // Example input
    bool result = sol.canPartition(nums);

    if (result) {
        cout << "The array can be partitioned into two subsets with equal sum. : YES" << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum. : NO" << endl;
    }

    return 0;
}
