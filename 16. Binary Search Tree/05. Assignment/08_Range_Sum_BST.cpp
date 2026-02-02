//leetcode: 938 Range Sum of BST

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
    void getRangeSum(TreeNode* root, int& l, int& h, int& sum) {
        if(!root) return;

        // If current node value is greater than low, left subtree may have valid nodes
        if(root->val > l)
            getRangeSum(root->left, l, h, sum);

        // Add current node value if it lies within range
        if(root->val >= l && root->val <= h) 
            sum += root->val;

        // If current node value is smaller than high, right subtree may have valid nodes
        if(root->val < h)
            getRangeSum(root->right, l, h, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        // Compute sum of nodes lying within [low, high]
        getRangeSum(root, low, high, sum);

        return sum;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case (BST)
    //          10
    //         /  \
    //        5    15
    //       / \     \
    //      3   7     18
    //
    // Range [7, 15]
    // Nodes included: 7,10,15
    // Sum = 32

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(18);

    int low = 7, high = 15;

    cout << "Range Sum BST [" << low << ", " << high << "] = "
         << sol.rangeSumBST(root, low, high) << endl;

    return 0;
}
