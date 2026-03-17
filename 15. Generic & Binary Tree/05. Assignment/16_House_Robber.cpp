//leetcode: 337. House Robber III

#include <bits/stdc++.h>
using namespace std;

// Actual TreeNode structure used for compilation
// (LeetCode comment block removed as instructed)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    unordered_map<TreeNode*, vector<int>> dp;

    // solve(root, go)
    // go = true  -> we are allowed to rob this node
    // go = false -> we are NOT allowed to rob this node
    int solve(TreeNode* root, bool go) {

        // Base case: no node means no money
        if(!root) return 0;

        // If already computed, return stored result
        if(dp[root].size() && dp[root][go] != -1) return dp[root][go];

        // Initialize dp for this node if not done yet
        if(dp[root].empty())
            dp[root] = vector<int> (2,-1);

        int ans = 0;

        if(go) {
            // Option 1: Rob this node
            // Then we cannot rob its children
            int take = root->val + solve(root->left, false) + solve(root->right, false);

            // Option 2: Skip this node
            // Then we can rob children
            int skip = solve(root->left, true) + solve(root->right, true);

            // Take maximum of both choices
            ans = max(take, skip);
        } 
        else {
            // If we cannot rob this node,
            // we are free to rob both children
            ans = solve(root->left, true) + solve(root->right, true);
        }

        // Store result in dp and return
        return dp[root][go] = ans;
    }

    int rob(TreeNode* root) {

        // Start with permission to rob root
        return solve(root, true);
    }
};

int main() {

    // Hardcoded test case

    /*
            3
           / \
          2   3
           \   \
            3   1

        Expected output = 7
        (3 + 3 + 1)
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution obj;

    int result = obj.rob(root);

    cout << "Maximum money that can be robbed: " << result << endl;

    return 0;
}