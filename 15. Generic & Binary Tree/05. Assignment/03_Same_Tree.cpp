//leetcode: 100 Same Tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL, trees are identical up to this point
        if(!p && !q) return true;

        // If both nodes exist, compare values and recurse on children
        if(p && q) {
            if(p->val != q->val) return false;

            bool left = isSameTree(p->left, q->left);
            bool right = isSameTree(p->right, q->right);

            return left && right;
        }

        //ek mai node exist krta hai and ek null hai, mtlb identical nhi hai dono tree
        return false;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case 1: Identical trees
    // Tree 1:        Tree 2:
    //     1              1
    //    / \            / \
    //   2   3          2   3
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    cout << "Are trees 1 identical? "
         << (sol.isSameTree(p1, q1) ? "Yes" : "No") << endl;

    // Hardcoded test case 2: Different trees
    // Tree 1:        Tree 2:
    //     1              1
    //    /                \
    //   2                  2
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    cout << "Are trees 2 identical? "
         << (sol.isSameTree(p2, q2) ? "Yes" : "No") << endl;

    return 0;
}
