//leetcode: 112. Path Sum
#include <iostream>
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
    bool solve(TreeNode* root, int target, int sum) {
        if(root == NULL) return false;
        sum = sum + root->val;

        //agar leaf node pr hai toh check krenge ki target ke equal h ki nhi
        if(root->left == NULL && root->right == NULL) {
            if(sum == target) return true;
            else return false;
        }
        // maine ek case solve kr diya ab aage recursion ko de dete hai

        bool leftAns = solve(root->left, target, sum);
        bool rightAns = solve(root->right, target, sum);

        return leftAns || rightAns;
        // if(leftAns == false && rightAns == false) return false;
        // else if(leftAns == true && rightAns == false) return true;
        // else if(leftAns == false && rightAns == true) return true;
        // else return true;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};

// Function to create a sample binary tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    /* 
       Binary Tree Structure:
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \      \
         7    2      1
    */

    return root;
}

// Driver function to test the hasPathSum function
int main() {
    Solution obj;
    TreeNode* root = createTree();

    int targetSum = 22; // Example test case
    bool result = obj.hasPathSum(root, targetSum);
    
    if (result) {
        cout << "Path with sum " << targetSum << " exists." << endl;
    } else {
        cout << "Path with sum " << targetSum << " does not exist." << endl;
    }

    return 0;
}
