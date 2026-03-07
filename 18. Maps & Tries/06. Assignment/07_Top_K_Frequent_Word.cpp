//leetcode: 692 Top K Frequent Words

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;

        unordered_map<string, int> mp;

        // Count frequency of each word
        for(string word : words) {
            mp[word]++;
        }

        // Convert map to vector for sorting
        vector<pair<string, int>> arr(mp.begin(), mp.end());

        // Sort by:
        // 1. Higher frequency first
        // 2. If frequency same, lexicographically smaller word first
        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b){
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        // Take first k words
        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }
    
        return ans;
    }
};



//implemented using trie, jo map se hashing kar rhe the bss uss hashing ke liye trie ka use kiye
class comp {
public:
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    }
};

class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    int freq;
    bool isTerminal;

    TrieNode(int val) {
        data = val;
        isTerminal = false;
        freq = 0;
    }
};

void insertNode(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        root->freq++;
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

void traverseUtil(TrieNode* root, string& s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k) {
    if(!root) return;
    if(root->isTerminal) {
        pq.push({root->freq, s});
        if(pq.size() > k) {
            pq.pop();
        }
    }
    for(auto i : root->children) {
        s.push_back(i.first);
        traverseUtil(i.second, s, pq, k);
        s.pop_back();
    }
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
    
    void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k) {
        string s;
        traverseUtil(root, s, pq, k);
    }
};


class Solution2 {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        for(auto str : words) {
            trie.insert(str);
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        trie.traverse(pq, k);
        vector<string> ans;
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans.push_back(top.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};




int main() {
    Solution2 sol;

    // Hardcoded test case
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;

    vector<string> result = sol.topKFrequent(words, k);

    // Print result
    for(string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}