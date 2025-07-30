//leetcode: 222. Count Complete Tree Nodes

#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
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
    int findLeftHeight(TreeNode* root) { // logn
        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* root) { //logn
        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        //ye solution worst case mai bhi o(logn * logn) hi lega
        if(!root) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh) return (1<<lh)-1; //(2^lh)-1 or (2^rh)-1, full complete binary tree hai

        int lans = countNodes(root->left);
        int rans = countNodes(root->right);
        return 1+lans+rans;
    }
};

int main() {
    // Tree used:
    //         1
    //        / \
    //       2   3
    //      / \  /
    //     4  5 6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    int totalNodes = sol.countNodes(root);
    cout << "Total number of nodes in the complete binary tree: " << totalNodes << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
