//106. Construct Binary Tree from Inorder and Postorder Traversal
#include <iostream>
#include <vector>
#include <unordered_map>
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
    void createMapping(unordered_map<int,int>& valMap, vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            int element = inorder[i];
            int index = i;
            valMap[element] = index;
        }
    }
    
    TreeNode* constructTree(unordered_map<int,int>& valMap, vector<int>& inorder, vector<int>& postorder, int& postorderIndex,
                             int inorderStart, int inorderEnd){
        //base case
        if(postorderIndex < 0) return NULL;
        if(inorderStart > inorderEnd) return NULL;

        int element = postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root = new TreeNode(element);
        int elementIndexinInorder = valMap[element];
        //postorder ka rightmost element hi root node hoga and piche se start ki taraf aate h toh hume dry run mai dikha
        //ki right to left aate wakt postorder mai jo element h wo inorder ke right mai hota h 
        // isiliye pehle right call then left
        //right call 
        root->right = constructTree(valMap, inorder, postorder, postorderIndex, elementIndexinInorder+1 , inorderEnd);
        //left call
        root->left = constructTree(valMap, inorder, postorder, postorderIndex, inorderStart, elementIndexinInorder-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        unordered_map<int,int> valMap;
        createMapping(valMap, inorder);
        TreeNode* root = constructTree(valMap, inorder, postorder, postorderIndex, inorderStart, inorderEnd);
        return root;
    }
};

// Helper function to print the inorder traversal of the tree
void printInorder(TreeNode* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Driver function to test the buildTree function
int main() {
    Solution obj;
    
    // Hardcoded test case:
    // Inorder and Postorder traversals of the binary tree.
    // Example:
    // Inorder   : {9, 3, 15, 20, 7}
    // Postorder : {9, 15, 7, 20, 3}
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = obj.buildTree(inorder, postorder);

    // Printing the inorder traversal of the constructed tree for verification.
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
       
       Explanation:
       - The last element in postorder (3) is the root.
       - In inorder, elements left to 3 form the left subtree {9} and right form the right subtree {15,20,7}.
       - The tree is built recursively using the mapping for fast lookup.
    */

    return 0;
}
