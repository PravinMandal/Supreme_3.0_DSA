//leetcode: 104. Maximum Depth of Binary Tree
#include <iostream>
using namespace std;

// Definition for a binary tree node using class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Given class with maxDepth method
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftSubtreeHeight = maxDepth(root->left);
        int rightSubtreeHeight = maxDepth(root->right);
        int maxAns = max(leftSubtreeHeight, rightSubtreeHeight);
        int totalAns = maxAns + 1;
        return totalAns;
    }
};

// Function to create a sample tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

// Main function (driver code)
int main() {
    // Hardcoded test case: Creating a sample tree
    TreeNode* root = createSampleTree();
    
    Solution obj;
    int depth = obj.maxDepth(root);

    cout << "Maximum Depth of the Binary Tree: " << depth << endl;

    return 0;
}
