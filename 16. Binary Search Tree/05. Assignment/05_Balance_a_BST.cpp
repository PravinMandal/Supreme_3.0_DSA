//leetcode: 1382 Balance a Binary Search Tree

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
    void getinorder(TreeNode* root, vector<int>& inorder) {
        if(!root) return;

        // Inorder traversal gives sorted values for BST
        getinorder(root->left, inorder);
        inorder.push_back(root->val);
        getinorder(root->right, inorder);
    }

    TreeNode* getbalanceBST(vector<int>& inorder, int s, int e) {
        if(s > e) return NULL;

        // Choose middle element as root for balanced BST
        int mid = s + (e - s) / 2;

        TreeNode* root = new TreeNode(inorder[mid]);

        // Recursively build left and right balanced subtrees
        root->left = getbalanceBST(inorder, s, mid - 1);
        root->right = getbalanceBST(inorder, mid + 1, e);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;

        // Step 1: Store inorder traversal of BST
        getinorder(root, inorder);

        int s = 0;
        int e = inorder.size() - 1;

        // Step 2: Build balanced BST from sorted inorder array
        TreeNode* ans = getbalanceBST(inorder, s, e);

        return ans;
    }
};

// Helper function to print inorder traversal
void inorderPrint(TreeNode* root) {
    if(!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    Solution sol;

    // Hardcoded test case (Unbalanced BST)
    //        1
    //         \
    //          2
    //           \
    //            3
    //             \
    //              4
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Inorder of Original BST: ";
    inorderPrint(root);
    cout << endl;

    TreeNode* balancedRoot = sol.balanceBST(root);

    cout << "Inorder of Balanced BST: ";
    inorderPrint(balancedRoot);
    cout << endl;

    return 0;
}
