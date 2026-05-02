//leetcode: 337. House Robber III

#include <bits/stdc++.h>
using namespace std;

// Actual struct for compilation (original comment untouched above)
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
    int solveUsingRec(TreeNode*& root, TreeNode* prev, TreeNode* parent) {
        if(!root) return 0; // Base case: no node, no money

        int incl = 0, excl = 0;

        // If previous node is not the parent, we are allowed to include current node
        if(prev == NULL || prev != parent) {
            // Include current node value and skip direct children
            incl += root->val + solveUsingRec(root->left, root, root);
            incl += solveUsingRec(root->right, root, root);
        }

        // Exclude current node, so we can consider children freely
        excl += solveUsingRec(root->left, prev, root);
        excl += solveUsingRec(root->right, prev, root);

        // Return maximum profit
        return max(incl, excl);
    }

    int solveUsingMem(TreeNode* root, TreeNode* prev, TreeNode* parent, unordered_map<TreeNode*, unordered_map<TreeNode*, unordered_map<TreeNode*, int>>>& dp) {
        if(!root) return 0;

        // If already computed for this state, return cached value
        if(dp[root][prev].count(parent)) return dp[root][prev][parent];

        int incl = 0, excl = 0;

        if(prev == NULL || prev != parent) {
            incl += root->val + solveUsingMem(root->left, root, root, dp);
            incl += solveUsingMem(root->right, root, root, dp);
        }

        excl += solveUsingMem(root->left, prev, root, dp);
        excl += solveUsingMem(root->right, prev, root, dp);

        // Store result in dp
        dp[root][prev][parent] = max(incl, excl);

        return dp[root][prev][parent];
    }

    int rob(TreeNode* root) {
        // return solveUsingRec(root, NULL, NULL);

        unordered_map<TreeNode*, unordered_map<TreeNode*, unordered_map<TreeNode*, int>>> dp;

        // Use memoization to optimize repeated subtree calculations
        return solveUsingMem(root, NULL, NULL, dp);
    }
};

class Solution2 {
public:
    int solveUsingRec(TreeNode* root) {
        if(!root) return 0;

        int incl = root->val;
        if(root->left) {
            incl += solveUsingRec(root->left->left);
            incl += solveUsingRec(root->left->right);
        }
        if(root->right) {
            incl += solveUsingRec(root->right->left);
            incl += solveUsingRec(root->right->right);
        }

        int excl = solveUsingRec(root->left) + solveUsingRec(root->right);
        return max(incl, excl);
    }
    
    int solveUsingMem(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if(!root) return 0;
        if(dp.count(root)) return dp[root];

        int incl = root->val;
        if(root->left) {
            incl += solveUsingMem(root->left->left, dp);
            incl += solveUsingMem(root->left->right, dp);
        }
        if(root->right) {
            incl += solveUsingMem(root->right->left, dp);
            incl += solveUsingMem(root->right->right, dp);
        }

        int excl = solveUsingMem(root->left, dp) + solveUsingMem(root->right, dp);
        dp[root] = max(incl, excl);
        return max(incl, excl);
    }

    int rob(TreeNode* root) {
        // return solveUsingRec(root);

        unordered_map<TreeNode*, int> dp;
        return solveUsingMem(root, dp);
    }
};

// Helper function to create a sample binary tree
TreeNode* buildSampleTree() {
    // Hardcoded tree:
    //        3
    //       / \
    //      2   3
    //       \   \
    //        3   1

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    return root;
}

int main() {
    Solution2 obj;

    // Build hardcoded test tree
    TreeNode* root = buildSampleTree();

    // Expected output: 7 (3 + 3 + 1)
    cout << "Maximum money that can be robbed: " << obj.rob(root) << endl;

    return 0;
}