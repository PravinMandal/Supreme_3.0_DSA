//leetcode: 114 Flatten Binary Tree to Linked List

#include <bits/stdc++.h>
using namespace std;

// Actual TreeNode definition required for compilation
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        // Morris-style traversal to flatten the tree in-place
        while(curr) {
            if(curr->left) {
                // Find rightmost node of left subtree
                TreeNode* pred = curr->left;
                while(pred->right) pred = pred->right;

                // Attach original right subtree to the rightmost node
                pred->right = curr->right;

                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            // Move to next node in the flattened list
            curr = curr->right;
        }
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    // Original Tree:
    //        1
    //       / \
    //      2   5
    //     / \   \
    //    3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    sol.flatten(root);

    // Print flattened tree (right-skewed linked list)
    cout << "Flattened Tree (Right Linked List): ";
    TreeNode* curr = root;
    while(curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}
