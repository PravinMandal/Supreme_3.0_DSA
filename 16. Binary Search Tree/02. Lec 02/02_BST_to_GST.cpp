//leetcode: 1038. Binary Search Tree to Greater Sum Tree
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
    void storeInorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL) return;
        // inorder: LNR
        storeInorder(root->left, arr);
        arr.push_back(root->val);
        storeInorder(root->right, arr);
    }
    
    void updateTree(TreeNode* root, vector<int>& inorder, int& index) {
        if(root == NULL) return;
        updateTree(root->left, inorder, index);
        root->val = inorder[index];
        index++;
        updateTree(root->right, inorder, index);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;

        //step 1: store the inorder in vector
        vector<int> inorder;
        storeInorder(root, inorder);

        //step 2: ab as per the question rule elements ko uske aage waale elements se plus krna h
        int n = inorder.size();
        for(int i = n - 1; i >= 0; i--) {
            int currValue = inorder[i];
            int nextValue = 0;
            if(i + 1 < n) {
                nextValue = inorder[i + 1];
            }
            int sum = currValue + nextValue;
            inorder[i] = sum;
        }
        
        //step 3: update the tree
        int index = 0;
        updateTree(root, inorder, index);
        return root;
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /* 
       Constructing the following BST:
                4
               / \
              1   6
             / \  / \
            0   2 5  7
                 \
                  3
       Inorder of BST: 0, 1, 2, 3, 4, 5, 6, 7
       
       For Greater Sum Tree (GST), each node's new value is the sum of all values greater than or equal to it.
       Expected new inorder (GST): [28, 28, 27, 25, 22, 18, 13, 7]
    */
    
    // Creating the BST nodes
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    TreeNode* newRoot = sol.bstToGst(root);
    
    cout << "Inorder traversal of the Greater Sum Tree: ";
    printInorder(newRoot);
    cout << endl;
    
    return 0;
}
