//leetcode: 1373.Maximum Sum BST in Binary Tree
//HW: GFG: Populate Inorder Successor for all nodes
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Definition for a binary tree node using class.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize a tree node with a given value.
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Info {
public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};

class Solution {
public:
    Info solve(TreeNode* root, int& sum) {
        //base case
        if(root == NULL) {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(sum, temp.sum);
            return temp;
        }
        //LRN
        Info leftAns = solve(root->left, sum);
        Info rightAns = solve(root->right, sum);

        //N
        Info currentAns;
        currentAns.minVal = min(leftAns.minVal, min(rightAns.minVal, root->val));
        currentAns.maxVal = max(leftAns.maxVal, max(rightAns.maxVal, root->val));
        currentAns.sum = leftAns.sum + rightAns.sum + root->val;
        currentAns.isBST = (root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isBST && rightAns.isBST);
        //jab bhi BST milega mai tbhi uska sum update kr dunga
        //taaki mere pass max sum aaye
        if(currentAns.isBST) {
            sum = max(sum, currentAns.sum);
        }
        return currentAns;
    }
    
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        Info temp = solve(root, sum);
        return sum;
    }
};

int main() {
    /*
       Constructing the following binary tree:
       
               5
              / \
             3   8
            / \   \
           2   4   9
       
       Explanation:
       - The entire tree is a valid BST.
       - Sum = 5 + 3 + 8 + 2 + 4 + 9 = 31.
       - Thus, the maximum sum of a BST in this tree is 31.
    */
    
    // Creating nodes of the tree.
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);
    
    Solution sol;
    int result = sol.maxSumBST(root);
    cout << "Maximum sum of BST in the tree is: " << result << endl;
    
    return 0;
}
