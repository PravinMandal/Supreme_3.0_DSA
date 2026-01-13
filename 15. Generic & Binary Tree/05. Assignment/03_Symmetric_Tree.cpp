//leetcode: 101 Symmetric Tree

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
    bool checkSymmetric(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(p && q) {
            if(p->val != q->val) return false;

            bool one = checkSymmetric(p->left, q->right);
            bool two = checkSymmetric(p->right, q->left);

            return one && two;
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left, root->right);
    }
};

int main() {
    Solution sol;

    // Hardcoded test case 1: Symmetric tree
    //        1
    //       / \
    //      2   2
    //     / \ / \
    //    3  4 4  3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    cout << "Is tree 1 symmetric? "
         << (sol.isSymmetric(root1) ? "Yes" : "No") << endl;

    // Hardcoded test case 2: Not symmetric
    //        1
    //       / \
    //      2   2
    //       \   \
    //        3   3
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    Solution sol2; // separate object for clarity
    cout << "Is tree 2 symmetric? "
         << (sol2.isSymmetric(root2) ? "Yes" : "No") << endl;

    return 0;
}
