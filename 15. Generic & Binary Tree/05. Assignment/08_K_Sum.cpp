//leetcode: 437 Path Sum III

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
    int count = 0;

    void pathSumOne(TreeNode* root, long long sum) {
        if(!root) return;

        // Subtract current node value from remaining sum
        sum = sum - root->val;

        // If remaining sum becomes zero, one valid path is found
        if(sum == 0) count++;

        // Continue checking paths downward
        pathSumOne(root->left, sum);
        pathSumOne(root->right, sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return count;

        // Count paths starting from current node
        pathSumOne(root, targetSum);

        // Try paths starting from left and right subtrees
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    //          10
    //         /  \
    //        5   -3
    //       / \    \
    //      3   2    11
    //     / \   \
    //    3  -2   1
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;

    cout << "Number of paths with sum " << targetSum << " = "
         << sol.pathSum(root, targetSum) << endl;

    return 0;
}
