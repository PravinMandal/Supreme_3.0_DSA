//leetcode: 1023 Camelcase Matching

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    char data;
    unordered_map<char, Trie*> children;
    bool isTerminal;

    Trie(char val) {
        data = val;
        isTerminal = false;
    }
};

void insertchar(string val, Trie* &root) {
    if(val.size() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = val[0];

    if(root->children.find(ch) != root->children.end()) {
        insertchar(val.substr(1), root->children[ch]);
    } 
    else {
        Trie* newchar = new Trie(ch);
        root->children[ch] = newchar;
        insertchar(val.substr(1), root->children[ch]);
    }
}

bool solve(Trie* root, string& queries, int i) {
    if(i >= queries.size()) {
        return root->isTerminal;
    }

    char ch = queries[i];

    // If character matches trie path
    if(root->children.find(ch) != root->children.end()) {
        return solve(root->children[ch], queries, i+1);
    }

    // If character is lowercase, we can skip it
    else if(islower(queries[i])) {
        return solve(root, queries, i+1);
    }

    // Uppercase mismatch means invalid
    return false;
}

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;

        Trie* trie = new Trie('-');

        // Insert pattern into Trie
        insertchar(pattern, trie);

        // Check each query against the pattern
        for(string str : queries) {
            ans.push_back(solve(trie, str, 0));
        }

        return ans;
    }
};

class Solution2 {
public:
    bool solve(string& str, string& pattern) {
        int i = 0;
        int j = 0;
        while(i < str.length() && j < pattern.length()) {
            if(isupper(str[i]) && isupper(pattern[j])) {
                if(str[i] != pattern[j]) return false;
                else {
                    i++;
                    j++;
                }
            }
            else if(isupper(pattern[j]) && islower(str[i])) {
                i++;
            }
            else {
                if(str[i] == pattern[j]) {
                    i++;
                    j++;
                } else {
                    i++;
                }
            }
        }
        while(i<str.length()) {
            if(isupper(str[i])) return false;
            i++;
        }
        if(j<pattern.length()) return false;
        return true;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for(string str : queries) {
            bool ans = solve(str, pattern);
            answer.push_back(ans);
        }
        return answer;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern = "FB";

    vector<bool> result = sol.camelMatch(queries, pattern);

    for(bool x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}