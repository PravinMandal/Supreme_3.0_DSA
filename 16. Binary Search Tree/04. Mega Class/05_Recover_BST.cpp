//leetcode: 99. Recover Binary Search Tree

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* FV = 0, *SV = 0, *prev = 0;
    //FV -> first violation, SV -> second violation

public:
    void solve(TreeNode* curr) {
        if(!curr) return;

        solve(curr->left);
        if(prev && curr->val < prev->val) {
            //BST property violated
            //means it's not sorted
            if(!FV) FV = prev; //first violation, store previous
            SV = curr; //current node is the second violation
        }
        prev = curr; // move forward
        solve(curr->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);
        if(FV && SV) {
            //both violations detected
            swap(FV->val, SV->val);
        }
    }
};

// In-order traversal to verify if tree is fixed
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Create a tree with swapped nodes
TreeNode* createTestTree() {
    /*
         3
        / \
       1   4
          /
         2

     Swapped: 2 and 3
     Correct: 2 should be root and 3 in left of 4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    return root;
}

int main() {
    TreeNode* root = createTestTree();

    cout << "Before fixing BST: ";
    inorder(root); // Will print wrong in-order
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "After fixing BST: ";
    inorder(root); // Should print sorted in-order
    cout << endl;

    return 0;
}
