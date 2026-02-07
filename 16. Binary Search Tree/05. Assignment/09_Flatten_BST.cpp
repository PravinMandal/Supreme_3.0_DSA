//gfg: Flatten BST to sorted linked list

#include <bits/stdc++.h>
using namespace std;

// Node structure required for compilation
class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int data) {
        this->data = data;
    }
};

class Solution {
  public:
    void getinorder(vector<Node*>& inorder, Node* root) {
        if(!root) return;
        getinorder(inorder, root->left);
        inorder.push_back(root);
        getinorder(inorder, root->right);
    }

    Node *flattenBST(Node *root) {
        vector<Node*> inorder;

        // Store nodes in inorder (sorted order for BST)
        getinorder(inorder, root);

        // Rearrange pointers to form a right-skewed linked list
        for(int i = 0; i < inorder.size(); i++) {
            inorder[i]->left = NULL;
            if(i + 1 < inorder.size())
                inorder[i]->right = inorder[i + 1];
            else
                inorder[i]->right = NULL;
        }

        // Head of the linked list
        return inorder[0];
    }
};

class Solution2 {
  public:
    void inorder(Node* root, Node*& prev) {
        if(!root) return;

        // Inorder traversal to process nodes in sorted order
        inorder(root->left, prev);

        // Link previous node to current node
        prev->right = root;
        prev = root;

        // Ensure left pointer is NULL in the flattened list
        prev->left = NULL;

        inorder(root->right, prev);
    }

    Node *flattenBST(Node *root) {
        // Dummy node to simplify linking logic
        Node* dummy = new Node(-1);
        Node* prev = dummy;

        inorder(root, prev);

        // Head of the flattened linked list
        return dummy->right;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded BST
    //          5
    //         / \
    //        3   7
    //       / \   \
    //      2   4   8

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(8);

    Node* head = sol.flattenBST(root);

    // Print flattened BST (sorted linked list using right pointers)
    Node* curr = head;
    while(curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}
