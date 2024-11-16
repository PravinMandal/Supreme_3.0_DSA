// leetcode: 55. Jump Game
//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//Return true if you can reach the last index, or false otherwise.

#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int>&nums, int i){
    //base case
    if(i==nums.size()-1) return true; //hume last index pr pohochna h kaise bhi jump krke
    if(i>=nums.size()) return false; //aage nhi jaana h aage gya mtlb false , wahi condition chaiye jisme last index tk pohoch paaye
    if(nums[i]==0) return false; //stuck ho gye agar zero aa gya kahin bich mai toh kyuki aage nhi badh skte

    bool recAns=false;
    for(int jump=1 ; jump<=nums[i] ; jump++){ 
        recAns=recAns||solve(nums,i+jump);
    }
    return recAns;
}

bool canJump(vector<int>&nums)
{
    int index=0;
    return solve(nums,index);
}

int main(){

    vector<int>nums={2,3,1,1,4};
    bool ans=canJump(nums);
    cout<<ans;

    return 0;
}