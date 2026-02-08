//leetcode: 3835 Count Subarrays With Cost Less Than or Equal to K

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(nums.size() == 1) return 1;

        int i = 0;
        long long ans = 0;
        map<int, long long> freq;

        // Sliding window approach
        for(int j = 0; j < nums.size(); j++) {

            // Add current element to frequency map
            freq[nums[j]]++;

            // Shrink window until condition is satisfied
            while(!freq.empty()) {
                long long maxLast = prev(freq.end())->first;
                long long minFirst = freq.begin()->first;
                long long len = j - i + 1;

                // Cost condition check
                if((maxLast - minFirst) * len > k) {
                    freq[nums[i]]--;
                    if(freq[nums[i]] == 0)
                        freq.erase(nums[i]);
                    i++;
                } else {
                    break;
                }
            }

            // All subarrays ending at j and starting from i are valid
            ans += (j - i + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> nums = {1, 3, 6};
    long long k = 6;

    cout << sol.countSubarrays(nums, k) << endl;

    return 0;
}
