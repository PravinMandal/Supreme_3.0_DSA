//leetcode: 1 Two Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

        int s = 0;
        int e = nums.size()-1;
        while(s<e) {
            int sum = arr[s].first + arr[e].first;
            if(sum == target) {
                ans.push_back(arr[s].second);
                ans.push_back(arr[e].second);
                return ans;
            }
            if(sum < target) s++;
            else e--;
        }
        return ans;
    }
};

int main() {
    // Hardcoded test case instead of cin
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> result = obj.twoSum(nums, target);

    cout << "Indices: ";
    for(int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
