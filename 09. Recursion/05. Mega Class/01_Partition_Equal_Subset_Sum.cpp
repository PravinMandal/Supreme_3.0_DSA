//leetcode: 416. Partition Equal Subset Sum
//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include<bits/stdc++.h>
#include<vector>
#include<numeric> //accumulate use krne ke liye
using namespace std;

bool canPartition(vector<int>& nums, int target, int i){

    //base case
    if(target<0 || i==nums.size()) return false;
    if(target==0) return true;

    bool include=canPartition(nums,target-nums[i], i+1); //nums[i] ko include kiya isiliye target mai se minus kiya
    bool exclude=canPartition(nums,target,i+1) ;

    return include||exclude; // include krke aaye chahe exclude krke bss aana chahiye isiliye or kr diye ki agar koi bhi condition mai aise 2 subset bann rhe h then return true krdo

}

bool solve()
{
    vector<int> nums={1,5,11,5};
    int index=0;
    int sum=accumulate(nums.begin(), nums.end(), 0); //ye hume sum krke de dega starting se end tak end 0 se add krna chalu krega mtlb 0+ sum

    //agar array ka sum odd aata h toh hum usse 2 part mai divide kr hi nhi payenge
    // odd+odd= even
    // even+even= even
    // toh agar sum krke odd aaya toh hum nhi bana payenge aise 2 subset joki equal ho   
    if(sum%2 != 0){ 
        return false;
    }

    int target=sum>>1; //sum/2;
    bool ans=canPartition(nums, target, index);
    return ans;

}


int main(){

    bool ans=solve();
    cout<<ans;
    return 0;
}