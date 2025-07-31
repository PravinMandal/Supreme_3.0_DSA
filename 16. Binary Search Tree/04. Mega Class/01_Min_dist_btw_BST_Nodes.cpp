//leetcode: 783. Minimum Distance Between BST Nodes

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void solve(TreeNode* root, int& mini, int& prev) {
        if(!root) return;

        solve(root->left, mini, prev);
        mini = min(mini, abs((root->val) - prev));
        prev = root->val; // agar globally store krna hai toh prev aise store krna
        //warna pass by reference krne ke baad bhi prev globally update nhi hoga
        solve(root->right, mini, prev);
    }

    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        int prev = INT_MAX;
        solve(root, mini, prev);
        return mini;
    }
};

int main() {
    // BST used:
    //       4
    //      / \
    //     2   6
    //    / \
    //   1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int result = sol.minDiffInBST(root);
    cout << "Minimum difference in BST: " << result << endl;

    // Free memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
