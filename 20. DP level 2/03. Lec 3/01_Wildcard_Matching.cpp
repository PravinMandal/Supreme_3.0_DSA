//Leetcode: 44. Wildcard Matching
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool solveRec(string& s, string& p, int i, int j) {
        //base case
        //case 1: if dono bahar nikal gye
        if(i >= s.length() && j >= p.length()) {
            return true;
        }

        //case 2: j bahar nikal gye, mtlb pattern hi khatam ho gya
        if(j >= p.length()) {
            return false;
        }

        //case 3: i bahar nikal gya but j baaki hai
        //j baaki hai but uske baad j mai saare * hai toh usse empty consider kiye toh pattern bann jayega
        if(i >= s.length()) {
            //check krenge sab * hona chahiye
            for(int k=j; k<p.length(); k++) {
                if(p[k] != '*') {
                    return false;
                }
            }
            //yaha par aa gya mtlb saare * hai
            return true;
        }

        //yaha logic aayega
        //i and j dono andar hai
        //match,  no match
        if(s[i] == p[j] || p[j] == '?') {
            return solveRec(s, p, i+1, j+1);
            //match ho gya just dono ko aage badha do
        }
        else if(p[j] == '*') {
            //ab do tarike se * ka use kr skte hai
            //eg: s = babbar and p = ba*ar
            // 1: * ko 'b*' maan lenge, just i+1 krdo
            //2: * ko empty maan lenge, just j+1 krdo
            //dono ka or krenge jisme se ans bann jaaye
            return solveRec(s, p, i+1, j) || solveRec(s, p, i, j+1);
        }
        else {
            //no match
            return false;
        }
    }

    bool solveMem(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        //base case
        //case 1: if dono bahar nikal gye
        if(i >= s.length() && j >= p.length()) {
            return true;
        }

        //case 2: j bahar nikal gye, mtlb pattern hi khatam ho gya
        if(j >= p.length()) {
            return false;
        }

        //case 3: i bahar nikal gya but j baaki hai
        //j baaki hai but uske baad j mai saare * hai toh usse empty consider kiye toh pattern bann jayega
        if(i >= s.length()) {
            //check krenge sab * hona chahiye
            for(int k=j; k<p.length(); k++) {
                if(p[k] != '*') {
                    return false;
                }
            }
            //yaha par aa gya mtlb saare * hai
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        //yaha logic aayega
        //i and j dono andar hai
        //match,  no match
        if(s[i] == p[j] || p[j] == '?') {
            dp[i][j] = solveMem(s, p, i+1, j+1, dp);
            return dp[i][j];
            //match ho gya just dono ko aage badha do
        }
        else if(p[j] == '*') {
            //ab do tarike se * ka use kr skte hai
            //eg: s = babbar and p = ba*ar
            // 1: * ko 'b*' maan lenge, just i+1 krdo
            //2: * ko empty maan lenge, just j+1 krdo
            //dono ka or krenge jisme se ans bann jaaye
            dp[i][j] = solveMem(s, p, i+1, j, dp) || solveMem(s, p, i, j+1, dp);
            return dp[i][j];
        }
        else {
            //no match
            dp[i][j] = false;
            return dp[i][j];
        }
    }

    bool solveTab(string& s, string& p, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //case 1 ka
        dp[m][n] = true;

        //case 2 ka zarurat nhi h kyuki wo false hai and hum sab false hi initialize kr rhe h

        for(int col=0; col<n; col++) {
            bool flag = true;
            for(int k=col; k<p.length(); k++) {
                if(p[k] != '*') {
                    flag = false;
                }
            }
            dp[m][col] = flag;
        }

        for(int i=m-1; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                int ans;
                if(s[i] == p[j] || p[j] == '?') {
                    ans = dp[i+1][j+1];
                }
                else if(p[j] == '*') {
                    ans = dp[i+1][j] || dp[i][j+1];
                }
                else {
                   ans = false;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    bool solveTabSO(string& s, string& p, int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        //case 1 ka
        next[n] = true;

        //case 2 ka zarurat nhi h kyuki wo false hai and hum sab false hi initialize kr rhe h

        for(int col=0; col<n; col++) {
            bool flag = true;
            for(int k=col; k<p.length(); k++) {
                if(p[k] != '*') {
                    flag = false;
                }
            }
            next[col] = flag;
        }

        for(int i=m-1; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                int ans;
                if(s[i] == p[j] || p[j] == '?') {
                    ans = next[j+1];
                }
                else if(p[j] == '*') {
                    ans = next[j] || curr[j+1];
                }
                else {
                   ans = false;
                }
                curr[j] = ans;
            }
            //shifting
            next = curr;
        }
        return next[0];
    }

    
    bool isMatch(string s, string p) {
        //recursion
        // bool ans = solveRec(s, p, 0, 0);

        //Memoisation
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // bool ans = solveMem(s, p, 0, 0, dp);

        //Tabulation
        // bool ans = solveTab(s, p, m, n);

        //SO
        bool ans = solveTabSO(s, p, m, n);

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "babbar";
    string p = "ba*ar";
    if(sol.isMatch(s, p)) {
        cout << "Pattern matches the string" << endl;
    } else {
        cout << "Pattern does not match the string" << endl;
    }
    return 0;
}
