//leetcode: 45. Jump Game II
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums, int i,int& ans, int step){
    //base case
    if(i==nums.size()-1){
        ans=min(ans,step);
        return;
    } //hume last index pr pohochna h kaise bhi jump krke
    if(i>=nums.size()) return; //aage nhi jaana h aage gya mtlb false , wahi condition chaiye jisme last index tk pohoch paaye
    if(nums[i]==0) return; //stuck ho gye agar zero aa gya kahin bich mai toh kyuki aage nhi badh skte

 
    for(int jump=1 ; jump<=nums[i] ; jump++){ 
        solve(nums,i+jump,ans,step+1);
    }

}

int solveMem(vector<int>& nums, int i, vector<int>& dp) {
    if(i == nums.size()-1) return 0; // last mai pohoch gye 0 jump krenge;
    if(i >= nums.size()) return INT_MAX; //invalid

    if(dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    for(int jump=1; jump<=nums[i]; jump++) {
        int recAns = solveMem(nums, i+jump, dp);
        if(recAns != INT_MAX)
            ans = min(ans, 1 + recAns);
    }
    dp[i] = ans;
    return dp[i];
}

int solveTab(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);

    dp[n-1] = 0;

    for(int i=n-2; i>=0; i--) {
        int ans = INT_MAX;
        for(int jump=1; jump<=nums[i] && i+jump<n ; jump++) {
            int recAns = dp[i+jump];
            if(recAns != INT_MAX)
                ans = min(ans, 1 + recAns);
        }
        dp[i] = ans;
    }
    return dp[0];
}

int jump(vector<int>& nums) {
    int index = 0;
    int ans = INT_MAX;
    int step = 0;
    // solve(nums, ans, index, step);

    //Memoisation
    int n = nums.size();
    vector<int> dp(n, -1);
    // int sol = solveMem(nums, index, dp);

    //tabulation
    int sol = solveTab(nums);

    return sol;
}

int canJump(vector<int>&nums)
{
    int index=0;
    int step=0;
    int ans=INT_MAX;
    solve(nums,index,ans,step);
    return ans;
}

int main(){

    vector<int>nums={2,3,1,1,4};
    int ans=canJump(nums);
    cout<<ans;

    return 0;
}