//leetcode: 543. Diameter of Binary Tree
#include <iostream>
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

// Given class with getHeight and diameterOfBinaryTree methods
class Solution {
public:
    // Function to calculate the height of a binary tree
    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0; // base case: height of an empty tree is 0
        }

        // Recursive call to get the height of the left and right subtrees
        int left = getHeight(root->left);
        int right = getHeight(root->right);

        // Max height between left and right subtree + 1 for the current node
        int maxAns = max(left, right);
        int totalAns = maxAns + 1;
        return totalAns;
    }

    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0; // base case: diameter of an empty tree is 0
        }

        // Option 1: diameter of the left subtree
        int option1 = diameterOfBinaryTree(root->left);
        // Option 2: diameter of the right subtree
        int option2 = diameterOfBinaryTree(root->right);
        // Option 3: diameter passing through the root (height of left + height of right)
        int option3 = getHeight(root->left) + getHeight(root->right);

        // The diameter is the maximum of the three options
        int maxAns = max(option1, max(option2, option3));
        return maxAns;
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
    int diameter = obj.diameterOfBinaryTree(root);

    cout << "Diameter of the Binary Tree: " << diameter << endl;

    return 0;
}
