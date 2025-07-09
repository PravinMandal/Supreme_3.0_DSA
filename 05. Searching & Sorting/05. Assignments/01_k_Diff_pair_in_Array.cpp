//leetcode: 532. K-diff Pairs in an Array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        int count = 0;
        for(auto it = freq.begin(); it!=freq.end(); it++) {
            int num = it->first;
            int f = it->second;

            if(k == 0) {
                if(f>1) count++;
            }
            else {
                if(freq.find(num+k) != freq.end()) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    cout << "Number of unique k-diff pairs: " << sol.findPairs(nums, k) << endl;

    return 0;
}
