//gfg: Merge two BSTs

#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Node structure required for compilation
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        Node *a = root1, *b = root2;
        stack<Node*> st1, st2;

        // Iterative inorder traversal of both BSTs together
        while(!st1.empty() || !st2.empty() || a || b) {

            // Push left nodes of first BST
            while(a) {
                st1.push(a);
                a = a->left;
            }

            // Push left nodes of second BST
            while(b) {
                st2.push(b);
                b = b->left;
            }

            // Choose the smaller top element from both stacks
            if(st2.empty() || (!st1.empty() && st1.top()->data <= st2.top()->data)) {
                auto atop = st1.top();
                ans.push_back(atop->data);
                st1.pop();
                a = atop->right;
            } else {
                auto btop = st2.top();
                ans.push_back(btop->data);
                st2.pop();
                b = btop->right;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    // BST 1:
    //        3
    //       / \
    //      1   5
    //
    // BST 2:
    //        4
    //       / \
    //      2   6

    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    vector<int> result = sol.merge(root1, root2);

    // Print merged sorted elements
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
