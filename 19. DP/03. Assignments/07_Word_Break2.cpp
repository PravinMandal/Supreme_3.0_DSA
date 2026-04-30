//leetcode: 140. Word Break II

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> mainAns;
public:
    bool solveUsingRec(string&s, unordered_map<string, bool>& wordDict, string ans, string output, string word, int i) {
        if(i>=s.size()) {
            if(s == output) {
                ans.pop_back();
                mainAns.push_back(ans);
                return true;
            }
            return false;
        } 

        bool incl = false;
        word.push_back(s[i]);
        if(wordDict.find(word) != wordDict.end()) {
            incl = solveUsingRec(s, wordDict, ans+word+" ", output+word, "", i+1);
        }
        bool excl = solveUsingRec(s, wordDict, ans, output, word, i+1);

        return incl||excl;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        for(string str : wordDict) mp[str] = true;
        solveUsingRec(s, mp, "", "", "", 0);

        return mainAns;
    }
};

class Solution2 {
public:
    vector<string> solveUsingRec(string& s, unordered_map<string, bool>& dict, int i) {
        if(i>=s.size()) return {""}; // If reached end, return empty string as base for concatenation

        vector<string>ans;
        string word = "";

        // Try all possible partitions starting from index i
        for(int j=i; j<s.size(); j++) {
            word += s[j]; // Build current word

            // If current word exists in dictionary
            if(dict.find(word) != dict.end()) {
                // Solve for remaining substring
                auto right = solveUsingRec(s, dict, j+1);

                // Combine current word with results from right side
                for(string str : right) {
                    string endPart;

                    // Add space only if there is something ahead
                    if(str.size() > 0)  endPart = " " + str;

                    ans.push_back(word+endPart);
                }
            }
        }
        return ans; // Return all possible sentences
    }

    vector<string> solveUsingMem(string& s, unordered_map<string, bool>& dict, int i, vector<vector<string>>& dp) {
        if(i>=s.size()) return {""};

        // Check if already computed (custom way using "-1" marker)
        if(dp[i] != vector<string>(s.size()+1, "-1")) return dp[i];

        vector<string>ans;
        string word = "";

        for(int j=i; j<s.size(); j++) {
            word += s[j];

            if(dict.find(word) != dict.end()) {
                auto right = solveUsingMem(s, dict, j+1, dp);

                for(string str : right) {
                    string endPart;

                    if(str.size() > 0)  endPart = " " + str;

                    ans.push_back(word+endPart);
                }
            }
        }

        // Store computed result
        dp[i] = ans;
        return dp[i];
    }
    
    vector<string> solveUsingTab(string& s, unordered_map<string, bool>& dict) {
        // dp[i] stores all possible sentences starting from index i
        vector<vector<string>> dp(s.size()+1);

        dp[s.size()] = {""}; // Base case

        for(int i=s.size()-1; i>=0; i--) {
            vector<string>ans;
            string word = "";

            for(int j=i; j<s.size(); j++) {
                word += s[j];

                if(dict.find(word) != dict.end()) {
                    auto right = dp[j+1];

                    for(string str : right) {
                        string endPart;

                        if(str.size() > 0)  endPart = " " + str;

                        ans.push_back(word+endPart);
                    }
                }
            }
            dp[i] = ans; // Store result for index i
        }
        return dp[0];
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;

        // Convert dictionary to hashmap for fast lookup
        for(string str : wordDict) mp[str] = true;

        // return solveUsingRec(s, mp, 0);

        // vector<vector<string>> dp(s.size()+1, vector<string>(s.size()+1, "-1"));
        // return solveUsingMem(s, mp, 0, dp);

        return solveUsingTab(s, mp); // Using tabulation approach
    }
};

int main() {
    Solution2 obj;

    // Hardcoded test cases
    string s1 = "catsanddog";
    vector<string> dict1 = {"cat", "cats", "and", "sand", "dog"};

    string s2 = "pineapplepenapple";
    vector<string> dict2 = {"apple", "pen", "applepen", "pine", "pineapple"};

    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};

    vector<string> res1 = obj.wordBreak(s1, dict1);
    vector<string> res2 = obj.wordBreak(s2, dict2);
    vector<string> res3 = obj.wordBreak(s3, dict3);

    cout << "Test Case 1 Output:\n";
    for(string str : res1) cout << str << endl;

    cout << "\nTest Case 2 Output:\n";
    for(string str : res2) cout << str << endl;

    cout << "\nTest Case 3 Output:\n";
    for(string str : res3) cout << str << endl;

    return 0;
}