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

// More optimal: TC : O(N), SC : O(1) 
class Solution2 {
  public:
    int findMedian(Node* root) {
        Node* curr = root;
        int size = 0;

        // First Morris Traversal to count total nodes in BST
        while(curr) {
            if(curr->left == NULL) {
                size++;
                curr = curr->right;
            } else {
                Node* pred = curr->left;
                while(pred->right != curr && pred->right) {
                    pred = pred->right;
                }
                
                if(pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    size++;
                    curr = curr->right;
                }
            }
        }

        // if(size & 1) {
        //     size = (size+1)/2;
        // } else {
        //     size = size/2;
        // }
        size = ceil((float)size/2);

        // Second Morris Traversal to reach the median node
        curr = root;
        while(curr) {
            if(curr->left == NULL) {
                size--;
                if(size == 0) return curr->data;
                curr = curr->right;
            } else {
                Node* pred = curr->left;
                while(pred->right != curr && pred->right) {
                    pred = pred->right;
                }
                
                if(pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    size--;
                    if(size == 0) return curr->data;
                    curr = curr->right;
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution2 sol;

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
