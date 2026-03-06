//leetcode: 648 Replace Words

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    unordered_map<int, TrieNode*> children;
    bool isTerminal;

    TrieNode(int val) {
        data = val;
        isTerminal = false;
    }
};

void insertNode(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    //1 case mai solve krunga
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        //ch present
        child = root->children[ch];
    }
    else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    //baaki recursion samhal lega
    insertNode(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word, int& len) {
    //base case
    len++;
    if(root->isTerminal) return true;
    if(word.length() == 0) {
        return root->isTerminal;
    }

    //1 case mai solve krunga
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    }
    else {
        return false;
    }

    bool recKaAns = searchWord(child, word.substr(1), len);
    return recKaAns;
}

bool searchPrefix(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        //just wo word mil gya toh return true krdo
        return true;
    }

    //1 case mai solve krunga
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()){
        //present
        child = root->children[ch];
    }
    else {
        return false;
    }

    //baki recursion samhal lega
    bool recKaAns = searchPrefix(child, word.substr(1));
    return recKaAns;
}

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        insertNode(root, word);
    }
    
    int search(string word) {
        int len = 0;
        bool found = searchWord(root, word, len);

        // If a root word is found, return its length
        return found ? len-1 : -1;
    }
    
    bool startsWith(string prefix) {
        bool ans = searchPrefix(root, prefix);
        return ans;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;

        Trie trie;

        // Insert all dictionary root words into Trie
        for(auto word : dictionary) {
            trie.insert(word);
        }

        int start = 0, end = 0;

        // Traverse the sentence to extract words
        while(end < sentence.size()) {

            if(sentence[end] == ' ' || end == sentence.size()-1) {

                // Handle last word separately
                int len = end == sentence.size()-1 ? sentence.size() : end - start;

                string word = sentence.substr(start, len);

                // Find shortest root that matches the word
                int replaceLen = trie.search(word);

                ans += replaceLen == -1 ? word : word.substr(0, replaceLen);

                if(sentence[end] == ' ') {
                    ans += " ";
                }

                start = end + 1;
            }

            end++;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    cout << sol.replaceWords(dictionary, sentence) << endl;

    return 0;
}