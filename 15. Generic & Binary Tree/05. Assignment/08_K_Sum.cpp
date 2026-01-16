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

class Solution2 {
public:
    int count = 0;
    unordered_map<long long, int> mp;

    void pathSumOne(TreeNode* root, long long currsum, int& targetsum) {
        if(!root) return;

        // Add current node value to running prefix sum
        currsum += root->val;

        // If prefix sum itself equals target, one valid path found
        if(currsum == targetsum) count++;

        // Check how many times (currsum - target) has appeared before
        if(mp.find(currsum - targetsum) != mp.end())
            count += mp[currsum - targetsum];

        // Store current prefix sum in map
        mp[currsum]++;

        // Continue DFS on left and right subtrees
        pathSumOne(root->left, currsum, targetsum);
        pathSumOne(root->right, currsum, targetsum);

        // Backtrack: remove current prefix sum before returning to parent
        mp[currsum]--; //backtrack, kyuki same line mai hona chahiye baju wale mai nhi;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return count;

        // Start DFS with initial prefix sum = 0
        pathSumOne(root, 0, targetSum);
        return count;
    }
};

int main() {
    Solution2 sol;

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
