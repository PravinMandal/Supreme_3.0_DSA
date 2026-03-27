//leetcode: 526. Beautiful Arrangement

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Backtracking function to count valid arrangements
    void solve(int n, vector<int>& arr, int& ans, vector<int>& visited, int index) {

        // If we filled all positions → valid arrangement found
        if(index == arr.size()) {
            ans++;
            return;
        }

        // Try placing numbers from 1 to n
        for(int i=1; i<=n; i++) {

            // If already used → skip
            if(visited[i]) continue;

            // Place number at current index
            // arr[index] = i;

            // Check condition:
            // (number % position == 0) OR (position % number == 0)
            // Note: index is 0-based, so position = index + 1
            if((i%(index+1)==0) || ((index+1) % i) == 0) {

                // Mark as used
                visited[i] = true;

                // Recurse for next position
                solve(n, arr, ans, visited, index+1);

                // Backtrack
                visited[i] = false;
            }
        }
    }

    int countArrangement(int n) {

        // Array to store current arrangement
        vector<int> arr(n, -1); //array ki zarurat nhi hai

        int ans = 0;

        // visited[i] tells whether number i is already used
        vector<int> visited(n+1);

        // Start backtracking from index 0
        solve(n, arr, ans, visited, 0);

        return ans;
    }
};

int main() {

    // Hardcoded test case
    int n = 3;

    Solution obj;

    int result = obj.countArrangement(n);

    cout << "Number of beautiful arrangements: " << result << endl;

    return 0;
}