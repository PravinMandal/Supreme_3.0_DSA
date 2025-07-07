//leetcode: 1143. Longest Common Subsequence
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int solveUsingRec(string text1, string text2, int i, int j) {
        //base case
        if(i >= text1.length()) return 0;
        if(j >= text2.length()) return 0;

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = 1 + solveUsingRec(text1, text2, i+1, j+1);
        }
        else {
            ans = 0 + max(solveUsingRec(text1, text2, i+1, j), solveUsingRec(text1, text2, i, j+1));
        }
        return ans;
    }

    //2D DP
    int solveMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
        //humne text1 and text2 pass by reference nhi kiya tha isliye boht saari copies bann gyi
        //aur usme boht time laga process krne mai isiiye TLE(time limit exceeded) aa gya tha
        //isiliye ye sab pass by reference krne ka
        //base case
        if(i >= text1.length()) return 0;
        if(j >= text2.length()) return 0;
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if(text1[i] == text2[j]) {
            ans = 1 + solveMem(text1, text2, i+1, j+1, dp);
        }
        else {
            ans = 0 + max(solveMem(text1, text2, i+1, j, dp), solveMem(text1, text2, i, j+1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    //Tabulation
    int solveTab(string &text1, string &text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i-- ) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = 1 + dp[i+1][j+1];
                }
                else {
                    ans = 0 + max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    //space optimized
    int solveTabSO(string &text1, string &text2) {
        int n = text1.length();
        int m = text2.length();
        // vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);

        for(int i=n-1; i>=0; i-- ) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(text1[i] == text2[j]) {
                    ans = 1 + prev[j+1];
                }
                else {
                    ans = 0 + max(prev[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            //shifting
            prev = curr;
        }
        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int n = text1.length();
        int m = text2.length();

        //Rec
        // return solveUsingRec(text1, text2, i, j);

        //Memoisation
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solveMem(text1, text2, i, j, dp);

        //Tabulation
        // return solveTab(text1, text2);

        //TabulationSO
        return solveTabSO(text1, text2);
        //itna hi space optimize hoga kyuki isme ek array pehle wale array pr dependent hai
        //toh 2 array toh lgega hi, ek array mai nhi kr skte
    }    
};

int main() {
    Solution sol;

    string text1 = "abcde";
    string text2 = "ace";

    int lcsLength = sol.longestCommonSubsequence(text1, text2);

    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}
