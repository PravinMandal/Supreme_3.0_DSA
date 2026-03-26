//leetcode: 47. Permutations II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Backtracking function to generate unique permutations
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, vector<bool>& visited, int index) {

        // If permutation size equals array size → valid permutation
        if(output.size() == nums.size()) {
            ans.push_back(output);
            return;
        }

        // Try every element
        for(int i=0; i<nums.size(); i++) {

            // If already used → skip
            if(visited[i]) continue;

            // Duplicate handling:
            // If current element is same as previous AND previous is already used
            // then skip to avoid duplicate permutations
            if(i-1>=0 && nums[i] == nums[i-1] && visited[i-1] == true) continue;

            // Choose element
            output.push_back(nums[i]);
            visited[i] = true;

            // Recurse
            solve(nums, ans, output, visited, i+1);

            // Backtrack
            output.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;

        // Track visited elements
        vector<bool> visited(nums.size(), 0);

        // Sort to handle duplicates
        sort(nums.begin(), nums.end());

        // Start recursion
        solve(nums, ans, output, visited, 0);

        return ans;
    }
};


class Solution2 {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, unordered_map<int,int>& freq) {
        if(output.size() == nums.size()) {
            ans.push_back(output);
            return;
        }

        for(auto& a : freq) {
            int num = a.first;
            int count = a.second;
            if(count == 0) continue;
            output.push_back(num);
            freq[num]--;
            solve(nums, ans, output, freq);
            output.pop_back();
            freq[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i : nums) freq[i]++;
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, ans, output, freq);
        return ans;
    }
};


//more intutive approach
class Solution3 {
public:

    // Backtracking using frequency map
    // Instead of visited[], we track how many times each number can still be used
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, unordered_map<int,int>& freq) {

        // If permutation is complete → store it
        if(output.size() == nums.size()) {
            ans.push_back(output);
            return;
        }

        // Try every unique number available in frequency map
        for(auto& a : freq) {

            int num = a.first;
            int count = a.second;

            // If no occurrences left → skip
            if(count == 0) continue;

            // Choose this number
            output.push_back(num);
            freq[num]--;

            // Recurse to build further permutation
            solve(nums, ans, output, freq);

            // Backtrack
            output.pop_back();
            freq[num]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Frequency map to count occurrences of each number
        unordered_map<int,int> freq;
        for(int i : nums) freq[i]++;

        vector<vector<int>> ans;
        vector<int> output;

        // Start recursion
        solve(nums, ans, output, freq);

        return ans;
    }
};

int main() {

    // Hardcoded test case
    vector<int> nums = {1, 1, 2};

    Solution3 obj;

    vector<vector<int>> result = obj.permuteUnique(nums);

    cout << "Unique permutations:\n";

    for(auto &vec : result) {
        cout << "[ ";
        for(int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}