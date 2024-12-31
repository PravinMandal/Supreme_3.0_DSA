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

//ye zyada aacha h, simple hai
int removeDuplicates2(vector<int>& nums) {
        int i=1;
        int j=0;
        while(i<nums.size()){
            if(nums[j]==nums[i]){
                i++;
            }
            else nums[++j]=nums[i++];
            // else{
            //     j++;
            //     nums[j]=nums[i];
            //     i++;
            // }
        }
        return j+1;
        //j hoga jis index pr j khada h 
        //j ke position pr aur uske piche saare unique h
        //vector zero index based hota h
        //total number of unique elements j+1;
    }

int main(){
    vector<int>nums{0,0,1,1,1,2,2,2,2};
    int ans=removeDuplicates2(nums);
    cout<<ans<<endl;

    for(int i=0; i<ans; i++){
        cout<<nums[i]<<" ";
    }
    
}