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

class Solution2 {
public:
    bool solveUsingRec(string&s, unordered_map<string, bool>& wordDict, string output, string word, int i) {
        if(i>=s.size()) {
            return s == output; // If we reached end, check if constructed output matches original string
        } 
        // word.push_back(s[i]);
        bool incl = false;

        // Include current character in the current word being formed
        word.push_back(s[i]);

        // If the current word exists in dictionary, we can "cut" here and start a new word
        if(wordDict.find(word) != wordDict.end()) {
            incl = solveUsingRec(s, wordDict, output+word, "", i+1);
        }

        // Exclude case means we continue building the current word
        bool excl = solveUsingRec(s, wordDict, output, word, i+1);

        // Return true if any path gives valid segmentation
        return incl||excl;
    }
    
    bool solveUsingMem(string&s, unordered_map<string, bool>& wordDict, string output, string word, int i, unordered_map<string, bool>& dp) {
        if(i>=s.size()) {
            return s == output; // Same base condition as recursion
        } 

        // Create a unique key using index and current partial word
        string key = to_string(i) + "|" + word;

        // If already computed, return stored result
        if(dp.find(key) != dp.end()) return dp[key];

        bool incl = false;

        // Add current character to word
        word.push_back(s[i]);

        // If word is found in dictionary, try splitting here
        if(wordDict.find(word) != wordDict.end()) {
            incl = solveUsingMem(s, wordDict, output+word, "", i+1, dp);
        }

        // Continue building word without splitting
        bool excl = solveUsingMem(s, wordDict, output, word, i+1, dp);

        // Store result in dp
        dp[key] = incl||excl;
        return dp[key];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;

        // Convert vector to map for O(1) lookup
        for(string str : wordDict) mp[str] = true;

        // return solveUsingRec(s, mp, "", "", 0);

        unordered_map<string, bool> dp;

        // Using memoization approach for efficiency
        return solveUsingMem(s, mp, "", "", 0, dp);
    }
};

class Solution3 {
public:
    bool solveUsingRec(string& s, unordered_map<string, bool>& wordDict, int start) {
        if(start>=s.size()) return true;

        string word = "";
        bool flag = false;
        for(int i=start; i<s.size(); i++) {
            word += s[i];
            if(wordDict.find(word) != wordDict.end()) {
                flag = flag || solveUsingRec(s, wordDict, i+1);
            }
        }
        return flag;
    }
    
    bool solveUsingMem(string& s, unordered_map<string, bool>& wordDict, int start, vector<int>& dp) {
        if(start>=s.size()) return true;

        if(dp[start] != -1) return dp[start];

        string word = "";
        bool flag = false;
        for(int i=start; i<s.size(); i++) {
            word += s[i];
            if(wordDict.find(word) != wordDict.end()) {
                flag = flag || solveUsingMem(s, wordDict, i+1, dp);
            }
        }
        dp[start] = flag;
        return flag;
    }

    bool solveUsingTab(string& s, unordered_map<string, bool>& wordDict) {
        vector<int> dp(s.size()+1, 0);
        dp[s.size()] = 1;

        for(int start = s.size()-1; start>=0; start--) {
            string word = "";
            bool flag = false;
            for(int i=start; i<s.size(); i++) {
                word += s[i];
                if(wordDict.find(word) != wordDict.end()) {
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        for(string str : wordDict) mp[str] = true;

        // return solveUsingRec(s, mp, 0);

        // vector<int> dp(s.size()+1, -1);
        // return solveUsingMem(s, mp, 0, dp);

        return solveUsingTab(s, mp);
    }
};

int main() {
    Solution3 obj;

    // Hardcoded test cases
    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};

    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};

    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};

    cout << "Test Case 1 Output: " << obj.wordBreak(s1, dict1) << endl;
    cout << "Test Case 2 Output: " << obj.wordBreak(s2, dict2) << endl;
    cout << "Test Case 3 Output: " << obj.wordBreak(s3, dict3) << endl;

    return 0;
}