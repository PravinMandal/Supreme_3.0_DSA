//leetcode: 105. Construct Binary Tree from Preorder and Inorder Traversal
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Definition for a binary tree node using class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a tree node
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Function to get index of an element from inorder traversal
    int getIndexorder(vector<int>& inorder, int element) {
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == element) {
                return i;
            }
        }
        return -1; // If element not found
    }

    // Function to construct tree from preorder and inorder traversals
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int inorderStart, int inorderEnd, int size) {
        // Base cases
        if(preorderIndex >= size || inorderStart > inorderEnd) {
            return NULL;
        }

        // Process the first element of preorder as the root
        int element = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(element);  // Creating the root node

        // Find this element in inorder and recursively build left and right subtrees
        int elementIndexInsideInorder = getIndexorder(inorder, element);
        
        // Recursive calls to build left and right subtrees
        root->left = constructTree(preorder, inorder, preorderIndex, inorderStart, elementIndexInsideInorder - 1, size);
        root->right = constructTree(preorder, inorder, preorderIndex, elementIndexInsideInorder + 1, inorderEnd, size);
        
        return root;
    }

    // Function to initiate tree building
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int size = inorder.size();
        return constructTree(preorder, inorder, preorderIndex, inorderStart, inorderEnd, size);
    }
};

// Function to print inorder traversal of the constructed tree
void printInorder(TreeNode* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to create test case and print the constructed tree
int main() {
    Solution obj;

    // Test case: Preorder and Inorder traversals
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = obj.buildTree(preorder, inorder);

    // Printing the inorder traversal of the constructed tree
    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    /*
       Constructed Binary Tree:
               3
              / \
             9   20
                /  \
               15   7
       
       Inorder Output should be: 9 3 15 20 7
    */

    return 0;
}
