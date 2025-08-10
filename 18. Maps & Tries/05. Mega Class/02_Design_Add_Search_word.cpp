// Leetcode: 211. Design Add and Search Words Data Structure
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
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

void insertword(TrieNode* root, string word) {
    if(word.size() == 0) {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    TrieNode* child;
    if(root->children.count(ch) == 1) {
        child = root->children[ch];
    }
    else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertword(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    if(word.size() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    TrieNode* child;

    if(ch == '.') {
        // . can be matched with any child of current root node trie node;
        for(auto it = root->children.begin(); it != root->children.end(); ++it) {
            child = it->second;
            if(searchWord(child, word.substr(1))) return true;
        }
        return false;
    }
    else if(root->children.count(ch) == 1) {
        child = root->children[ch];
        return searchWord(child, word.substr(1));
    }
    else {
        return false;
    }
}

class WordDictionary {
public:
    TrieNode* root = new TrieNode('-');
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        insertword(root, word);
    }
    
    bool search(string word) {
        bool ans = searchWord(root, word);
        return ans;
    }
};

int main() {
    WordDictionary obj;

    // Hardcoded test cases from Leetcode examples
    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");

    cout << boolalpha; // to print true/false instead of 1/0
    cout << "search('pad') -> " << obj.search("pad") << endl; // false
    cout << "search('bad') -> " << obj.search("bad") << endl; // true
    cout << "search('.ad') -> " << obj.search(".ad") << endl; // true
    cout << "search('b..') -> " << obj.search("b..") << endl; // true

    return 0;
}
