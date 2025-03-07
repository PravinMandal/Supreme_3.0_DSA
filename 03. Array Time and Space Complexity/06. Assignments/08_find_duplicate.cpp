//leetcode: 287. Find the Duplicate Number
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            if(map[element] == false) {
                map[element] = true;
            }
            else {
                return element;
            }
        }
        return -1;
    }
};

int main() {
    // Example Test Case:
    // Input: nums = {1, 3, 4, 2, 2}
    // Expected Output: 2
    vector<int> nums = {1, 3, 4, 2, 2};
    
    Solution sol;
    int duplicate = sol.findDuplicate(nums);
    
    cout << "The duplicate element is: " << duplicate << endl;
    return 0;
}
