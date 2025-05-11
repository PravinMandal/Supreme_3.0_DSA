#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i) {
        int n = nums.size();
        if(i>=n) return 0;
        int includeAns = nums[i] + solve(nums, i+2);
        int excludeAns = 0 + solve(nums, i+1);
        int ans = max(includeAns, excludeAns);
        return ans;
    }

    int solveMem(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if(i>=n) return 0;

        if(dp[i] != -1) {
            return dp[i];
        }

        int includeAns = nums[i] + solveMem(nums, i+2, dp);
        int excludeAns = 0 + solveMem(nums, i+1, dp);
        dp[i] = max(includeAns, excludeAns);
        return dp[i];
    }

    int solveTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+10, 0);
        // dp[n] = 0;
        //upr jo base case tha usme array >= rhega toh return krna tha 0;
        //toh humne array ko hi zero se intialize kr diya ab saare aage ke zero hi honge
        //toh specifically nhi krna pdega sbko
        
        for(int i=n-1; i>=0; i--) {
            int includeAns = nums[i] + dp[i+2];
            //yaha hum i+2 kr rhe h toh array ke bahar bhi jaa skta hai isiliye check krke krna humesha
            int excludeAns = 0 + dp[i+1];
            dp[i] = max(includeAns, excludeAns);
        }
            return dp[0];
            // dp[0] return kr rhe h kyuki trick hai jo recursion wale mai pass krte h wahi return krna hota h idhr
    }

     int solveTabUsingSpaceOptimised(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+10, 0);
        // dp[n] = 0;
        //upr jo base case tha usme array >= rhega toh return krna tha 0;
        //toh humne array ko hi zero se intialize kr diya ab saare aage ke zero hi honge
        //toh specifically nhi krna pdega sbko
        int next1 = 0;
        int next2 = 0;
        
        for(int i=n-1; i>=0; i--) {
            // int curr = nums[i];
            int includeAns = nums[i] + next2;
            //yaha hum i+2 kr rhe h toh array ke bahar bhi jaa skta hai isiliye check krke krna humesha
            int excludeAns = 0 + next1;
            int curr = max(includeAns, excludeAns);
            
            //shifting: ye mai bhul jaata hu
            next2 = next1;
            next1 = curr;
        }
            return next1;
            // dp[0] return kr rhe h kyuki trick hai jo recursion wale mai pass krte h wahi return krna hota h idhr
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+10, -1);
        int index=0;
        // int ans = solveMem(nums, index, dp);
        // int ans = solveTabulation(nums);
        int ans = solveTabUsingSpaceOptimised(nums);
        return ans;
    }
};

int main() {
    Solution sol;

    //fixed input
    vector<int> nums = {2, 7, 9, 3, 1};

    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}
