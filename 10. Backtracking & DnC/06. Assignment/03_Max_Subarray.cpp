//leetcode: 53. Maximum Subarray

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Divide and Conquer approach to find maximum subarray sum
    int findMaxSubArray(vector<int>& nums, int s, int e) {

        // Base case: single element
        if(s == e) return nums[s];

        int mid = s + (e-s)/2;

        // Maximum subarray entirely in left half
        int maxLeftSum = findMaxSubArray(nums, s, mid);

        // Maximum subarray entirely in right half
        int maxRightSum = findMaxSubArray(nums, mid+1, e);

        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int leftBorderSum = 0, rightBorderSum = 0;

        // Compute maximum sum crossing mid from left side
        for(int i=mid; i>=s; i--) {
            leftBorderSum += nums[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }

        // Compute maximum sum crossing mid from right side
        for(int i=mid+1; i<=e; i++) {
            rightBorderSum += nums[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }

        // Maximum subarray that crosses the midpoint
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        // Final answer is max of:
        // left part, right part, crossing part
        return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {

        // Call recursive divide and conquer
        return findMaxSubArray(nums, 0, nums.size()-1);
    }
};

int main() {

    // Hardcoded test case
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution obj;

    int result = obj.maxSubArray(nums);

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}