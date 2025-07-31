//leetcode: 653. Two Sum IV - Input is a BST

#include <iostream>
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

class BSTIterator {
    stack<TreeNode*> st;
    stack<TreeNode*> revSt;

    void pushLeftNode(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

    void pushRightNode(TreeNode* root) {
        while(root) {
            revSt.push(root);
            root = root->right;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeftNode(root);
        pushRightNode(root);
    }

    int next() {
        auto top = st.top();
        st.pop();
        if(top->right) {
            pushLeftNode(top->right);
        }
        return top->val;
    }

    int before() {
        auto top = revSt.top();
        revSt.pop();
        if(top->left) {
            pushRightNode(top->left);
        }
        return top->val;
    }

    bool hasNext() {
        return !st.empty();
    }

    bool hasBefore() {
        return !revSt.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //stack ka use isiliye kr rhe h taaki space bache
        // vector use kregne toh o(n) space lega
        // but stack use krenge toh o(h) space lega , h->height of BST, average case mai
        // skew BST rha toh worst case mai ye bhi o(n) lega
        BSTIterator it(root);
        int i = it.next(); //smallest
        int j = it.before(); //largest

        while(i < j) {
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k)
                i = it.next(); //similar to i++
            else
                j = it.before(); //similar to j--
        }
        return false;
    }
};

// Helper function to create a test tree
TreeNode* createTestTree() {
    /*
           5
          / \
         3   6
        / \   \
       2   4   7
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    root->right = new TreeNode(6, nullptr, new TreeNode(7));
    return root;
}

int main() {
    TreeNode* root = createTestTree();
    Solution sol;

    int k1 = 9; // 2 + 7
    int k2 = 28; // not present

    cout << "Does the tree contain two elements that sum to " << k1 << "? " << (sol.findTarget(root, k1) ? "Yes" : "No") << endl;
    cout << "Does the tree contain two elements that sum to " << k2 << "? " << (sol.findTarget(root, k2) ? "Yes" : "No") << endl;

    return 0;
}
