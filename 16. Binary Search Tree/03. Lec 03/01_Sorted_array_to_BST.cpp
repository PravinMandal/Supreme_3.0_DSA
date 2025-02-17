//leetcode: 108. Convert Sorted Array to Binary Search Tree
#include <iostream>
#include <vector>
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
    TreeNode* solve(vector<int>& inorder, int s, int e){
        if(s > e) return NULL; //base case

        int mid = s + (e - s) / 2;
        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);
        root->left = solve(inorder, s, mid - 1);
        root->right = solve(inorder, mid + 1, e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& inorder) {
        int s = 0;
        int n = inorder.size();
        int e = n - 1;
        TreeNode* root = solve(inorder, s, e);
        return root;
    }
};

// Helper function to print the inorder traversal of the BST
void printInorder(TreeNode* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
       Given Sorted Array (Inorder): [1, 2, 3, 4, 5, 6, 7]
       
       Expected Balanced BST:
       
                4
               / \
              2   6
             / \ / \
            1  3 5  7
       
       Inorder traversal of the constructed BST should output:
       1 2 3 4 5 6 7
    */
    
    vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7};
    
    Solution sol;
    TreeNode* bstRoot = sol.sortedArrayToBST(sortedArr);
    
    cout << "Inorder traversal of the constructed BST: ";
    printInorder(bstRoot);
    cout << endl;
    
    return 0;
}
