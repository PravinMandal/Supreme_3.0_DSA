//leetcode: 94 Binary Tree Inorder Traversal

#include <bits/stdc++.h>
using namespace std;

// Actual TreeNode definition required for compilation
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        // Morris Inorder Traversal (O(1) extra space)
        while(curr) {
            if(curr->left == NULL) {
                // If no left child, visit current node and move right
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while(pred->right != curr && pred->right) {
                    pred = pred->right;
                }

                if(pred->right == NULL) {
                    // Make temporary thread to current node
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    // Thread already exists, remove it and visit current
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        } 
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    //        1
    //         \
    //          2
    //         /
    //        3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = sol.inorderTraversal(root);

    // Print inorder traversal
    cout << "Inorder Traversal: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
