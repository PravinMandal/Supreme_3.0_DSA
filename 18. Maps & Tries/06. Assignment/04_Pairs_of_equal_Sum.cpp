//gfg: Find pairs with given sum in array (Check if any two pairs have equal sum)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        // If less than 4 elements, we cannot form two distinct pairs
        if(arr.size() < 4) return false;

        unordered_map<int, int> mp;

        // Check all possible pairs
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {

                int sum = arr[i] + arr[j];

                // If this sum was already seen before,
                // it means another pair had same sum
                if(mp.find(sum) == mp.end()) {
                    mp[sum]++;
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> arr = {3, 4, 7, 1, 2, 9, 8};

    cout << sol.findPairs(arr) << endl;  // Expected: 1 (true)

    return 0;
}