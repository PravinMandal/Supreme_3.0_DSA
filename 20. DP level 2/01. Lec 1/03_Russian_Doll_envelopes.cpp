//leetcode: 354. Russian Doll Envelopes
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int isSafeToFit(vector<int>& e1, vector<int>& e2){
        if(e1[0] < e2[0] && e1[1] < e2[1]) {
            return true;
        }
        else {
            return false;
        }
    }

    int solveUsingRec(vector<vector<int>>& envelopes, int prev, int curr) {
        //base case
        if(curr >= envelopes.size()){
            return 0;
        }

        int incl = 0;
        if(prev == -1 || isSafeToFit(envelopes[prev], envelopes[curr])) {
            incl = 1 + solveUsingRec(envelopes, curr, curr+1);
        }
        int excl = 0 + solveUsingRec(envelopes, prev, curr+1);
        int ans = max(incl, excl);
        return ans;
    }

    //Memoisation
    int solveUsingMem(vector<vector<int>>& envelopes, int prev, int curr, vector<vector<int>>& dp) {
        //base case
        if(curr >= envelopes.size()){
            return 0;
        }

        if(dp[prev+1][curr] != -1) {
            return dp[prev+1][curr];
        }

        int incl = 0;
        if(prev == -1 || isSafeToFit(envelopes[prev], envelopes[curr])) {
            incl = 1 + solveUsingMem(envelopes, curr, curr+1, dp);
        }
        int excl = 0 + solveUsingMem(envelopes, prev, curr+1, dp);
        dp[prev+1][curr] = max(incl, excl);
        return dp[prev+1][curr];
    }

    //Tabulation
    int solveUsingTab(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                int incl = 0;
                if(prev == -1 || isSafeToFit(envelopes[prev], envelopes[curr])) {
                    incl = 1 + dp[curr+1][curr+1];
                }
                int excl = 0 + dp[prev+1][curr+1];
                dp[prev+1][curr] = max(incl, excl);
            }
        }
        return dp[-1+1][0];
    }

    //TabulationSO
    int solveUsingTabSO(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> prevRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                int incl = 0;
                if(prev == -1 || isSafeToFit(envelopes[prev], envelopes[curr])) {
                    incl = 1 + prevRow[curr+1];
                }
                int excl = 0 + prevRow[prev+1];
                currRow[prev+1] = max(incl, excl);
            }
            //shifting
            //ye mai bhul jaata hu
            prevRow = currRow;
        }
        return prevRow[-1+1];
    }

    //TabulationSO2
    int solveUsingTabSO2(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        // vector<int> prevRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                int incl = 0;
                if(prev == -1 || isSafeToFit(envelopes[prev], envelopes[curr])) {
                    incl = 1 + currRow[curr+1];
                }
                int excl = 0 + currRow[prev+1];
                currRow[prev+1] = max(incl, excl);
            }
            //shifting
            //ye mai bhul jaata hu
            // prevRow = currRow;
        }
        return currRow[-1+1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int prev = -1;
        int curr = 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        
        //recursion
        // return solveUsingRec(envelopes, prev, curr);

        //Memoisation
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveUsingMem(envelopes, prev, curr, dp);

        //Tabulation
        // return solveUsingTab(envelopes);

        //TabulationSO
        // return solveUsingTabSO(envelopes);

        //TabulationSO2
        return solveUsingTabSO2(envelopes);
        // sab krne ke baad bhi TLE maar diya
        //assignment mai hai 
        //isse DP with binary Search krna pdega
    }
};

int main() {
    Solution s;

    vector<vector<int>> envelopes = {
        {5,4},
        {6,4},
        {6,7},
        {2,3}
    };

    cout << "Maximum number of envelopes: " << s.maxEnvelopes(envelopes) << endl;

    return 0;
}
