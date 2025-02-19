//gfg: left view of binary tree
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node using class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with a given value
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void solve(Node* root, int level, vector<int>& ans) {
        if(root == NULL) return;
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
    }

    vector<int> leftView(Node* root) {
        vector<int> ans;
        int level = 0;
        solve(root, level, ans);
        return ans;
    }
};

int main() {
    // Constructing the following binary tree:
    /*
                 1
                / \
               2   3
              /   / \
             4   5   6
              \
               7

       Expected Left View: 1, 2, 4, 7
    */

    // Creating nodes of the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(7);

    // Create an object of Solution and get the left view of the tree
    Solution sol;
    vector<int> left_view = sol.leftView(root);

    // Output the left view
    cout << "Left View of the Tree: ";
    for (int val : left_view) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
