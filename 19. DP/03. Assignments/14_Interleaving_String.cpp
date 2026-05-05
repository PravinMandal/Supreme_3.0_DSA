//leetcode: 97. Interleaving String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solveUsingRec(string& s1, string& s2, string& s3, int i, int j, int k) {
        if(i>=s1.size() && j>=s2.size() && k>=s3.size()) return true; // All strings consumed

        bool ans = false;
        
        // If current char of s1 matches s3, move forward in s1 and s3
        if(i<s1.size() && (s1[i] == s3[k])) 
            ans |= solveUsingRec(s1, s2, s3, i+1, j, k+1);

        // If current char of s2 matches s3, move forward in s2 and s3
        if(j<s2.size() && (s2[j] == s3[k])) 
            ans |= solveUsingRec(s1, s2, s3, i, j+1, k+1);

        return ans;
    }
    
    bool solveUsingMem(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if(i>=s1.size() && j>=s2.size() && k>=s3.size()) return true;

        // Return stored result if already computed
        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool ans = false;
        
        if(i<s1.size() && (s1[i] == s3[k])) 
            ans |= solveUsingMem(s1, s2, s3, i+1, j, k+1, dp);

        if(j<s2.size() && (s2[j] == s3[k])) 
            ans |= solveUsingMem(s1, s2, s3, i, j+1, k+1, dp);
        
        // Store result
        dp[i][j][k] = ans;

        return ans;
    }

    bool solveUsingTab(string& s1, string& s2, string& s3) {

        // 3D DP: dp[i][j][k] = whether s3[k:] can be formed using s1[i:] and s2[j:]
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, 0)));
        
        // Base case: all strings consumed
        dp[s1.size()][s2.size()][s3.size()] = true;

        // Fill DP bottom-up
        for(int i=s1.size(); i>=0; i--) {
            for(int j=s2.size(); j>=0; j--) {
                for(int k=s3.size(); k>=0; k--) {

                    // Skip already initialized base case
                    if(i>=s1.size() && j>=s2.size() && k>=s3.size()) continue;

                    bool ans = false;

                    // Match with s1
                    if(i<s1.size() && (s1[i] == s3[k])) 
                        ans |= dp[i+1][j][k+1];

                    // Match with s2
                    if(j<s2.size() && (s2[j] == s3[k])) 
                        ans |= dp[i][j+1][k+1];
        
                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[0][0][0]; // Final answer
    }
    

    bool isInterleave(string s1, string s2, string s3) {
        // return solveUsingRec(s1, s2, s3, 0, 0, 0);

        // vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        // return solveUsingMem(s1, s2, s3, 0, 0, 0, dp);

        return solveUsingTab(s1, s2, s3); // Using tabulation
    }
};

int main() {
    Solution obj;

    // Hardcoded test cases
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    string s4 = "aadbbbaccc";

    cout << "Test Case 1 Output (should be 1): " << obj.isInterleave(s1, s2, s3) << endl;
    cout << "Test Case 2 Output (should be 0): " << obj.isInterleave(s1, s2, s4) << endl;

    return 0;
}