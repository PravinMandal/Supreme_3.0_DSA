//isme hum kya krenge ki koi bhi prefix diya hoga and apne stored words mai se suggest krna hi ki kya ho skta h
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class TrieNode {
public:
    char data;
    unordered_map<int, TrieNode*>children;
    bool isTerminal;

    TrieNode(char val) {
        this->data = val;
        this->isTerminal = false;
    }
};

void insertIntoTrie(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    //ek case mai solve krunga
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    }
    else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    //baaki recursion samhal lega
    insertIntoTrie(child, word.substr(1));
}

void storeString(TrieNode* root, vector<string>& ans, string temp) {
    //base case
    if(root->isTerminal) {
        ans.push_back(temp);
        //mujhe yaha return krne ki zaroorat nhi h kyuki kya pta Terminal aane ke baad bhi uske aage koi aur word bhi ho
        //for eg: "car" aaya and isTerminal true aaya but uske aage "caring" bhi h
    }

    //ek case mai solve krunga
    TrieNode* child;
    for(auto i: root->children) {
        char ch = i.first;
        temp.push_back(ch);
        child = root->children[ch];
        storeString(child, ans, temp);
        //backtrack
        temp.pop_back();
    }
    //root->children nhi hoga then recursion tut jayega
}

void findWordsWithPrefix(TrieNode* root, string prefix, vector<string>& ans) {
    //base case
    if(prefix.length() == 0) {
        string temp = "";
        storeString(root, ans, temp);
        return;
    }

    //ek case mai solve krunga
    char ch = prefix[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    }
    else {
        return;
    }

    findWordsWithPrefix(child, prefix.substr(1), ans);
}

vector<vector<string>> getSuggestions(TrieNode* root, string prefix) {
    vector<vector<string>> ans;
    string temp ="";

    for(int i=0; i<prefix.size(); i++) {
        vector<string> tempAns;
        char currChar = prefix[i];
        temp.push_back(currChar);
        findWordsWithPrefix(root, temp, tempAns);
        
        for(int j=0; j<tempAns.size(); j++) {
            tempAns[j] = temp + tempAns[j];
        }
        ans.push_back(tempAns);
    }
    return ans;
}

int main() {
    TrieNode* root = new TrieNode('-');

    insertIntoTrie(root, "babbar");
    insertIntoTrie(root, "baby");
    insertIntoTrie(root, "baba");
    insertIntoTrie(root, "bala");

    string prefix = "bal";

    vector<vector<string>> ans = getSuggestions(root, prefix);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    // vector<string> ans;
    // findWordsWithPrefix(root, prefix, ans);

    // for(int i=0; i<ans.size(); i++) {
    //     string str = prefix + ans[i];
    //     ans[i] = str; //ab ans[i] mai final ans bhi store ho gya
    //     cout<<ans[i]<<endl;
    // }


    return 0;
}