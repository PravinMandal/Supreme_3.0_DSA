//leetcode: 543 Diameter of Binary Tree

#include <bits/stdc++.h>
using namespace std;

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
    int getHeight(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }

        // Recursively calculate height of left & right subtree
        int left = getHeight(root->left, ans);
        int right = getHeight(root->right, ans);

        // Height of current node
        int totalHeight = max(left, right) + 1;

        // Diameter passing through current node
        int diameter = left + right;
        // Update maximum diameter found so far
        ans = max(ans, diameter);

        return totalHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        getHeight(root, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case 1
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    cout << "Diameter of tree 1: "
         << sol.diameterOfBinaryTree(root1) << endl;

    // Hardcoded test case 2
    //       1
    //        \
    //         2
    //          \
    //           3
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);

    Solution sol2; // separate object to avoid shared state
    cout << "Diameter of tree 2: "
         << sol2.diameterOfBinaryTree(root2) << endl;

    return 0;
}
