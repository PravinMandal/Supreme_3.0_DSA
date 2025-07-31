//leetcode: 98. Validate Binary Search Tree

#include <iostream>
#include <climits>
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
    void solve(TreeNode* root, TreeNode*& prev, bool& ans) {
        if (!root) return;

        solve(root->left, prev, ans);
        if (prev && root->val <= prev->val) {
            ans = false;
            return;
        }
        prev = root;
        solve(root->right, prev, ans);
    }

    bool solve2(TreeNode* root, long long lb, long long ub) {
        if (!root) return true;
        bool isCurrentNodeInRange = (lb < root->val && root->val < ub);
        bool left = true;
        bool right = true;
        if (isCurrentNodeInRange) {
            left = solve2(root->left, lb, root->val);
            right = solve2(root->right, root->val, ub);
        }
        return isCurrentNodeInRange && left && right;
    }

    bool solve3(TreeNode* root, long long lb, long long ub) {
        if (!root) return true;
        return (lb < root->val && root->val < ub) &&
               solve3(root->left, lb, root->val) &&
               solve3(root->right, root->val, ub);
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        TreeNode* prev = nullptr;
        // Method 1
        // solve(root, prev, ans);
        // return ans;

        // Method 2 (preferred)
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;
        return solve3(root, lb, ub);
    }
};

int main() {
    // BST used:
    //       5
    //      / \
    //     3   7
    //    / \
    //   2   4

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution sol;
    if (sol.isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Not a valid BST" << endl;

    // Free memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
