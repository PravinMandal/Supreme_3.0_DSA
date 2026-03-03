//leetcode: 525 Contiguous Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        int csum = 0;

        // Traverse the array and treat 0 as -1 and 1 as +1
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1) 
                csum++;
            else 
                csum--;

            // If cumulative sum becomes 0,
            // subarray from 0 to i has equal 0s and 1s
            if(csum == 0) {
                ans = max(ans, i + 1);
            } 
            else if(mp.find(csum) == mp.end()) {
                // Store first occurrence of this cumulative sum
                mp[csum] = i;
            } 
            else {
                // If seen before, subarray between previous index+1 and i
                // has equal number of 0s and 1s
                ans = max(ans, i - mp[csum]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};

    cout << sol.findMaxLength(nums) << endl;  // Expected: 6

    return 0;
}