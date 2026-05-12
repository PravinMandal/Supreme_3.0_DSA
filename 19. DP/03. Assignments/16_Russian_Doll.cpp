//leetcode: 354. Russian Doll Envelopes

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingBS(vector<vector<int>>& envelopes) {

        // Sort envelopes by width ascending
        // If widths are same, sort height descending
        // Descending height prevents invalid nesting of same-width envelopes
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>&b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        // This array is used for LIS (Longest Increasing Subsequence) on heights
        vector<int> arr;

        for(auto& env : envelopes) {

            int height = env[1];

            // Find first position where current height can be placed
            // lower_bound gives first element >= height
            auto it = lower_bound(arr.begin(), arr.end(), height);

            if(it == arr.end()) {

                // If height is greater than all existing values,
                // extend LIS
                arr.push_back(height);

            } else {

                // Replace existing value to keep smaller tail
                // for future better LIS formation
                *it = height;
            }
        }

        // Size of LIS gives maximum number of nested envelopes
        return arr.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //Binary Search Method
        return solveUsingBS(envelopes);

    }
};

int main() {

    Solution obj;

    // Hardcoded test cases
    vector<vector<int>> envelopes1 = {
        {5,4},
        {6,4},
        {6,7},
        {2,3}
    };

    vector<vector<int>> envelopes2 = {
        {1,1},
        {1,1},
        {1,1}
    };

    vector<vector<int>> envelopes3 = {
        {4,5},
        {4,6},
        {6,7},
        {2,3},
        {1,1}
    };

    cout << "Test Case 1 Output: " << obj.maxEnvelopes(envelopes1) << endl;
    cout << "Test Case 2 Output: " << obj.maxEnvelopes(envelopes2) << endl;
    cout << "Test Case 3 Output: " << obj.maxEnvelopes(envelopes3) << endl;

    return 0;
}