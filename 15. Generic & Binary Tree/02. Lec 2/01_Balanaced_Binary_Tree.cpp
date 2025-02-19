//leetcode: 110. Balanced Binary Tree
#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node using class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a tree node
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Given class with getHeight and isBalanced methods
class Solution {
public:
    // Function to calculate the height of a binary tree
    int getHeight(TreeNode* root) {
        if(root == NULL) return 0; // Base case: height of an empty tree is 0

        int lh = getHeight(root->left);  // Recursively find the height of the left subtree
        int rh = getHeight(root->right); // Recursively find the height of the right subtree

        int maxAns = max(lh, rh); // Find the maximum of left and right subtree heights
        int Ans = maxAns + 1; // Add 1 for the current node
        return Ans;
    }

    // Function to check if a binary tree is balanced
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true; // Base case: an empty tree is always balanced

        // Get the height of the left and right subtrees
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        // Calculate the absolute difference between left and right subtree heights
        int absDiff = abs(lh - rh);
        bool status = (absDiff <= 1); // A tree is balanced if the height difference is at most 1

        // Recursively check if the left and right subtrees are balanced
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        // The tree is balanced if:
        // - The current node is balanced
        // - The left subtree is balanced
        // - The right subtree is balanced
        if(status && leftAns && rightAns) return true;
        else return false;
    }
};

// Function to create a sample balanced tree
TreeNode* createBalancedTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Function to create a sample unbalanced tree
TreeNode* createUnbalancedTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    return root;
}

// Main function (driver code)
int main() {
    Solution obj;

    // Test Case 1: Balanced tree
    TreeNode* balancedRoot = createBalancedTree();
    bool balancedResult = obj.isBalanced(balancedRoot);
    cout << "Is the tree balanced? " << (balancedResult ? "Yes" : "No") << endl;

    // Test Case 2: Unbalanced tree
    TreeNode* unbalancedRoot = createUnbalancedTree();
    bool unbalancedResult = obj.isBalanced(unbalancedRoot);
    cout << "Is the tree balanced? " << (unbalancedResult ? "Yes" : "No") << endl;

    return 0;
}
