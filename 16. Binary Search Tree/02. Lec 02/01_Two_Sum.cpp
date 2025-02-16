//leetcode: 653. Two Sum IV - Input is a BST
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void storeInorder(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) return;
        //inorder:- LNR
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }
    bool checkTwoSum(vector<int> arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        while(s < e) {
            int sum = arr[s] + arr[e];
            if(sum == target) {
                return true;
            }
            if(sum < target) {
                s++;
            }
            if(sum > target) {
                e--;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);
        bool ans = checkTwoSum(inorder, k);
        return ans;
    }
};

int main() {
    // Constructing the following binary tree:
    /*
             5
            / \
           3   6
          / \   \
         2   4   7
    */
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    int target = 9; // Example target: 2 + 7 = 9
    bool found = sol.findTarget(root, target);
    
    cout << "Target " << target << (found ? " is " : " is not ") << "found in the BST." << endl;
    
    return 0;
}
