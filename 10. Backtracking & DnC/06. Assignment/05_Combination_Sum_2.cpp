//leetcode: 40. Combination Sum II

#include <bits/stdc++.h>
using namespace std;


// TLE, kyuki set use kr rhe hai and itne saare duplicates wo handle krege agar bada input hua toh
class Solution {
public:

    // This approach uses a SET to automatically remove duplicate combinations
    // We generate all possible combinations and store them in set<vector<int>>
    void solve(vector<int>& arr, set<vector<int>>& st, vector<int>& output, int target, int i) {

        // If target becomes 0 → valid combination
        if(target == 0) {
            st.insert(output);
            return;
        }

        // If index goes out of bounds → stop
        if(i >= arr.size()) return;

        int curr = arr[i];

        // Option 1: Include current element (if it fits)
        if(target >= curr) {

            output.push_back(curr);

            // Move to next index → no reuse allowed
            solve(arr, st, output, target-curr, i+1);

            // Backtrack
            output.pop_back();
        }

        // Option 2: Exclude current element
        solve(arr, st, output, target, i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;

        // Set ensures unique combinations (automatically removes duplicates)
        set<vector<int>> st;

        vector<int> output;

        // Sorting ensures combinations are generated in order
        // so that duplicates can be properly handled by set
        sort(candidates.begin(), candidates.end());

        // Start recursion
        solve(candidates, st, output, target, 0);

        // Convert set to vector
        for(auto i : st) {
            ans.push_back(i);
        }

        return ans;
    }
};


// more optimized
class Solution2 {
public:

    // Backtracking function to generate unique combinations
    void solve(vector<int>& arr, vector<vector<int>>& ans, vector<int>& output, int target, int index) {

        // If target becomes 0 → valid combination
        if(target == 0) {
            ans.push_back(output);
            return;
        }

        // Try all elements from current index
        for(int i=index; i<arr.size(); i++) {

            // array sorted hai agar wo index chhod ke uske aage duplicate hue toh just skip na 
            // warna duplicates banayenge
            if(i > index && arr[i] == arr[i-1]) continue;

            // Since array is sorted, if current element > target
            // then all next elements will also be greater → stop
            if(arr[i] > target) break;

            // Choose current element
            output.push_back(arr[i]);

            // Move to next index (i+1) → reuse NOT allowed
            solve(arr, ans, output, target - arr[i], i + 1);

            // Backtrack
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> output;

        // Sort array to:
        // 1. Handle duplicates
        // 2. Enable pruning (break condition)
        sort(candidates.begin(), candidates.end());

        // Start recursion
        solve(candidates, ans, output, target, 0);

        return ans;
    }
};

int main() {

    // Hardcoded test case
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution2 obj;

    vector<vector<int>> result = obj.combinationSum2(candidates, target);

    cout << "Unique combinations:\n";

    for(auto &vec : result) {
        cout << "[ ";
        for(int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}