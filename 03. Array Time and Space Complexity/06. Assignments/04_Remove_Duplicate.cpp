//leetcode:- 26. Remove Duplicates from Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(ans.empty()){
                ans.push_back(nums[i]);
            }
            else if(ans.back()!=nums[i]){
                ans.push_back(nums[i]);
            }
        }
        copy(ans.begin(),ans.end(),nums.begin());
        return ans.size();
}

int main(){
    vector<int>nums{0,0,1,1,1,2,2,2,2};
    int ans=removeDuplicates(nums);
    cout<<ans<<endl;

    for(int i=0; i<ans; i++){
        cout<<nums[i]<<" ";
    }
    
}