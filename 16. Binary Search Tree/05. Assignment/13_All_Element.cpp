//leetcode: 1305. All Elements in Two Binary Search Trees

#include <bits/stdc++.h>
using namespace std;

// Actual TreeNode structure used for compilation
// (LeetCode comment block removed as instructed)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        
        // Two stacks to simulate inorder traversal of both trees
        stack<TreeNode*> s1, s2;

        // Continue until both trees and stacks are fully processed
        while(root1 || root2 || !s1.empty() || !s2.empty()) {

            // Push all left nodes of tree1
            while(root1) {
                s1.push(root1);
                root1 = root1->left;
            }

            // Push all left nodes of tree2
            while(root2) {
                s2.push(root2);
                root2 = root2->left;
            }

            // Choose the smaller top element between both stacks
            // If s2 is empty OR s1 has smaller/equal value → process s1
            if(s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {

                root1 = s1.top();
                s1.pop();

                // Add to result (in sorted order)
                ans.push_back(root1->val);

                // Move to right subtree
                root1 = root1->right;
            } 
            else {

                root2 = s2.top();
                s2.pop();

                // Add to result
                ans.push_back(root2->val);

                // Move to right subtree
                root2 = root2->right;
            }
        }

        return ans;
    }
};

int main() {

    // Hardcoded test case

    /*
        Tree1:        2
                     / \
                    1   4

        Tree2:        1
                     / \
                    0   3

        Output: [0,1,1,2,3,4]
    */

    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    Solution obj;

    vector<int> result = obj.getAllElements(root1, root2);

    cout << "Merged sorted elements: ";

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}