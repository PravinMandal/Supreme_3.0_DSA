//leetcode: 235. Lowest Common Ancestor of a Binary Search Tree
#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // normal binary tree wala jo LCA ka code tha wo bhi chal jayega
        if(root == NULL) return NULL;

        //case A: p and q both are in left side
        if(p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            if(leftAns != NULL) {
                return leftAns;
            }
        }
        //case B: p and q both are in right side
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            if(rightAns != NULL) {
                return rightAns;
            }
        }

        //case C: p in left and q in right
        //case D: p in right and q in left 
        //ye dono case else mai aa gye isiliye condition nhi daale toh bhi chalega
        return root;
    }
};

int main() {
    /*
       Constructing the following BST:
       
                 6
               /   \
              2     8
             / \   / \
            0   4 7   9
               / \
              3   5

       Example Cases:
       - If p = 2 and q = 8, then LCA is 6.
       - If p = 2 and q = 4, then LCA is 2.
    */
    
    // Creating nodes of the BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    // Define the nodes for which LCA is to be found.
    // Example 1:
    TreeNode* p1 = root->left;       // Node with value 2
    TreeNode* q1 = root->right;      // Node with value 8

    // Example 2:
    TreeNode* p2 = root->left;       // Node with value 2
    TreeNode* q2 = root->left->right; // Node with value 4

    Solution sol;
    
    TreeNode* lca1 = sol.lowestCommonAncestor(root, p1, q1);
    cout << "Lowest Common Ancestor of " << p1->val << " and " << q1->val << " is: " << lca1->val << endl;
    
    TreeNode* lca2 = sol.lowestCommonAncestor(root, p2, q2);
    cout << "Lowest Common Ancestor of " << p2->val << " and " << q2->val << " is: " << lca2->val << endl;
    
    return 0;
}
