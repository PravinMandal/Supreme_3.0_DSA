//leetcode: 230. Kth Smallest Element in a BST
#include <iostream>
using namespace std;

// Definition for a binary tree node using class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize a tree node with a given value
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void solve(TreeNode* root, int k, int& index, int& ans) {
        if(root == NULL) return;
        solve(root->left, k, index, ans);
        if(index == k) {
            ans = root->val;
        }
        index++;
        solve(root->right, k, index, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int index = 1;
        int ans = 0;
        solve(root, k, index, ans);
        return ans;
    }
};

int main() {
    /*
       Constructing the following BST:
       
               5
              / \
             3   6
            / \
           2   4
          /
         1
       
       Inorder Traversal of BST: 1, 2, 3, 4, 5, 6
       For k = 3, the kth smallest element is 3.
    */
    
    // Creating nodes of the BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    
    // Creating an object of Solution and finding the kth smallest element
    Solution sol;
    int k = 3;
    int kth_small = sol.kthSmallest(root, k);
    cout << "The " << k << "rd smallest element in the BST is: " << kth_small << endl;
    
    return 0;
}
