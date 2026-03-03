//gfg: Largest subarray with 0 sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;

        // Traverse the array and maintain prefix sum
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // If prefix sum becomes zero, subarray from 0 to i has sum 0
            if(sum == 0) {
                ans = max(ans, i + 1);
            }

            // If this prefix sum was seen before,
            // subarray between previous index+1 and current index has sum 0
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, (i - mp[sum]));
            } else {
                // Store first occurrence of this prefix sum
                mp[sum] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << sol.maxLength(arr) << endl;  // Expected: 5

    return 0;
}