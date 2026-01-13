//gfg: Transform to Sum Tree

#include <bits/stdc++.h>
using namespace std;

// Actual Node definition required for compilation
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sumTree(Node* node) {
        if(!node) return 0;

        int leftnode = node->left ? node->left->data : 0;
        int rightnode = node->right ? node->right->data : 0;

        int left = sumTree(node->left);
        int right = sumTree(node->right);

        // Update current node with sum of left and right subtree values
        node->data = leftnode + rightnode + left + right;

        return node->data;
    }

    void toSumTree(Node *node) {
        sumTree(node);
    }
};

class Solution2 {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sumTree(Node* node) {
        if(!node) return 0;
        if(!node->left && !node->right) {
            int temp = node->data;
            node->data = 0;
            return temp;
        }
        int left = sumTree(node->left);
        int right = sumTree(node->right);
        int temp = node->data;
        node->data = left + right;
        return temp + left + right;
    }
    void toSumTree(Node *node) {
        sumTree(node);
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    // Original Tree:
    //        10
    //       /  \
    //      -2   6
    //     / \  / \
    //    8  -4 7   5
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    sol.toSumTree(root);

    // After conversion, print root and its immediate children
    cout << "Root value after Sum Tree conversion: " << root->data << endl;
    cout << "Left child value: " << root->left->data << endl;
    cout << "Right child value: " << root->right->data << endl;

    return 0;
}
