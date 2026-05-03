//leetcode: 1140. Stone Game II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>& piles, int m, int i, bool alice) {
        //base case
        if(i >= piles.size()) return 0; // No piles left

        // If it's Alice's turn → maximize score, Bob's turn → minimize Alice's score
        int ans = alice ? INT_MIN : INT_MAX;

        int sum = 0;

        // Try all possible X (1 to 2*M)
        for(int x=1; x<=2*m; x++) {
            if(i+x-1 >= piles.size()) break;

            // Accumulate stones picked in this move
            sum += piles[i+x-1];

            if(alice)
                // Alice picks and adds to her score
                ans = max(ans, sum + solveUsingRec(piles, max(x, m), i+x, !alice));
            else 
                //bob will try ki alice minimize hoye
                // Bob tries to minimize Alice's total score
                ans = min(ans, solveUsingRec(piles, max(x, m), i+x, !alice));
        }

        return ans;
    }
    
    int solveUsingMem(vector<int>& piles, int m, int i, bool alice, vector<vector<vector<int>>>& dp) {
        //base case
        if(i >= piles.size()) return 0;

        // If already computed, return stored value
        if(dp[m][i][alice] != -1) return dp[m][i][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int sum = 0;

        for(int x=1; x<=2*m; x++) {
            if(i+x-1 >= piles.size()) break;

            sum += piles[i+x-1];

            if(alice)
                ans = max(ans, sum + solveUsingMem(piles, max(x, m), i+x, !alice, dp));
            else 
                ans = min(ans, solveUsingMem(piles, max(x, m), i+x, !alice, dp));
        }

        // Store result
        dp[m][i][alice] = ans;

        return ans;
    }

    int solveUsingTab(vector<int>& piles) {
        int n = piles.size();

        // dp[m][i][alice] = best result from index i with M=m and turn
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

        // Bottom-up filling
        for(int m=n; m>=1; m--) {
            for(int i=n-1; i>=0; i--) {
                for(int alice=0; alice<=1; alice++) {

                    int ans = alice ? INT_MIN : INT_MAX;
                    int sum = 0;

                    for(int x=1; x<=2*m; x++) {
                        if(i+x-1 >= piles.size()) break;

                        sum += piles[i+x-1];

                        if(alice)
                            ans = max(ans, sum + dp[max(x, m)][i+x][!alice]);
                        else 
                            ans = min(ans, dp[max(x, m)][i+x][!alice]);
                    }

                    dp[m][i][alice] = ans;
                }
            }
        }

        return dp[1][0][1]; // Start from index 0, M=1, Alice's turn
    }

    int stoneGameII(vector<int>& piles) {
        // return solveUsingRec(piles, 1, 0, true);

        int n = piles.size();

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        // return solveUsingMem(piles, 1, 0, true, dp);

        return solveUsingTab(piles);
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    vector<int> piles1 = {2, 7, 9, 4, 4};
    vector<int> piles2 = {1, 2, 3, 4, 5, 100};

    cout << "Test Case 1 Output: " << obj.stoneGameII(piles1) << endl;
    cout << "Test Case 2 Output: " << obj.stoneGameII(piles2) << endl;

    return 0;
}