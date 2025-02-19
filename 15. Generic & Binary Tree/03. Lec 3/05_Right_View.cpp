//gfg: right view of binary tree
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
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, int level, vector<int>& ans){
        if(root == NULL) return;
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        solve(root->right, level+1, ans);
        solve(root->left, level+1, ans);
    }
    
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       int level = 0;
       solve(root, level, ans);
       return ans;
    }
};

int main() {
    // Constructing the following binary tree:
    /*
                1
               / \
              2   3
             /   / \
            4   5   6
                 \
                  7
       
       Expected Right View: 1, 3, 6, 7
       Explanation:
       - Level 0: 1
       - Level 1: rightmost node is 3
       - Level 2: rightmost node is 6
       - Level 3: rightmost node is 7
    */
    
    // Creating nodes of the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);
    
    // Create an object of Solution and get the right view of the tree
    Solution sol;
    vector<int> right_view = sol.rightView(root);
    
    // Output the right view
    cout << "Right View of the Tree: ";
    for (int val : right_view) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
