//leetcode: 643. Maximum Average Subarray I
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findthemaxSubarray(vector<int>& nums, int k) {
        int sum = 0;
        int ans = INT_MIN;
        int i = 0, j = k - 1;
        sum = accumulate(nums.begin(), nums.begin() + k, 0);
        ans = sum;
        j++;
        while(j < nums.size()) {
            sum = sum - nums[i++];
            sum = sum + nums[j++];
            ans = max(ans, sum);
        }
        return ans / (double)k;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = findthemaxSubarray(nums, k);
        return ans;
    }
};

int main() {
    // Example Test Case:
    // Input: nums = [1,12,-5,-6,50,3], k = 4
    // Expected Output: 12.75
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    
    Solution sol;
    double result = sol.findMaxAverage(nums, k);
    
    cout << "The maximum average of a subarray of length " << k << " is: " << result << endl;
    return 0;
}
