//leetcode ques: 213. House Robber II
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&nums , int s , int e){
    // int n=nums.size();

    //base case
    if(s>e){
        //array ke bahar aa gye
        return 0;
    }

        //include -> 0th index se start kr rhe h
        int includeAns=nums[s]+solve(nums,s+2,e);

        //exclude -> 0th index ko exclude krke 1st index se
        int excludeAns= 0+ solve(nums,s+1,e);

        //ab dono ka maximum nikal jis ghr ke combination mai zyada chori ho paayi usse return krdo
        return max(includeAns,excludeAns);  
}


int main(){

    vector<int> nums={1,2,3,1};
    int n=nums.size();

    //hume pta ki question bolna chahta h ki hume circular maan kr chalna h and jo array ka last wala element h wo mtlb neigbour h and hum adjacent ghar mai chori nhi kr skte 

    //first case mai hum first ghar mai chori krenge and last wale mai nhi krenge isiliye n-2 kiye taaki wo ghr exclude ho jaye
    int option1=solve(nums,0,n-2);
    int option2=solve(nums,1,n-1);
    //second case mai hum first wale ghr ko ignore krke last wale ko include krenge n-1 krke taaki wo last wale mai kr paaye and at the same time first wale mai na kre 

    int ans=max(option1,option2);
    cout<<ans;





    return 0;
}