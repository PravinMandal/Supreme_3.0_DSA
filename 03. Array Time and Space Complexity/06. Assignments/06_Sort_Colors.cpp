//leetcode: 75. Sort Colors
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};

int main() {
    // Example Test Case:
    // Input: nums = {2, 0, 2, 1, 1, 0}
    // Expected output: {0, 0, 1, 1, 2, 2}
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    Solution sol;
    sol.sortColors(nums);
    
    cout << "Sorted Colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
