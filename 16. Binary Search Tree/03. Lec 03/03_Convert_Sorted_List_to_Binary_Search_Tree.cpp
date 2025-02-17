//leetcode: 109. Convert Sorted List to Binary Search Tree
#include <iostream>
using namespace std;

// Definition for singly-linked list node.
class ListNode {
public:
    int val;
    ListNode* next;
    
    // Constructor to initialize a list node with a given value.
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize a tree node with a given value.
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to return the length of the linked list.
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // Recursive function to construct BST from sorted linked list.
    // 'head' is passed by reference so that it can move along the list.
    TreeNode* solve(ListNode*& head, int n) {
        if(head == NULL || n <= 0) {
            return NULL; // base case
        }
        // Left subtree
        TreeNode* leftSubTree = solve(head, n/2);
        
        // Node: the current head node becomes the root.
        TreeNode* root = new TreeNode(head->val);
        root->left = leftSubTree;
        head = head->next;
        
        // Right subtree: 
        // from the remaining (n - (n/2) - 1) nodes.
        TreeNode* rightSubTree = solve(head, (n - (n/2)) - 1); 
        // n mese n/2 left wale ko de diya aur 1 root node ko de diya,
        // kitna bacha: (n - (n/2)) - 1
        
        root->right = rightSubTree;
        return root;
    }
    
    // Main function to convert sorted linked list to balanced BST.
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        TreeNode* root = solve(head, n);
        return root;
    }
};

// Helper function to print inorder traversal of the BST.
void printInorder(TreeNode* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
       Constructing a sorted linked list:
       1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
       
       Expected Inorder Traversal of the BST (should be sorted):
       1 2 3 4 5 6 7
    */
    
    // Creating the sorted linked list.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    
    // Convert sorted linked list to BST.
    Solution sol;
    TreeNode* bstRoot = sol.sortedListToBST(head);
    
    // Print inorder traversal of the BST.
    cout << "Inorder traversal of the BST: ";
    printInorder(bstRoot);
    cout << endl;
    
    return 0;
}
