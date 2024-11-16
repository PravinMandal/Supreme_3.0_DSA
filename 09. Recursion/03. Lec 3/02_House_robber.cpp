//leetcode: 198. House Robber

//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&nums , int i){
    int n=nums.size();

    //base case
    if(i>n){
        //array ke bahar aa gye
        return 0;
    }

        //include -> 0th index se start kr rhe h
        int includeAns=nums[i]+solve(nums,i+2);

        //exclude -> 0th index ko exclude krke 1st index se
        int excludeAns= 0+ solve(nums,i+1);

        //ab dono ka maximum nikal jis ghr ke combination mai zyada chori ho paayi usse return krdo
        return max(includeAns,excludeAns);  
}

int main(){

    vector<int>nums={2,7,9,3,1};
    int index=0;
    int ans=solve(nums,index);
    cout<<"max amount of money we can rob: "<<ans;

    return 0;
}