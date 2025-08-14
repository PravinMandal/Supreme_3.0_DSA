//leetcode: 676. Implement Magic Dictionary
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char value;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(int data) {
        this->value = data;
        this->isTerminal = false;
    }
};

class Trie {
    void insertHelper(TrieNode* root, string word, int i = 0) {
        if (i == word.size()) {
            root->isTerminal = true;
            return;
        }

        char ch = word[i];
        if (root->children.find(ch) != root->children.end()) {
            insertHelper(root->children[ch], word, i + 1);
        }
        else {
            root->children[ch] = new TrieNode(ch);
            insertHelper(root->children[ch], word, i + 1);
        }
    }

    bool searchWordHelper(TrieNode* root, string word, int i = 0, bool mismatch = false) {
        if (i == word.size()) return mismatch && root->isTerminal;

        char ch = word[i];
        if (root->children.find(ch) != root->children.end()) {
            //match kro jaha tak possible hai
            if (searchWordHelper(root->children[ch], word, i + 1, mismatch)) return true;
        }

        //agar hum yaha hai mtlb mismatch hua
        if (!mismatch) {
            for (auto& [childchar, childNode] : root->children) {
                if (ch != childchar && searchWordHelper(childNode, word, i + 1, true)) return true;
            }
        }
        //yaha aaya mtlb 1 baar se zyada mismatch hua
        return false;
    }

public:
    TrieNode* root = new TrieNode('-');
    void insertWord(string word) {
        insertHelper(root, word);
    }
    bool searchWords(string word) {
        return searchWordHelper(root, word);
    }
};

class MagicDictionary {
    Trie trie;
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary) {
            trie.insertWord(word);
        }
    }

    bool search(string searchWord) {
        return trie.searchWords(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main() {
    MagicDictionary* obj = new MagicDictionary();

    // Hardcoded test case from LeetCode example
    vector<string> dictionary = { "hello", "leetcode" };
    obj->buildDict(dictionary);

    cout << boolalpha; // print true/false instead of 1/0
    cout << obj->search("hello") << endl;    // false
    cout << obj->search("hhllo") << endl;    // true
    cout << obj->search("hell") << endl;     // false
    cout << obj->search("leetcoded") << endl; // false

    delete obj;
    return 0;
}
