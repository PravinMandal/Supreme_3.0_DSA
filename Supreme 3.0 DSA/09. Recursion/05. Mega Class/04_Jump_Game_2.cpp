//leetcode: 45. Jump Game II
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&nums, int i,int& ans, int step){
    //base case
    if(i==nums.size()-1){
        ans=min(ans,step);
        return;
    }; //hume last index pr pohochna h kaise bhi jump krke
    if(i>=nums.size()) return; //aage nhi jaana h aage gya mtlb false , wahi condition chaiye jisme last index tk pohoch paaye
    if(nums[i]==0) return; //stuck ho gye agar zero aa gya kahin bich mai toh kyuki aage nhi badh skte

 
    for(int jump=1 ; jump<=nums[i] ; jump++){ 
        solve(nums,i+jump,ans,step+1);
    }

}

int canJump(vector<int>&nums)
{
    int index=0;
    int step=0;
    int ans=INT32_MAX;
    solve(nums,index,ans,step);
    return ans;
}

int main(){

    vector<int>nums={2,3,1,1,4};
    int ans=canJump(nums);
    cout<<ans;

    return 0;
}