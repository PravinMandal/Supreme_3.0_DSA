//10. Regular Expression Matching
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool solveUsingRec(string& s, string& p, int i, int j) {
        //base case
        if(i >= s.length() && j >= p.length()) {
            return true;
        }
        //p khatam ho gya but s abhi bhi baaki hai
        if(j >= p.length()) {
            return false;
        }

        //ab yaha pr jab i and j andar honge uske cases discuss krne hai
        // '.' and '*' handling

        bool currMatch = (i<s.length()) && (s[i] == p[j] || p[j] == '.');

        if(j+1 < p.length() && p[j+1] == '*') {
            //2 cases bana skte hai
            //ek mai * ko preceding element banana hai and ek mai empty
            bool replaceWithEmptyChar = (solveUsingRec(s, p, i, j+2));
            bool replaceWithPrecChar = (currMatch && solveUsingRec(s, p, i+1, j));

            return replaceWithEmptyChar || replaceWithPrecChar;
        }
        else if(currMatch) {
            return solveUsingRec(s, p, i+1, j+1);
        }
        else {
            //no match
            return false;
        }
    }

    bool solveUsingMem(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if(i >= s.length() && j >= p.length()) {
            return true;
        }
        if(j >= p.length()) {
            return false;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        bool currMatch = (i<s.length()) && (s[i] == p[j] || p[j] == '.');
        bool ans;
        if(j+1 < p.length() && p[j+1] == '*') {
            bool replaceWithEmptyChar = (solveUsingMem(s, p, i, j+2, dp));
            bool replaceWithPrecChar = (currMatch && solveUsingMem(s, p, i+1, j, dp));
            
            ans = replaceWithEmptyChar || replaceWithPrecChar;
        }
        else if(currMatch) {
            ans = solveUsingMem(s, p, i+1, j+1, dp);
        }
        else {
            ans = false;
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    bool solveUsingTab(string& s, string& p, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m][n] = true;

        for(int i=m; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                bool currMatch = (i<s.length()) && (s[i] == p[j] || p[j] == '.');
                bool ans;
                if(j+1 < p.length() && p[j+1] == '*') {
                    bool replaceWithEmptyChar = (dp[i][j+2]);
                    bool replaceWithPrecChar = (currMatch && dp[i+1][j]);
                    
                    ans = replaceWithEmptyChar || replaceWithPrecChar;
                }
                else if(currMatch) {
                    ans = dp[i+1][j+1];
                }
                else {
                    ans = false;
                }

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    bool solveUsingTabSO(string& s, string& p, int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        next[n] = true;

        for(int i=m; i>=0; i--) {
            //yaha pr thoda confusion hai
            //yaha kya kr rhe hai ki agar dono string fully proccesed hai toh
            //hum true store kr lete hai
            // if(i == m) {
            //     curr[n] = true;
            // }
            // else {
            //     curr[n] = false;
            // }
            curr[n] = (i==m);
            for(int j=n-1; j>=0; j--) {
                bool currMatch = (i<s.length()) && (s[i] == p[j] || p[j] == '.');
                bool ans;
                if(j+1 < p.length() && p[j+1] == '*') {
                    bool replaceWithEmptyChar = (curr[j+2]);
                    bool replaceWithPrecChar = (currMatch && next[j]);
                    
                    ans = replaceWithEmptyChar || replaceWithPrecChar;
                }
                else if(currMatch) {
                    ans = next[j+1];
                }
                else {
                    ans = false;
                }

                curr[j] = ans;
            }
            //shifting
            next = curr;
        }
        return curr[0];
    }
    

    bool isMatch(string s, string p) {
        //Recursion
        // bool ans = solveUsingRec(s, p, 0, 0);

        //Memoisation
        int m = s.length();
        int n = p.length();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // bool ans = solveUsingMem(s, p, 0, 0, dp);

        //Tabulation
        // bool ans = solveUsingTab(s, p, m, n);

        //SO
        bool ans = solveUsingTabSO(s, p, m, n);

        return ans;
    }
};

int main() {
    Solution sol;

    string s = "aab";
    string p = "c*a*b";

    if(sol.isMatch(s, p)) {
        cout << "Pattern matches the string" << endl;
    } else {
        cout << "Pattern does not match the string" << endl;
    }

    return 0;
}
