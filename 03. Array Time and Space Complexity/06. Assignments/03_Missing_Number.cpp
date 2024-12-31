#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;

class Solution{
public:
    int missingNumber(vector<int>&nums){
         int n=nums.size();
        unordered_map<int,int>mapping;
        for(int i=0;i<n; i++){
            mapping[nums[i]]=i;
        }
        for(int i=0; i<=n; i++){
            if(mapping.find(i)!=mapping.end()){

            }
            else{
                return i;
            }
        }
        return -1;
    }

    //ye sabse mst hai
    int missingNumber2(vector<int>& nums) {
        int n=nums.size();
        int num=(n*(n+1))/2;
        int sum=accumulate(nums.begin(), nums.end(), 0);
        return num-sum;
    }

    int missingNumber3(vector<int>& nums){
        int ans=0;
        int n=nums.size();
        //xor all value of array
        for(int i=0; i<n; i++){
            ans^=nums[i];
        }

        //xor all range values(index) [0,N] 
        for(int i=0; i<=n; i++){
            ans^=i;
        }
        return ans;
    }
};

int main(){

    vector<int>nums={0,1,2,3,5,6,7,8,9};
    Solution sol;
    int ans=sol.missingNumber2(nums);

    if(ans!=-1){
        cout<<"the missing number is: "<<ans<<endl;
    }

    return 0;
}