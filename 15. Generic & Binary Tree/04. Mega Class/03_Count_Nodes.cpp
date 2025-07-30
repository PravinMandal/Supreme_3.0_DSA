//leetcode: 222. Count Complete Tree Nodes

#include <iostream>
#include <vector>
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
    void solve(TreeNode* root, int& count) {
        if (!root) return;
        count++;
        solve(root->left, count);
        solve(root->right, count);
    }

    int countNodes(TreeNode* root) {
        int count = 0;
        solve(root, count);
        return count;
    }
};

int main() {
    // Creating the following binary tree:
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
    cout << "Total number of nodes in the tree: " << totalNodes << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
