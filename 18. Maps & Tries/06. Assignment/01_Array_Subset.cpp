//gfg: Array Subset of another array

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> mp;

        // Store frequency of elements of array a
        for(int i : a) {
            mp[i]++;
        }

        // Check elements of array b in map
        for(int i : b) {
            if(mp.find(i) == mp.end()) {
                return false;
            }
            else {
                mp[i]--;
                if(mp[i] == 0) {
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};

    cout << sol.isSubset(a, b) << endl;  // Expected: 1 (true)

    return 0;
}