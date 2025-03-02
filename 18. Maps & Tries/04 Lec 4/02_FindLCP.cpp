//leetcode: 14. Longest Common Prefix
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    char data;
    unordered_map<int, TrieNode*> children;
    bool isTerminal;

    TrieNode(char val) {
        data = val;
        isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    //1 case mai samhalunga
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    //baaki recursion samhal lega
    insertWord(child, word.substr(1));
}

void findLCP(TrieNode* root, string& ans) {
    //base case
    if(root->isTerminal == true) {
        return;
    }

    //1 case mai samhalunga
    TrieNode* child;
    if(root->children.size() == 1) {
        for(auto i : root->children) {
            char ch = i.first;
            ans.push_back(ch);
            child = i.second;
        }
    }
    else {
        return;
    }
    //baaki recursion samhal lega
    findLCP(child, ans);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        for(auto word : strs) {
            insertWord(root, word);
        }
        string ans = "";
        findLCP(root, ans);
        return ans;
    }
};

int main() {
    // Example Test Case:
    // Input: strs = {"flower", "flow", "flight"}
    // Expected Output: "fl"
    vector<string> strs = {"flower", "flow", "flight"};
    
    Solution sol;
    string result = sol.longestCommonPrefix(strs);
    
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
