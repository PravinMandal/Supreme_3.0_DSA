//leetcode: 3834. Merge Adjacent Equal Elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        ans.reserve(nums.size());

        // Traverse elements and merge adjacent equal values
        for(auto i : nums) {
            long long curr = i;

            // Keep merging while the last element is equal to current
            while(!ans.empty() && ans.back() == curr) {
                curr += ans.back();
                ans.pop_back();
            }

            ans.push_back(curr);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> nums = {2, 2, 4, 4, 8};

    vector<long long> result = sol.mergeAdjacent(nums);

    // Print result after merge operations
    for(long long x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
