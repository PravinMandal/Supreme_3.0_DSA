//gfg: Check whether BST contains Dead End

#include <bits/stdc++.h>
using namespace std;

// Node structure required for compilation
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    void hasDeadEnd(Node* root, int l, int r, bool& ans) {
        if(!root) return;

        // If leaf node is reached, check if range collapses
        if(!root->left && !root->right) {
            if(l == r) {
                ans = true;
                return;
            }
        }

        // Left subtree has allowed range [l, root->data - 1]
        hasDeadEnd(root->left, l, root->data - 1, ans);

        // Right subtree has allowed range [root->data + 1, r]
        hasDeadEnd(root->right, root->data + 1, r, ans);
    }

    bool isDeadEnd(Node *root) {
        bool ans = false;

        // BST values are positive, so range starts from 1
        hasDeadEnd(root, 1, INT_MAX, ans);

        return ans;
    }
};

class Solution2 {
  public:
    void hasDeadEnd(Node* root, int l, int r, bool& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(r-l <= 2) {
                ans = true;
                return;
            }
        }
        hasDeadEnd(root->left, l, root->data, ans);
        hasDeadEnd(root->right, root->data, r, ans);
    }
    bool isDeadEnd(Node *root) {
        bool ans = false;
        hasDeadEnd(root, 0, INT_MAX, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded BST test case
    //          8
    //         / \
    //        5   9
    //       / \
    //      2   7
    //       \
    //        3
    //
    // Dead End exists at node 3 because no value can be inserted further

    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);

    root->left->left = new Node(2);
    root->left->right = new Node(7);

    root->left->left->right = new Node(3);

    cout << (sol.isDeadEnd(root) ? "Dead End Found" : "No Dead End") << endl;

    return 0;
}
