//leetcode: 1312. Minimum Insertion Steps to Make a String Palindrome

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solveUsingRec(string&s, int i, int e) {

        // Base case:
        // If pointers cross or become equal, string is already palindrome
        if(i>=e) return 0;

        int ans = 0;

        // If characters are different,
        // we need one insertion + minimum of two possibilities
        if(s[i] != s[e]) {

            ans = 1 + min(
                solveUsingRec(s, i+1, e),
                solveUsingRec(s, i, e-1)
            );

        } else {

            // If characters match, move both pointers inward
            ans = solveUsingRec(s, i+1, e-1);
        }

        return ans;
    }
    
    int solveUsingMem(string&s, int i, int e, vector<vector<int>>& dp) {

        if(i>=e) return 0;

        // Return already computed result
        if(dp[i][e] != -1) return dp[i][e];

        int ans = 0;

        if(s[i] != s[e]) {

            ans = 1 + min(
                solveUsingMem(s, i+1, e, dp),
                solveUsingMem(s, i, e-1, dp)
            );

        } else {

            ans = solveUsingMem(s, i+1, e-1, dp);
        }

        // Store result in DP table
        dp[i][e] = ans;

        return ans;
    }

    int solveUsingTab(string& s) {

        // dp[i][e] = minimum insertions needed for substring i to e
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));

        // Fill table diagonally
        for(int i=s.size()-1; i>=0; i--) {

            for(int e=i+1; e<s.size(); e++) {

                int ans = 0;

                if(s[i] != s[e]) {

                    ans = 1 + min(dp[i+1][e], dp[i][e-1]);

                } else {

                    ans = dp[i+1][e-1];
                }

                dp[i][e] = ans;
            }
        }

        return dp[0][s.size()-1];
    }
    
    int solveUsingTabSO(string& s) {

        // vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));

        // Space optimized DP using only two rows
        vector<int> curr(s.size()+1, 0);
        vector<int> prev(s.size()+1, 0);

        for(int i=s.size()-1; i>=0; i--) {

            for(int e=i+1; e<s.size(); e++) {

                int ans = 0;

                if(s[i] != s[e]) {

                    ans = 1 + min(prev[e], curr[e-1]);

                } else {

                    ans = prev[e-1];
                }

                curr[e] = ans;
            }

            //shifting
            prev = curr;
        }

        return prev[s.size()-1];
    }

    int minInsertions(string s) {

        // return solveUsingRec(s, 0, s.size()-1);

        // vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        // return solveUsingMem(s, 0, s.size()-1, dp);

        // return solveUsingTab(s);

        return solveUsingTabSO(s);
    }
};

int main() {

    Solution obj;

    // Hardcoded test cases
    string s1 = "zzazz";
    string s2 = "mbadm";
    string s3 = "leetcode";

    cout << "Test Case 1 Output: " << obj.minInsertions(s1) << endl;
    cout << "Test Case 2 Output: " << obj.minInsertions(s2) << endl;
    cout << "Test Case 3 Output: " << obj.minInsertions(s3) << endl;

    return 0;
}