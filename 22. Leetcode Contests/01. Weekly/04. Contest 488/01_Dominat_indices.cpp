//leetcode: 3833. Count Dominant Indices

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        vector<int> total(nums.size(), 0);

        // total[i] stores suffix sum starting from index i
        total[nums.size() - 1] = nums[nums.size() - 1];

        int ans = 0;

        // Traverse from right to left
        for(int i = nums.size() - 2; i >= 0; i--) {
            total[i] = nums[i] + total[i + 1];

            // Check if current element is greater than
            // average of remaining suffix elements
            if(nums[i] > (total[i + 1] / (nums.size() - i - 1)))
                ans++;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> nums = {3, 12, 6, 4};

    cout << sol.dominantIndices(nums) << endl;

    return 0;
}
