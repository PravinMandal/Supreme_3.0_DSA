//leetcode: 2163 Minimum Difference in Sums After Removal of Elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // sum of the smallest n elements chosen from nums[0..i]
    void getPrefix(vector<int>& nums, vector<long long>& prefix) {
        priority_queue<int> pq; // max heap to remove the largest element when size exceeds n
        int n = nums.size() / 3;
        long long sum = 0;

        // Traverse from left to right
        for(int i : nums) {
            sum += i;
            pq.push(i);

            // Until we have at least n elements, prefix value is invalid
            if(pq.size() < n) {
                prefix.push_back(-1);
                continue;
            }

            // If more than n elements, remove the largest to keep smallest n
            if(pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }

            // Store sum of smallest n elements so far
            prefix.push_back(sum);
        }
    }

    // sum of the largest n elements chosen from nums[i..end]
    void getSuffix(vector<int>& nums, vector<long long>& suffix) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap to remove smallest element
        int n = nums.size() / 3;
        long long sum = 0;

        // Traverse from right to left
        for(int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            pq.push(nums[i]);

            // Until we have at least n elements, suffix value is invalid
            if(pq.size() < n) {
                suffix.push_back(-1);
                continue;
            }

            // If more than n elements, remove the smallest to keep largest n
            if(pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }

            // Store sum of largest n elements so far
            suffix.push_back(sum);
        }

        // Reverse to align indices with original array
        reverse(suffix.begin(), suffix.end());
    }

    long long minimumDifference(vector<int>& nums) {
        vector<long long> prefix;
        vector<long long> suffix;

        // Compute prefix and suffix arrays
        getPrefix(nums, prefix);
        getSuffix(nums, suffix);

        long long ans = LLONG_MAX;
        int n = nums.size() / 3;

        // Try all valid split points between first 2n elements
        // Left part uses prefix[i], right part uses suffix[i+1]
        for(int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, prefix[i] - suffix[i + 1]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> nums = {3, 1, 2, 4, 5, 6, 1, 2, 3};

    cout << sol.minimumDifference(nums) << endl;

    return 0;
}