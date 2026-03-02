//leetcode: 239 Sliding Window Maximum

#include <bits/stdc++.h>
using namespace std;


// TC : O(NlogN)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        // Push first k elements with their indices
        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        // Maximum of the first window
        ans.push_back(pq.top().first);

        // Process remaining elements
        for(int i = k; i < nums.size(); i++) {
            // Add current element
            pq.push({nums[i], i});

            // Remove elements that are out of the current window
            while(!pq.empty() && pq.top().second < i - k + 1) {
                pq.pop();
            }

            // Current window maximum
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

// TC : O(N)
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for(int i=k; i<nums.size(); i++) {
            while(!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    // Print sliding window maximums
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}