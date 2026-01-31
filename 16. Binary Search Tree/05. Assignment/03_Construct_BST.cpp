//leetcode: 1008 Construct Binary Search Tree from Preorder Traversal

#include <bits/stdc++.h>
using namespace std;

// Actual TreeNode definition required for compilation
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// TC : O(n*n) kyuki har baar root se start kr rhe hai
class Solution {
public:
    TreeNode* buildBST(TreeNode* root, int key) {
        if(!root) {
            // If position is empty, create new node
            return new TreeNode(key);
        }

        // Insert key into left subtree if smaller
        if(root->val > key) {
            root->left = buildBST(root->left, key);
        }
        // Insert key into right subtree if greater
        else {
            root->right = buildBST(root->right, key);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        // Insert each preorder element into BST one by one
        for(int i=0; i<preorder.size(); i++) {
            if(i == 0) {
                root = new TreeNode(preorder[0]);
            } else {
                buildBST(root, preorder[i]);
            }
        }

        return root;
    }
};

// best solution -> O(N)
// preorder traverse krte krte hi BST bana rhe hai
class Solution2 {
public:
    TreeNode* buildBST(vector<int>& preorder, int& i, int mini, int maxi) {
        if(i >= preorder.size()) return NULL;

        TreeNode *root = NULL;
        int curr = preorder[i];

        // Only create node if current value lies in valid range
        if(curr > mini && curr < maxi) {
            root = new TreeNode(curr);
            i++;

            // Left subtree must have values smaller than curr
            root->left = buildBST(preorder, i, mini, curr);

            // Right subtree must have values greater than curr
            root->right = buildBST(preorder, i, curr, maxi);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int index = 0;

        TreeNode* root = buildBST(preorder, index, mini, maxi);
        return root;
    }
};

// Helper function to print inorder traversal (to verify BST)
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution2 sol;

    // Hardcoded test case
    // Preorder: [8, 5, 1, 7, 10, 12]
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = sol.bstFromPreorder(preorder);

    // Print inorder traversal (should be sorted if BST is correct)
    cout << "Inorder Traversal of Constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
