//leetcode: Minimum Operations to Equalize Array (Contest Question)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAllEqual(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] != nums[i]) {
                return false;
            }
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int bitwiseNum = 0;
        for(int i : nums) {
            bitwiseNum ^= i;
        }
        if(isAllEqual(nums)) return 0;
        for(int i=0; i<nums.size(); i++) {
            if((nums[i] != bitwiseNum)) {
                return 1;
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int minOperations(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != nums[0]) return 1;
        }
        return 0;
    }
};

int main() {
    // Hardcoded testcases
    Solution2 sol;
    
    vector<int> nums1 = {2, 1, 3, 2, 3};  
    cout << sol.minOperations(nums1) << endl;  // Expected: 1

    vector<int> nums2 = {1, 1, 1};  
    cout << sol.minOperations(nums2) << endl;  // Expected: 0

    vector<int> nums3 = {5, 5, 7, 5};  
    cout << sol.minOperations(nums3) << endl;  // Expected: 1 (example)

    return 0;
}
