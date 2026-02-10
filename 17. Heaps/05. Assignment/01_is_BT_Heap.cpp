//gfg: Is Binary Tree Heap

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
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool isHeap(Node* tree) {
        queue<Node*> q;
        q.push(tree);

        // Once a NULL child is seen, all following nodes must also be NULL
        bool isNull = false;

        while(!q.empty()) {
            auto front = q.front(); 
            q.pop();

            if(front == NULL) {
                isNull = true;
            } else {
                // If a non-null node appears after a null, tree is not complete
                if(isNull) return false;

                // Heap property: parent must be >= children
                if(front->left && front->left->data > front->data) return false;
                if(front->right && front->right->data > front->data) return false;

                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case 1 (Valid Max Heap)
    //          10
    //         /  \
    //        9    8
    //       / \  /
    //      7  6 5
    Node* root1 = new Node(10);
    root1->left = new Node(9);
    root1->right = new Node(8);
    root1->left->left = new Node(7);
    root1->left->right = new Node(6);
    root1->right->left = new Node(5);

    cout << sol.isHeap(root1) << endl; // Expected: 1

    // Hardcoded test case 2 (Not a Heap)
    //          10
    //         /  \
    //        15   8
    Node* root2 = new Node(10);
    root2->left = new Node(15);
    root2->right = new Node(8);

    cout << sol.isHeap(root2) << endl; // Expected: 0

    return 0;
}
