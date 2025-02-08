//gfg: Tree Boundary Traversal
#include <iostream>
#include <vector>
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
    void leftBoundary(Node* root, vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        ans.push_back(root->data);
        if(root->left != NULL){
            leftBoundary(root->left, ans);
        }
        else{
            leftBoundary(root->right, ans);
        }
    }
    
    void leafBoundary(Node* root, vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
    }
    
    void rightBoundary(Node* root, vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        if(root->right != NULL){
            rightBoundary(root->right, ans);
        }
        else{
            rightBoundary(root->left, ans);
        }
        //mujhe reverse order mai store krna h right boundary ko isiliye
        //ab ans mai push_back krunga
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        //A -> Root Node
        ans.push_back(root->data);
        //B -> left subtree -> left boundary
        leftBoundary(root->left, ans);
        //C -> left subtree -> left leafnode
        leafBoundary(root->left, ans);
        //D -> right subtree -> right leafnode
        leafBoundary(root->right, ans);
        //E -> right subtree -> right boundary
        rightBoundary(root->right, ans);
        
        return ans;
    }
};

int main() {
    // Constructing the following binary tree:
    /*
                1
               / \
              2   3
             / \    \
            4   5    6
               / \
              7   8
              
       Boundary Traversal should produce:
       - Root: 1
       - Left Boundary (excluding leaf): 2
       - Left Leaf Nodes: 4, 7, 8
       - Right Leaf Nodes: 6
       - Right Boundary (in reverse order): 3
       
       Final Boundary Traversal: 1, 2, 4, 7, 8, 6, 3
    */
    
    // Creating the tree nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    
    // Create an object of Solution and perform boundary traversal
    Solution sol;
    vector<int> boundary = sol.boundaryTraversal(root);
    
    // Output the boundary traversal
    cout << "Boundary Traversal: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
