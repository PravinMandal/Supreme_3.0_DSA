//gfg: Huffman Encoding

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int freq;
    Node* left;
    Node* right;

    Node(int num) {
        this->freq = num;
        left = NULL;
        right = NULL;
    }
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; // min heap
    }
};

class Solution {
public:
    Node* findroot(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (int i = 0; i < N; i++) {
            pq.push(new Node(f[i]));
        }

        while (pq.size() > 1) {
            Node* leftptr = pq.top(); pq.pop();
            Node* rightptr = pq.top(); pq.pop();

            Node* parent = new Node(leftptr->freq + rightptr->freq);

            parent->left = leftptr;
            parent->right = rightptr;
            pq.push(parent);
        }

        // The remaining node in the queue is the root
        Node* root = pq.top(); 
        pq.pop();
        return root;
    }

    void solve(Node* root, string ans, vector<string>& finalAns) {
        if (!root) return;

        if (!root->left && !root->right) {
            finalAns.push_back(ans);
            return;
        }

        solve(root->left, ans + "0", finalAns);
        solve(root->right, ans + "1", finalAns);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        Node* root = findroot(S, f, N);

        // Traverse and store Huffman codes
        vector<string> finalAns;
        solve(root, "", finalAns);
        return finalAns;
    }
};

int main() {
    // Hardcoded test case instead of cin
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = f.size();

    Solution obj;
    vector<string> codes = obj.huffmanCodes(S, f, N);

    cout << "Huffman Codes:\n";
    for (string code : codes) {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
