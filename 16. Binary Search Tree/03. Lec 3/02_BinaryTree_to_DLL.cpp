//gfg: Binary Tree to DLL
#include <iostream>
using namespace std;

// Definition for a binary tree node using class
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize a node with a given value
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void solve(Node* root, Node*& head, Node*& tail) {
        if(root == NULL) {
            return;
        }
        //LNR-> inorder
        //L
        solve(root->left, head, tail);
        //N
        //assume krke chal rha hu ki left mai LL bann gya hoga
        //root no ke left ko LL se connect krna hoga
        //head and tail ko update krna hoga
        if(tail != NULL) {
            //ab tak ki LL empty nhi h
            tail->right = root;
            root->left = tail;
            //tail update
            tail = root;
        }
        else {
            head = root;
            tail = root;
        }
        //R
        solve(root->right, head, tail);
    }
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        Node* tail = NULL;
        solve(root, head, tail);
        return head;
    }
};

int main() {
    /*
       Constructing the following binary tree:
       
               10
              /  \
             5    20
            / \   / \
           3   7 15  25
       
       The DLL (inorder) should be:
       3 <-> 5 <-> 7 <-> 10 <-> 15 <-> 20 <-> 25
    */
    
    // Creating the binary tree nodes
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    
    // Convert Binary Tree to Doubly Linked List (DLL)
    Solution sol;
    Node* head = sol.bToDLL(root);
    
    // Print the DLL from left to right
    cout << "Doubly Linked List (inorder): ";
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
    
    return 0;
}
