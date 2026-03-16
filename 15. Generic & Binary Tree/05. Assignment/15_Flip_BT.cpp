//leetcode: 971. Flip Binary Tree To Match Preorder Traversal

#include <bits/stdc++.h>
using namespace std;

// Actual TreeNode structure used for compilation
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
    int i;

    // This recursive function performs preorder traversal
    // and compares it with the given voyage sequence
    void solve(TreeNode* root, vector<int>& voyage, vector<int>& ans) {

        // Base case
        if(!root) return;

        // If current node does not match expected voyage value
        if(root->val != voyage[i]) {
            ans = {-1};
            return;
        }

        // Move to next index of voyage
        i++;

        // If left child exists but next voyage value doesn't match it,
        // we need to flip left and right children
        if(root->left && i<voyage.size() && root->left->val != voyage[i]) {

            // Record flip node
            ans.push_back(root->val);

            // Swap children
            swap(root->left, root->right);
        }

        // Continue preorder traversal
        solve(root->left, voyage, ans);
        solve(root->right, voyage, ans);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {

        // index pointer for voyage
        i = 0;

        vector<int> ans;

        solve(root, voyage, ans);

        // If impossible case
        if(!ans.empty() && ans[0] == -1) return {-1};

        return ans;
    }
};

int main() {

    // Hardcoded test case

    /*
        Tree:
            1
           / \
          2   3

        Voyage = [1,3,2]
        Flip required at node 1
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> voyage = {1,3,2};

    Solution obj;

    vector<int> result = obj.flipMatchVoyage(root, voyage);

    cout << "Flip Nodes: ";

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}