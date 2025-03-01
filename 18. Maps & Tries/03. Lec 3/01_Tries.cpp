#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode {
public:
    char value;
    unordered_map<int, TrieNode*> children;
    bool isTerminal;

    TrieNode(char data) {
        this->value = data;
        isTerminal = false;
    }
};

void insertIntoTries(TrieNode* root, string word) {
    //base case
    if(word.size() == 0) {
        root->isTerminal = true;
        return ;
    }

    //1 case mujhe solve krna h
    // 1 char ko tries mai insert kr deta hu
    char ch = word[0];
    TrieNode* child;

    //present h toh waha chale jao
    //absent h toh create krdo
    if(root->children.count(ch) == 1) {
        //present
        child = root->children[ch];
    }
    else {
        //absent
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    //baaki recursion samhal lega
    insertIntoTries(child, word.substr(1));
}

bool searchTrie(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        // if(root->isTerminal == true) {
        //     return true;
        // }
        // else {
        //     return false;
        // }

        return root->isTerminal;
    }
    
    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        //ye char present h
        child = root->children[ch];
    }
    else {
        //nhi present h ye char
        return false;
    }

    bool recurKaAns = searchTrie(child, word.substr(1));
    return recurKaAns;
}

void deleteWord(TrieNode* root, string word) {
    //base case
    //ek time aise aayega, jab word empty hoga
    //and root mai last char hoga
    if(word.length() == 0) {
        //last char tk pohoch gye
        //ab agar mujhe delete krna h toh meri approach ye h ki
        //mai agar isTerminal ko false mark krdu toh usse fir search nhi kr payenge and wo lost ho jaayega
        //mtlb kahin na kahin delete ho jaayega
        root->isTerminal = false;
        //mai uss word ko delete nhi kr rha kyuki aur bhi durse words connected h 
        //and agar maine tries mai se isko delete kr diya toh bohot mess create ho jayega
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        //char present
        child = root->children[ch];
    }
    else {
        //char not present
        //mtlb delete krne ki zaroorat hi nhi h kyuki present hi nhi h
        return;
    }

    //baaki recursion samhal lega
    deleteWord(child, word.substr(1));
}

int main() {

        TrieNode* root = new TrieNode('-');
        insertIntoTries(root, "cover");
        insertIntoTries(root, "care");
        insertIntoTries(root, "car");
        insertIntoTries(root, "hyper");
        insertIntoTries(root, "tail");
        insertIntoTries(root, "tails");
        insertIntoTries(root, "tall");
        insertIntoTries(root, "tower");
        insertIntoTries(root, "cake");

        bool ans = searchTrie(root, "cover");
        ans ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
        
        ans = searchTrie(root, "tail");
        ans ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;

        ans = searchTrie(root, "tailss");
        ans ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;

        ans = searchTrie(root, "cuts");
        ans ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;


        deleteWord(root, "cover");
        deleteWord(root, "tail");

        cout<<"Printing after deletion"<<endl;
        ans = searchTrie(root, "cover");
        ans ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
        
        ans = searchTrie(root, "tail");
        ans ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
        

    return 0;
}