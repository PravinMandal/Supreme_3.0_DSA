//leetcode: 652 Find Duplicate Subtrees
// imp

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
    vector<TreeNode*> ans;
    unordered_map<string, int> subTreeMap;

    string preorder(TreeNode* root) {
        if(!root) return "N";

        // Serialize current subtree using preorder traversal
        string curr = to_string(root->val);
        string l = preorder(root->left);
        string r = preorder(root->right);

        string s = curr + "," + l + "," + r;

        // If subtree serialization already exists, it's a duplicate
        if(subTreeMap.find(s) != subTreeMap.end()) {

            // Only push once when it appears the second time
            if(subTreeMap[s] == 1)
                ans.push_back(root);

            subTreeMap[s]++;
        }
        else {
            subTreeMap[s] = 1;
        }

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    //        1
    //       / \
    //      2   3
    //     /   / \
    //    4   2   4
    //       /
    //      4
    //
    // Duplicate subtrees are:
    //   [2,4]
    //   [4]

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    vector<TreeNode*> duplicates = sol.findDuplicateSubtrees(root);

    cout << "Duplicate Subtree Roots Values: ";
    for(auto node : duplicates) {
        cout << node->val << " ";
    }
    cout << endl;

    return 0;
}
