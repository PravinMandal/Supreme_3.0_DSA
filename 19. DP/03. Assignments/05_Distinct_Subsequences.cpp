//leetcode: 115. Distinct Subsequences

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(string& s, string& t, int i, int j) {
        //base case
        if(j>=t.size()) return 1; // If we matched all characters of t, one valid subsequence is found
        if(i>=s.size()) return 0; // If s is exhausted but t is not, no subsequence possible

        int incl = 0;
        if(s[i] == t[j]) {
            // If characters match, we have option to include this character
            incl = solveUsingRec(s, t, i+1, j+1);
        }
        // Exclude current character of s and move forward
        int excl = solveUsingRec(s, t, i+1, j);

        return incl+excl; // Total ways = include + exclude
    }
    
    int solveUsingMem(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        //base case
        if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;

        // If already computed, return stored value
        if(dp[i][j] != -1) return dp[i][j];

        int incl = 0;
        if(s[i] == t[j]) {
            incl = solveUsingMem(s, t, i+1, j+1, dp);
        }
        int excl = solveUsingMem(s, t, i+1, j, dp);

        // Store result in DP table
        return dp[i][j] = incl+excl;
    }

    int solveUsingTab(string& s, string& t) {
        // DP table where dp[i][j] = number of ways to form t[j:] from s[i:]
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

        // If t is empty, there's exactly 1 way (choose nothing)
        for(int i=0; i<=s.size(); i++) {
            dp[i][t.size()] = 1;
        }

        // Fill table from bottom to top
        for(int i=s.size()-1; i>=0; i--) {
            for(int j=t.size()-1; j>=0; j--) {
                unsigned long long incl = 0;
                if(s[i] == t[j]) {
                    incl = dp[i+1][j+1]; // include current char
                }
                unsigned long long excl = dp[i+1][j]; // exclude current char

                // Prevent overflow by limiting to INT_MAX
                dp[i][j] = min((unsigned long long)INT_MAX, incl+excl);
            }
        }
        return (int) dp[0][0]; // Answer for full strings
    }

    int solveUsingTabSO(string& s, string& t) {
        // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        vector<int>curr(t.size()+1, 0);
        vector<int>prev(t.size()+1, 0);

        //last wala column 1 tha, toh sab row ka [t.size()] position 1 hona chahiye
        prev[t.size()] = 1;
        curr[t.size()] = 1; // upar dekho saare row ke last wala element one tha

        for(int i=s.size()-1; i>=0; i--) {
            for(int j=t.size()-1; j>=0; j--) {
                unsigned long long incl = 0;
                if(s[i] == t[j]) {
                    incl = prev[j+1]; // include from next row
                }
                unsigned long long excl = prev[j]; // exclude from next row

                curr[j] = min((unsigned long long)INT_MAX, incl+excl);
            }
            //shifting
            prev = curr; // Move current row to previous for next iteration
        }
        return prev[0];
    }

    int solveUsingTabSO2(string& s, string& t) {
        // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        vector<int>curr(t.size()+1, 0);
        // vector<int>prev(t.size()+1, 0);

        //last wala column 1 tha, toh sab row ka [t.size()] position 1 hona chahiye
        // prev[t.size()] = 1;
        curr[t.size()] = 1; // upar dekho saare row ke last wala element one tha

        for(int i=s.size()-1; i>=0; i--) {
            for(int j=0; j<t.size(); j++) {
                unsigned long long incl = 0;
                if(s[i] == t[j]) {
                    incl = curr[j+1]; // include case (same array reused carefully)
                }
                unsigned long long excl = curr[j]; // exclude case

                curr[j] = min((unsigned long long)INT_MAX, incl+excl);
            }
            //shifting
            // prev = curr;
        }
        return curr[0];
    }

    int numDistinct(string s, string t) {
        if(s.size()<t.size()) return 0; // If s is smaller than t, impossible
        // return solveUsingRec(s, t, 0, 0);

        // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        // return solveUsingMem(s, t, 0, 0, dp);

        return solveUsingTabSO2(s, t); // Using most optimized approach
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    string s1 = "rabbbit";
    string t1 = "rabbit";

    string s2 = "babgbag";
    string t2 = "bag";

    cout << "Test Case 1 Output: " << obj.numDistinct(s1, t1) << endl;
    cout << "Test Case 2 Output: " << obj.numDistinct(s2, t2) << endl;

    return 0;
}