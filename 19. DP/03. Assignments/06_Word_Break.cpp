//leetcode: 139. Word Break

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Recursive function with memoization
    // Checks if string s can be segmented into words from dictionary
    bool solveUsingRec(string s, unordered_set<string>& wordDict, unordered_map<string, bool>& dp) {

        // If string becomes empty → valid segmentation
        if(s.size() == 0) return true;

        // If already computed → return stored result
        if(dp.count(s) == 1) return dp[s];

        // Try every word in dictionary
        for(auto word : wordDict) {

            // Check if current string starts with this word
            if(s.substr(0, word.size()) == word) {

                // Remove prefix and solve for remaining string
                string temp = s.substr(word.size());

                if(solveUsingRec(temp, wordDict, dp)) {
                    dp[s] = true;
                    return dp[s];
                }
            }
        }

        // If no valid segmentation found
        dp[s] = false;
        return dp[s];
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        // Convert vector to set for faster lookup
        unordered_set<string> wordDicts (wordDict.begin(), wordDict.end());

        // Memoization map
        unordered_map<string, bool> dp;

        return solveUsingRec(s, wordDicts, dp);
    }
};

int main() {

    // Hardcoded test case
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    Solution obj;

    bool result = obj.wordBreak(s, wordDict);

    if(result) cout << "String can be segmented" << endl;
    else cout << "Cannot be segmented" << endl;

    return 0;
}