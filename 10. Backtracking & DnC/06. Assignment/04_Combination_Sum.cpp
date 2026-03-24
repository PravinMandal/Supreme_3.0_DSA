//leetcode: 39. Combination Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Backtracking function to generate all valid combinations
    void solve(vector<int>& candidates, int target, vector<int>& output, vector<vector<int>>& ans, int index) {

        // If target becomes 0 → we found a valid combination
        if(target == 0) {
            ans.push_back(output);
            return;
        }

        // If target becomes negative OR index goes out of bounds → stop this path
        if(target < 0 || index >= candidates.size()) return;

        // Try picking each element starting from current index
        for(int i=index; i<candidates.size(); i++) {

            int curr = candidates[i];

            // Only proceed if current number can fit into target
            if(target >= curr) {

                // Choose current number
                output.push_back(curr);

                // Stay at same index i (reuse allowed)
                solve(candidates, target-curr, output, ans, i);

                // Backtrack: remove last added element
                output.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;

        // Edge case: no valid combinations possible
        if(target <= 1) return ans;

        vector<int> output;

        int index = 0;

        // Start recursion
        solve(candidates, target, output, ans, index);

        return ans;
    }
};

class Solution2 {
public:
    void solve(vector<int>& candidates, int target, vector<int>& output, vector<vector<int>>& ans, int i) {
        if(target == 0) {
            ans.push_back(output);
            return;
        }
        if(target < 0 || i >= candidates.size()) return;

        int curr = candidates[i];
        if(target >= curr) {
            output.push_back(curr);
            solve(candidates, target-curr, output, ans, i);
            output.pop_back();
        }
        solve(candidates, target, output, ans, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(target <= 1) return ans;
        vector<int> output;
        int index = 0;
        solve(candidates, target, output, ans, index);
        return ans;
    }
};

int main() {

    // Hardcoded test case
    vector<int> candidates = {2, 3, 5};
    int target = 8;

    Solution2 obj;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "Combinations:\n";

    for(auto &vec : result) {
        cout << "[ ";
        for(int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}