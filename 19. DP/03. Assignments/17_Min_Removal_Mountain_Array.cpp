//leetcode: 1671. Minimum Number of Removals to Make Mountain Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lis(vector<int>& nums) {

        // Array used for Longest Increasing Subsequence optimization
        vector<int> arr;

        // Start with first element
        arr.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++) {

            // If current number is greater than last LIS element,
            // extend LIS
            if(arr.back() < nums[i]) {
                arr.push_back(nums[i]);
                continue;
            }

            // Find first element >= nums[i]
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);

            int idx = it-arr.begin();

            // Replace to maintain smaller tail for future subsequences
            arr[idx] = nums[i];
        }

        return arr.size();
    }

    int solveUsingRec(vector<int>& nums) {

        int n = nums.size();

        // Store minimum removals
        int ans = INT_MAX;

        // Try every index as mountain peak
        // Peak cannot be first or last
        for(int i=1; i<n-1; i++) {

            // Left part including peak
            vector<int> temp(nums.begin(), nums.begin()+i+1);

            // Find LIS for increasing left side
            int left = lis(temp);

            // Right part starting from peak
            temp.assign(nums.begin()+i, nums.end());

            // Reverse so decreasing sequence becomes increasing LIS
            reverse(temp.begin(), temp.end());

            // Find LIS for right decreasing side
            int right = lis(temp);

            // Valid mountain requires both sides length > 1
            // if (left > 1 && right > 1) {

            //     // Elements to remove from left
            //     int leftRem = (i + 1) - left;

            //     // Elements to remove from right
            //     int rightRem = (n - i) - right;

            //     // Update minimum removals
            //     ans = min(ans, leftRem + rightRem);
            // }
            if (left > 1 && right > 1) {
                int totalRemoval = n - (left+right-1); // -1 isiliye kyuki pivot index wala dono mai consider kiye the
                ans = min(ans, totalRemoval);
            }
        }

        return ans;
    }

    int minimumMountainRemovals(vector<int>& nums) {

        // If exactly 3 elements, already valid mountain
        if(nums.size()==3) return 0;

        return solveUsingRec(nums);
    }
};

class Solution2 {
public:

    int lisOptimal(vector<int>& nums, vector<int>& lis) {

        // This array stores optimized tails for LIS construction
        vector<int> arr;

        // First element always starts LIS
        arr.push_back(nums[0]);

        // LIS length at first index is 1
        lis.push_back(1);

        for(int i=1; i<nums.size(); i++) {

            // If current number is greater than current LIS tail,
            // extend LIS
            if(arr.back() < nums[i]) {
                arr.push_back(nums[i]);

                // Store LIS length till this index
                lis.push_back(arr.size());

                continue;
            }

            // Find first element >= current number
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);

            int idx = it-arr.begin();

            // Replace to maintain smaller tail values
            // This helps future subsequences become longer
            arr[idx] = nums[i];

            // LIS length at this index
            lis.push_back(idx+1);
        }

        return arr.size();
    } 

    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        // Already valid mountain
        if(n==3) return 0;

        // longest increasing subsequence
        // longest decreasing subsequence
        vector<int> lis, lds;

        // LIS from left
        lisOptimal(nums, lis);

        // Reverse array to calculate decreasing sequence as LIS
        reverse(nums.begin(), nums.end());

        lisOptimal(nums, lds);

        // Reverse LDS to align indices with original array
        reverse(lds.begin(), lds.end());

        int ans = INT_MAX;

        // Try every element as mountain peak
        for(int i=0; i<nums.size(); i++) {

            int left = lis[i];
            int right = lds[i];

            // Valid mountain requires both increasing and decreasing sides
            if(left>1 && right>1) {

                // Total mountain length = left + right - 1
                // Peak counted twice, so subtract 1
                int totalRemoval = n - (left+right-1);

                ans = min(ans, totalRemoval);
            }
        }

        return ans;
    }
};

int main() {

    Solution2 obj;

    // Hardcoded test cases
    vector<int> nums1 = {1,3,1};
    vector<int> nums2 = {2,1,1,5,6,2,3,1};
    vector<int> nums3 = {4,3,2,1,1,2,3,1};

    cout << "Test Case 1 Output: " << obj.minimumMountainRemovals(nums1) << endl;
    cout << "Test Case 2 Output: " << obj.minimumMountainRemovals(nums2) << endl;
    cout << "Test Case 3 Output: " << obj.minimumMountainRemovals(nums3) << endl;

    return 0;
}