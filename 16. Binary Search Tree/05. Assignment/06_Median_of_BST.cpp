//gfg: Median of BST

#include <bits/stdc++.h>
using namespace std;

// Actual Node definition required for compilation
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    void getinorder(Node* root, vector<int>& inorder) {
        if(!root) return;

        // Inorder traversal of BST gives sorted order
        getinorder(root->left, inorder);
        inorder.push_back(root->data);
        getinorder(root->right, inorder);
    }

    int findMedian(Node* root) {
        vector<int> inorder;

        // Store sorted values of BST
        getinorder(root, inorder);

        // Return middle element (lower median for even size)
        return inorder[(inorder.size() - 1) / 2];
    }
};

int main() {
    Solution sol;

    // Hardcoded test case (BST)
    //          6
    //         / \
    //        3   8
    //       / \   \
    //      1   4   9
    //
    // Inorder: [1,3,4,6,8,9]
    // Median index = (6-1)/2 = 2  -> value = 4

    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->right = new Node(9);

    cout << "Median of BST = " << sol.findMedian(root) << endl;

    return 0;
}
