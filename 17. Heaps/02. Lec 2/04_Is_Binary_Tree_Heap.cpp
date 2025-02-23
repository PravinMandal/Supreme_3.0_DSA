//gfg: Is Binary Tree Heap
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Definition for a binary tree node using class.
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize a node with a given value.
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool checkCompleteness(Node* root) {
        queue<Node*> q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            if(front == NULL) {
                nullFound = true;
            }
            else {
                if(nullFound == true) {
                    return false;
                }
                else {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
    
    bool checkMaxProperty(Node* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        
        bool leftAns = checkMaxProperty(root->left);
        bool rightAns = checkMaxProperty(root->right);
        
        bool option1 = true;
        if(root->left && root->data < root->left->data) {
            option1 = false;
        }
        
        bool option2 = true;
        if(root->right && root->data < root->right->data) {
            option2 = false;
        }
        
        bool currAns = option1 && option2;
        
        return currAns;
    }
    
    bool isHeap(Node* tree) {
        bool completeness = checkCompleteness(tree);
        bool MaxProperty =  checkMaxProperty(tree);
        
        if(completeness && MaxProperty) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Valid Max-Heap
    /*
            Constructing the following binary tree:
            
                    10
                   /  \
                  9    8
                 / \   / 
                7   6 5  
            
            This tree is complete and satisfies the max-heap property:
            - 10 >= 9, 10 >= 8;
            - 9 >= 7, 9 >= 6;
            - 8 >= 5.
            
            Expected Output: isHeap returns true.
    */
    Node* heapRoot = new Node(10);
    heapRoot->left = new Node(9);
    heapRoot->right = new Node(8);
    heapRoot->left->left = new Node(7);
    heapRoot->left->right = new Node(6);
    heapRoot->right->left = new Node(5);
    
    bool isHeap1 = sol.isHeap(heapRoot);
    cout << "Test Case 1 - The tree is " << (isHeap1 ? "a valid heap." : "not a valid heap.") << endl;
    
    // Test Case 2: Not a Heap (Violates Completeness or Max Property)
    /*
            Constructing the following binary tree:
            
                    10
                   /  
                  12   
                 / \
                7   8
            
            In this tree, even though it is complete,
            the max-heap property is violated because 12 > 10.
            
            Expected Output: isHeap returns false.
    */
    Node* nonHeapRoot = new Node(10);
    nonHeapRoot->left = new Node(12);
    nonHeapRoot->right = new Node(8); // Including right child to keep it complete.
    nonHeapRoot->left->left = new Node(7);
    nonHeapRoot->left->right = new Node(8);
    
    bool isHeap2 = sol.isHeap(nonHeapRoot);
    cout << "Test Case 2 - The tree is " << (isHeap2 ? "a valid heap." : "not a valid heap.") << endl;
    
    return 0;
}
