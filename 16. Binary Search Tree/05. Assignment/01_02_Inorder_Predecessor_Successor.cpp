//gfg: Predecessor and Successor in BST

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
    void solve(Node* root, int key, vector<Node*>& a) {
        if(!root) return;

        // If current node value is smaller than key, it can be a predecessor candidate
        if(root->data < key) {
            a[0] == NULL ? a[0] = root : (a[0]->data) < root->data ? a[0]=root : a[0] = a[0];
        }

        // If current node value is greater than key, it can be a successor candidate
        else if(root->data > key){
            a[1] == NULL ? a[1] = root : (a[1]->data) > root->data ? a[1]=root : a[1] = a[1];
        }

        // Continue searching in left and right subtrees
        solve(root->left, key, a);
        solve(root->right, key, a);
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans = {NULL, NULL};
        solve(root, key, ans);
        return ans;
    }
};

class Solution2 {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
       Node* pred = NULL, *succ = NULL;
       Node* curr = root;

       // Traverse BST to find key while updating pred and succ
       while(curr) {
           if(curr->data == key) break;

           if(curr->data < key) {
               // Current node can be predecessor
               pred = curr;
               curr = curr->right;
           } else {
               // Current node can be successor
               succ = curr;
               curr = curr->left;
           }
       }

       // If key node is found, find exact predecessor and successor inside subtrees
       if(curr) {

           // Predecessor = rightmost node in left subtree
           Node* lscan = curr->left;
           while(lscan) {
                pred = lscan;
                lscan = lscan->right;
           }

           // Successor = leftmost node in right subtree
           Node* rscan = curr->right;
           while(rscan) {
                succ = rscan;
                rscan = rscan->left;
           }
       }

       return {pred, succ};
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case (BST)
    //          50
    //         /  \
    //       30    70
    //      / \    / \
    //     20 40  60  80

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 65;

    vector<Node*> result = sol.findPreSuc(root, key);

    cout << "Key = " << key << endl;

    if(result[0])
        cout << "Predecessor = " << result[0]->data << endl;
    else
        cout << "Predecessor = NULL" << endl;

    if(result[1])
        cout << "Successor = " << result[1]->data << endl;
    else
        cout << "Successor = NULL" << endl;

    return 0;
}
