//leetcode: 236. Lowest Common Ancestor of a Binary Tree
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

class Solution {
public:
    // Function to find the Lowest Common Ancestor (LCA) of two given nodes
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL; // Base case: if the tree is empty
        if(root->val == p->val) return p; // If root matches p, return p
        if(root->val == q->val) return q; // If root matches q, return q

        // Recur for left and right subtrees
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // If both leftAns and rightAns are NULL, p and q are not found in this subtree
        if(leftAns == NULL && rightAns == NULL) return NULL;

        // If only one side is non-null, return that side
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;

        // If both left and right answers are non-null, the current root is the LCA
        else return root; 
    }
};

// Function to create a sample binary tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

// Driver function to test the LCA function
int main() {
    Solution obj;
    TreeNode* root = createTree();

    TreeNode* p = root->left;      // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
