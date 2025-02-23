//leetcode: 958. Check Completeness of a Binary Tree
#include <iostream>
#include <queue>
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
    bool solve(TreeNode* root) {
        queue<TreeNode*> q;
        //initial state maintain kro
        q.push(root);
        bool nullFound = false; //ek flag bana liye
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL) {
                nullFound = true;
            }
            else {
                //front ek valid node h
                if(nullFound == true) {
                    //mtlb null ke baad koi node mila hai
                    //mtlb not a CBT
                    return false;
                }
                else {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        bool ans = solve(root);
        return ans;
    }
};

int main() {
    // Test Case 1: Complete Binary Tree
    /*
         Constructing the following complete binary tree:
         
                 1
               /   \
              2     3
             / \   / 
            4   5 6  
         
         Expected Output: Complete Tree (true)
    */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    
    Solution sol;
    bool isComplete1 = sol.isCompleteTree(root1);
    cout << "The first tree is " << (isComplete1 ? "complete" : "not complete") << "." << endl;
    
    // Test Case 2: Incomplete Binary Tree
    /*
         Constructing the following incomplete binary tree:
         
                 1
               /   \
              2     3
               \
                4
         
         Expected Output: Not a Complete Tree (false)
    */
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    
    bool isComplete2 = sol.isCompleteTree(root2);
    cout << "The second tree is " << (isComplete2 ? "complete" : "not complete") << "." << endl;
    
    return 0;
}
