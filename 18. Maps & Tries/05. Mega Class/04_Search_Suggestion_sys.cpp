//leetcode: 1268 Search Suggestions System
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char value;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    string word;

    TrieNode(int data) {
        this->value = data;
        this->isTerminal = false;
    }
};

class Trie{
    void insertHelper(TrieNode* root, string word, int i=0) {
        if(i == word.size()) {
            root->isTerminal = true;
            root->word = word;
            return;
        }

        char ch = word[i];
        if(root->children.find(ch) != root->children.end()) {
            insertHelper(root->children[ch], word, i+1);
        }
        else {
            root->children[ch] = new TrieNode(ch);
            insertHelper(root->children[ch], word, i+1); 
        }
    }

    TrieNode* searchPrefixHelper(TrieNode* root, string& prefix, int i=0) {
        if(i >= prefix.size()) {
            //prefix matching completed;
            //now have to return all the terminal words
            return root;
        }

        if(root->children.find(prefix[i]) != root->children.end())
            return searchPrefixHelper(root->children[prefix[i]], prefix, i+1);
        return NULL;
    }

    void collectallWords(TrieNode* root, vector<string>& ans) {
        if(!root) return;
        if(root->isTerminal) ans.push_back(root->word);

        for(auto &[childchar, childNode] : root->children) {
            collectallWords(childNode, ans);
        }
    }


public:

    TrieNode* root = new TrieNode('-');
    void insertWord(string word) {
        insertHelper(root, word);
    }
    vector<string> searchPrefix(string prefix) {
        auto prefixMatchedNode = searchPrefixHelper(root, prefix);
        vector<string>ans;
        if(prefixMatchedNode) {
            //collect all the words below this node
            collectallWords(prefixMatchedNode, ans);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        vector<vector<string>>ans;

        //insert all product name
        for(auto& product : products) {
            trie.insertWord(product);
        }

        //this loop simulate char by char typing of searchWord
        string prefix;
        for(auto ch : searchWord) {
            prefix += ch;

            //get all word with current prefix
            vector<string>suggestion = trie.searchPrefix(prefix);
            sort(suggestion.begin(), suggestion.end());

            if(suggestion.size() > 3) {
                suggestion.resize(3);
            }
            ans.push_back(suggestion);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example test case from LeetCode 1268
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    
    vector<vector<string>> result = sol.suggestedProducts(products, searchWord);
    
    for (int i = 0; i < result.size(); i++) {
        cout << "After typing \"" << searchWord.substr(0, i+1) << "\": ";
        for (auto &word : result[i]) {
            cout << word << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
