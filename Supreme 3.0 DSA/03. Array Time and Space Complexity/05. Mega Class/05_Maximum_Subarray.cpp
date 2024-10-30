//kadane's algorithm hai isme , boht boht important h boht baar interview mai pucha h
//isme hume ek array milega usme se maximum number nikalna h subarray ko add krke
// leetcode question no 53

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;


//naive mtlb brute force method mtlb bina kisi optimization ke
int naive(vector<int>& nums){
    int n=nums.size();
    int ans=INT_MIN;

    for(int i=0 ;i<n ; i++){
        int sum=0;
        for(int j=i ; j<n ; j++){
            sum=sum+nums[j];
            ans=max(ans,sum);
        }
    }
    return ans;
}


int kadaneAlgo(vector<int>& nums){
    int ans=INT_MIN;
    int sum=0;
    for(int i=0 ; i<nums.size() ; i++){
        int num=nums[i];
        sum=sum+num;
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }
    }
    return ans;
    
}

int main(){

    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};

    int ans=naive(nums);
    cout<<"Maximum addition of elements of subarray: "<<ans<<endl;

    int ans2=kadaneAlgo(nums);
    cout<<"Maximum addition of elements of subarray: "<<ans2<<endl;

    return 0;
}