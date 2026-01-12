//leetcode: 110 Balanced Binary Tree

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
    bool isbalanced = true;

    int height(TreeNode* root) {
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if(isbalanced && abs(lh - rh) > 1) {
            isbalanced = false;
            return -1; // yahi ruk jao tree is not balanced proof ho gya, height ka koi kaam nhi h
        }

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case 1: Balanced Binary Tree
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

    cout << "Is tree 1 balanced? "
         << (sol.isBalanced(root1) ? "Yes" : "No") << endl;

    // Hardcoded test case 2: Unbalanced Binary Tree
    //       1
    //      /
    //     2
    //    /
    //   3
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    Solution sol2; // separate object to reset isbalanced flag
    cout << "Is tree 2 balanced? "
         << (sol2.isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}
