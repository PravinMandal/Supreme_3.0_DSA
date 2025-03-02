//leetcode: 208. Implement Trie (Prefix Tree)
#include <iostream>
#include <unordered_map>
#include <string>
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

bool searchWord(TrieNode* root, string word) {
    //base case
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

    bool recKaAns = searchWord(child, word.substr(1));
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
    
    bool search(string word) {
        bool ans = searchWord(root, word);
        return ans;
    }
    
    bool startsWith(string prefix) {
        bool ans = searchPrefix(root, prefix);
        return ans;
    }
};

int main() {
    // Create a Trie and test its functions
    Trie trie;
    
    // Insert words into the trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("bat");
    trie.insert("batch");
    
    // Search for words in the trie
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'bath': " << (trie.search("bath") ? "Found" : "Not Found") << endl;
    
    // Check for prefixes in the trie
    cout << "Prefix 'app' exists: " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Prefix 'ba' exists: " << (trie.startsWith("ba") ? "Yes" : "No") << endl;
    cout << "Prefix 'cat' exists: " << (trie.startsWith("cat") ? "Yes" : "No") << endl;
    
    return 0;
}
