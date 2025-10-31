//gfg: Flattening a Linked List
#include <iostream>
using namespace std;

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

// Definition for Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public:
    // Function to merge two sorted linked lists (using bottom pointers)
    Node* merge(Node* a, Node* b) {
        // Base cases: if one list is empty, return the other
        if(!a) return b;
        if(!b) return a;
        
        Node* ans = NULL;
        
        // Compare data of both nodes and recursively merge
        if(a->data < b->data) {
            ans = a;
            ans->bottom = merge(a->bottom, b); // merge remaining of 'a' and 'b'
        } else {
            ans = b;
            ans->bottom = merge(a, b->bottom); // merge remaining of 'b' and 'a'
        }

        ans->next = NULL; // Ensure 'next' pointer is set to NULL
        return ans;
    }

    // Function to flatten the multilevel linked list
    Node *flatten(Node *root) {
        // Base case: if root is null, return null
        if(!root) return 0;
        
        // Recursively flatten the list to the right (next)
        Node* mergeLL = merge(root, flatten(root->next));
        return mergeLL;
    }
};

int main() {
    // Creating a test case manually:
    // Linked list looks like:
    // 5 -> 10 -> 19 -> 28
    // |     |     |     |
    // 7     20    22    35
    // |           |     |
    // 8           50    40
    // |                 |
    // 30                45

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution obj;
    Node* flat = obj.flatten(head);

    cout << "Flattened list: ";
    while(flat) {
        cout << flat->data << " ";
        flat = flat->bottom;
    }
    cout << endl;

    return 0;
}
