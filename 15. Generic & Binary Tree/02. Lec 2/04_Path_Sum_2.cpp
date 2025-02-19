//leetcode: 113. Path Sum II
#include <iostream>
#include <vector>
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
    void solve(TreeNode* root, int target, vector<vector<int>>& ans, vector<int>& arr, int sum) {
        
        if(root == NULL) return;
        sum = sum + root->val;
        arr.push_back(root->val);

        //ab leaf node pr jaakr check krenge target ke equal h ki nhi
        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                ans.push_back(arr);
            }
            //backtrack krte h 
            //agar arr ko pass by reference nhi krte toh ye step nhi lgta
            //but usse har call pr new space lgta joki inefficient hai
            arr.pop_back();
            return;
        }

        // ab left aur right ke liye solve kr deta hu
        solve(root->left, target, ans, arr, sum);
        solve(root->right, target, ans, arr, sum);

        //backtrack krte h 
        //agar arr ko pass by reference nhi krte toh ye step nhi lgta
        //but usse har call pr new space lgta joki inefficient hai
        arr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;
        int sum = 0;
        solve(root, targetSum, ans, arr, sum);
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    /* 
       Binary Tree Structure:
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \    / \
         7    2  5   1
    */

    return root;
}

// Driver function to test the pathSum function
int main() {
    Solution obj;
    TreeNode* root = createTree();

    int targetSum = 22; // Example test case
    vector<vector<int>> result = obj.pathSum(root, targetSum);
    
    cout << "Paths with sum " << targetSum << " are:\n";
    for (auto path : result) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
