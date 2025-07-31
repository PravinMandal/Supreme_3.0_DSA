//leetcode: 173. Binary Search Tree Iterator

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Method 1: vector based
class BSTIterator0 {
public:
    vector<int> inorder;
    int i = 0;

    void storeInorder(TreeNode* root) {
        if(!root) return;
        storeInorder(root->left);
        inorder.push_back(root->val);
        storeInorder(root->right);
    }

    BSTIterator0(TreeNode* root) {
        storeInorder(root);
    }

    int next() {
        return inorder[i++];
    }

    bool hasNext() {
        return (i < inorder.size());
    }
};

//Method 2 : recursive inorder traversal jaisa hi h but recursion ke jagah stack use kr rhe h
//stack ka use isiliye kr rhe h taaki space bache
// vector use kregne toh o(n) space lega
// but stack use krenge toh o(h) space lega , h->height of BST, average case mai
// skew BST rha toh worst case mai ye bhi o(n) lega
class BSTIterator {
    stack<TreeNode*> st;

    void pushLeftNode(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeftNode(root);
    }

    int next() {
        auto top = st.top();
        st.pop();

        if(top->right) {
            pushLeftNode(top->right);
        }
        return top->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

// Main function to test both BSTIterator0 and BSTIterator
int main() {
    /*
        Constructing the following BST:
                7
               / \
              3   15
                 /  \
                9    20
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    cout << "Using BSTIterator0 (vector based):\n";
    BSTIterator0 it0(root);
    while(it0.hasNext()) {
        cout << it0.next() << " ";
    }

    cout << "\n\nUsing BSTIterator (stack based):\n";
    BSTIterator it(root);
    while(it.hasNext()) {
        cout << it.next() << " ";
    }

    return 0;
}
