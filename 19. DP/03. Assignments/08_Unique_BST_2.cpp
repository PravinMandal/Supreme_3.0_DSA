//leetcode: 95. Unique Binary Search Trees II

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Actual TreeNode definition for compilation (your original comment is untouched above)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> solveUsingRec(int s, int e) {
        if(s>e) return {NULL}; // Base case: empty subtree

        vector<TreeNode*> multipleRoots;

        // Try every number in range as root
        for(int i=s; i<=e; i++) {

            // Generate all possible left and right subtrees
            auto leftArr = solveUsingRec(s, i-1);
            auto rightArr = solveUsingRec(i+1, e);

            // Combine each left subtree with each right subtree
            for(int j=0; j<leftArr.size(); j++) {
                for(int k=0; k<rightArr.size(); k++) {

                    TreeNode* root = new TreeNode(i); // Create root node

                    root->left = leftArr[j];   // Attach left subtree
                    root->right = rightArr[k]; // Attach right subtree

                    multipleRoots.push_back(root); // Store this tree
                }
            }
        }
        return multipleRoots; // Return all possible BSTs
    }
    
    vector<TreeNode*> solveUsingMem(int s, int e, unordered_map<int, unordered_map<int, vector<TreeNode*>>>& dp) {
        if(s>e) return {NULL};

        // Check if already computed for range (s, e)
        if(dp.find(s) != dp.end() && dp[s].find(e) != dp[s].end()) return dp[s][e];
        
        vector<TreeNode*> multipleRoots;

        for(int i=s; i<=e; i++) {

            auto leftArr = solveUsingMem(s, i-1, dp);
            auto rightArr = solveUsingMem(i+1, e, dp);

            for(int j=0; j<leftArr.size(); j++) {
                for(int k=0; k<rightArr.size(); k++) {

                    TreeNode* root = new TreeNode(i);

                    root->left = leftArr[j];
                    root->right = rightArr[k];

                    multipleRoots.push_back(root);
                }
            }
        }

        // Store computed result
        dp[s][e] = multipleRoots;

        return multipleRoots;
    }

    vector<TreeNode*> generateTrees(int n) {
        // return solveUsingRec(1, n);

        unordered_map<int, unordered_map<int, vector<TreeNode*>>> dp;

        // Use memoization to avoid recomputation
        return solveUsingMem(1, n, dp);
    }
};

// Helper function to print tree in preorder (for verification)
void printPreorder(TreeNode* root) {
    if(!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution obj;

    int n = 3; // Hardcoded test case

    vector<TreeNode*> result = obj.generateTrees(n);

    cout << "Generated Trees (Preorder Traversal):\n";

    for(int i = 0; i < result.size(); i++) {
        cout << "Tree " << i+1 << ": ";
        printPreorder(result[i]);
        cout << endl;
    }

    return 0;
}