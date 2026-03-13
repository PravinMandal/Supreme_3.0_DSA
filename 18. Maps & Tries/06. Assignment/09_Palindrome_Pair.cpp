//leetcode: 336. Palindrome Pairs

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    char data;
    unordered_map<char, Trie*> child;
    bool isTerminal;
    int index; //words idx;

    Trie(char val) {
        this->data = val;
        this->isTerminal = false;
        index = -1; //words idx
    }
};

// This function inserts a word into the Trie character by character
// i represents the current character index in the string
// stridx represents the index of the word in the original words vector
void insert(Trie* root, string& str, int i, int& stridx) {
    // If we reached the end of the word, mark this node as terminal
    // and store the index of the word
    if(i == str.size()) {
        root->isTerminal = true;
        root->index = stridx;
        return;
    }

    char ch = str[i];

    // If the character does not exist in the children map,
    // create a new Trie node for it
    if(root->child.find(ch) == root->child.end()) {
        root->child[ch] = new Trie(ch);
    } 

    // Move to the next character in the word
    insert(root->child[ch], str, i+1, stridx);
}

// This function checks if the substring from index i to end is a palindrome
bool isPalindrome(string& str, int i) {
    int s = i;
    int e = str.size()-1;

    // Two pointer technique to verify palindrome
    while(s<=e) {
        if(str[s] != str[e]) return false;
        s++;
        e--;
    }
    return true;
}

// This function explores all remaining paths in the Trie when
// the searched word has been completely matched
// It collects all possible words that can form a palindrome pair
void getAll(Trie* root, string str, int& stridx, vector<int>& indexes, vector<vector<int>>& ans) {

    // If current node marks the end of a word in Trie
    if(root->isTerminal) {

        // Check if the remaining built string forms a palindrome
        bool isPal = isPalindrome(str, 0);

        if(isPal) {
            indexes = {root->index, stridx};

            // Avoid pairing the word with itself
            if(indexes[0] != stridx) ans.push_back(indexes);
        }
    }
    
    // Recursively explore all children nodes
    // Each child adds a character to the current constructed string
    for(auto all : root->child) {
        getAll(all.second, str+ all.first, stridx, indexes, ans);
    }
}

// This function searches the reversed word in the Trie
// While traversing, it checks palindrome conditions
void searchPalindrome(Trie* root, string& str, int i, int& stridx, vector<int>& indexes, vector<vector<int>>& ans) {

    // If we reached the end of the reversed word
    // we explore all remaining branches of Trie
    if(i == str.size()) {
        getAll(root, "", stridx, indexes, ans);
        return;
    }

    // If a word ends at this Trie node
    // check if the remaining part of the string is palindrome
    if(root->isTerminal) {
        bool isPal = isPalindrome(str, i);

        if(isPal) {
            indexes = {root->index, stridx};

            if(indexes[0] != stridx) ans.push_back(indexes);
        }
    }

    char ch = str[i];

    // Continue traversal only if the character exists in Trie
    if(root->child.find(ch) != root->child.end()) {
        searchPalindrome(root->child[ch], str, i+1, stridx, indexes, ans);
    } else return;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;

        // Create root of Trie
        Trie* trie = new Trie('-');

        // Insert all words into the Trie
        for(int i=0; i<words.size(); i++) {
            insert(trie, words[i], 0, i);
        }

        // For each word, reverse it and try to find matching palindrome pairs
        for(int i=0; i<words.size(); i++) {

            string str = words[i];

            // Reverse the word to search for complementary pairs
            reverse(str.begin(), str.end());

            vector<int> indexes = {-1, -1};

            searchPalindrome(trie, str, 0, i, indexes, ans);
            
        }

        return ans;
    }
};

int main() {
    // Hardcoded test cases as required

    Solution obj;

    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};

    vector<vector<int>> result = obj.palindromePairs(words);

    cout << "Palindrome Pairs (index1, index2):" << endl;

    for(auto &pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }

    return 0;
}