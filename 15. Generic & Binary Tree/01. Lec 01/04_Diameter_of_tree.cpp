//leetcode: 543. Diameter of Binary Tree
#include <iostream>
using namespace std;

// TreeNode class to represent each node in the binary tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to calculate the height of a subtree
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left, right) + 1;
    }
    
    // Function to compute the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int option1 = diameterOfBinaryTree(root->left);    // Diameter in left subtree
        int option2 = diameterOfBinaryTree(root->right);   // Diameter in right subtree
        int option3 = getHeight(root->left) + getHeight(root->right);  // Path through root
        return max(option3, max(option1, option2));
    }
};

int main() {
    // Constructing a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;  // Output should be 3
    
    // Cleanup (optional, for completeness)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}