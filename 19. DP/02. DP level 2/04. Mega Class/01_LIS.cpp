//leetcode: 300. Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // This array will store the smallest possible tail
        // for increasing subsequences of different lengths
        vector<int> arr;

        // Initialize with first element
        arr.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++) {

            // If current element is greater than last element of arr,
            // we can extend the LIS
            if(arr.back() < nums[i]) {
                arr.push_back(nums[i]);
                continue;
            }

            // Otherwise, find the position to replace using binary search
            // This keeps arr sorted and optimal
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);

            int index = it - arr.begin();

            // Replace element at found index
            // This ensures smallest possible tail value
            arr[index] = nums[i];
        }

        // Size of arr gives length of LIS
        return arr.size();
    }
};

int main() {

    // Hardcoded test case
    vector<int> nums = {10,9,2,5,3,7,101,18};

    Solution obj;

    int result = obj.lengthOfLIS(nums);

    cout << "Length of LIS: " << result << endl;

    return 0;
}