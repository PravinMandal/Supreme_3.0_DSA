//leetcode: 1187. Make Array Strictly Increasing

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int INF = 1e9;

    int solveUsingRec(vector<int>& arr1, vector<int>& arr2, int prev, int i) {

        // Base case: all elements processed
        if(i>=arr1.size()) return 0;

        // Start with impossible large answer
        int ans = INF;

        // Option 1:
        // Keep current element if it maintains strictly increasing order
        if(prev == -1 || prev < arr1[i]) {
            ans = min(ans, solveUsingRec(arr1, arr2, arr1[i], i+1));
        } 

        // Option 2:
        // Replace current element with next greater element from arr2
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        if(it != arr2.end()) {

            // One replacement + recursive answer
            ans = min(ans, 1 + solveUsingRec(arr1, arr2, *it, i+1));
        }

        return ans;
    }
    
    int solveUsingMem(vector<int>& arr1, vector<int>& arr2, int prev, int i, unordered_map<int, unordered_map<int, int>>& dp) {

        // Base case
        if(i>=arr1.size()) return 0;

        int ans = INF;

        // Return cached result
        if(dp.count(prev) && dp[prev].count(i)) return dp[prev][i];

        // Option 1: Keep current element
        if(prev == -1 || prev < arr1[i]) {
            ans = min(ans, solveUsingMem(arr1, arr2, arr1[i], i+1, dp));
        } 

        // Find smallest element greater than prev
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        // Option 2: Replace current element
        if(it != arr2.end()) {
            ans = min(ans, 1 + solveUsingMem(arr1, arr2, *it, i+1, dp));
        }

        // Store result
        dp[prev][i] = ans;

        return ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        // Sort arr2 for binary search
        sort(arr2.begin(), arr2.end());

        // remove duplicates
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        // int ans = solveUsingRec(arr1, arr2, -1, 0);

        unordered_map<int, unordered_map<int, int>> dp;

        int ans = solveUsingMem(arr1, arr2, -1, 0, dp);

        // If impossible, return -1
        return ans >= INF ? -1 : ans;
    }
};

int main() {

    Solution obj;

    // Hardcoded test cases
    vector<int> arr1_1 = {1,5,3,6,7};
    vector<int> arr2_1 = {1,3,2,4};

    vector<int> arr1_2 = {1,5,3,6,7};
    vector<int> arr2_2 = {4,3,1};

    vector<int> arr1_3 = {1,5,3,6,7};
    vector<int> arr2_3 = {1,6,3,3};

    cout << "Test Case 1 Output: " << obj.makeArrayIncreasing(arr1_1, arr2_1) << endl;
    cout << "Test Case 2 Output: " << obj.makeArrayIncreasing(arr1_2, arr2_2) << endl;
    cout << "Test Case 3 Output: " << obj.makeArrayIncreasing(arr1_3, arr2_3) << endl;

    return 0;
}