//leetcode: 1402. Reducing Dishes

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& satisfaction, int i, int time) {
        if(i>=satisfaction.size()) return 0; // Base case: no dishes left

        // Include current dish
        // Current satisfaction contributes time * satisfaction[i]
        int incl = (time*satisfaction[i]) + solveUsingRec(satisfaction, i+1, time+1);

        // Exclude current dish
        int excl = solveUsingRec(satisfaction, i+1, time);

        // Return best choice
        return max(incl, excl);
    }
    
    int solveUsingMem(vector<int>& satisfaction, int i, int time, vector<vector<int>>& dp) {
        if(i>=satisfaction.size()) return 0; // Base case

        // Return memoized answer
        if(dp[i][time] != -1) return dp[i][time];

        // Include current dish
        int incl = (time*satisfaction[i]) + solveUsingMem(satisfaction, i+1, time+1, dp);

        // Skip current dish
        int excl = solveUsingMem(satisfaction, i+1, time, dp);

        dp[i][time] = max(incl, excl);

        return max(incl, excl);
    }

    int solveUsingTab(vector<int>& satisfaction) {

        /*
            dp[i][time] =
            maximum satisfaction starting from index i
            when current cooking time is "time"
        */
        vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+2, 0));

        for(int i=satisfaction.size()-1; i>=0; i--) {
            for(int time=satisfaction.size(); time>=1; time--) {

                // Include current dish
                int incl = (time*satisfaction[i]) + dp[i+1][time+1];

                // Exclude current dish
                int excl = dp[i+1][time];

                dp[i][time] = max(incl, excl);
            }
        }

        return dp[0][1];
    }

    int solveUsingTabSO(vector<int>& satisfaction) {
        // vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+2, 0));

        // Space optimized DP
        vector<int> curr(satisfaction.size()+2, 0);
        vector<int> prev(satisfaction.size()+2, 0);

        for(int i=satisfaction.size()-1; i>=0; i--) {
            for(int time=satisfaction.size(); time>=1; time--) {

                // Include current dish
                int incl = (time*satisfaction[i]) + prev[time+1];

                // Exclude current dish
                int excl = prev[time];

                curr[time] = max(incl, excl);
            }

            //shifting
            prev = curr;
        }

        return prev[1];
    }

    int maxSatisfaction(vector<int>& satisfaction) {

        // Sorting is important because smaller/negative values should come first
        // This allows DP to decide whether including early negative dishes
        // helps increase later larger positive contributions
        sort(satisfaction.begin(), satisfaction.end());

        // return solveUsingRec(satisfaction, 0, 1);

        // vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size()+1, -1));
        // return solveUsingMem(satisfaction, 0, 1, dp);

        // return solveUsingTab(satisfaction);
        return solveUsingTabSO(satisfaction);
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    vector<int> satisfaction1 = {-1, -8, 0, 5, -9};
    vector<int> satisfaction2 = {4, 3, 2};
    vector<int> satisfaction3 = {-1, -4, -5};

    cout << "Test Case 1 Output: " << obj.maxSatisfaction(satisfaction1) << endl;
    cout << "Test Case 2 Output: " << obj.maxSatisfaction(satisfaction2) << endl;
    cout << "Test Case 3 Output: " << obj.maxSatisfaction(satisfaction3) << endl;

    return 0;
}