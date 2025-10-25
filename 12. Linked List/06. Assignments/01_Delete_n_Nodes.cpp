//gfg: Delete N nodes after M nodes of a linked list
#include <bits/stdc++.h>
using namespace std;

// Node definition as per the problem
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* temp1 = head;
        Node* temp2 = NULL;

        while(temp1 != NULL) {
            // Skip m nodes
            for(int i=1; i<m && temp1 != NULL; i++) {
                temp1 = temp1->next;
            }

            // If we've reached the end, break
            if(temp1 == NULL) return head;
            temp2 = temp1;

            // Move temp2 ahead n+1 times to delete n nodes
            for(int j=0; j<=n && temp2 != NULL; j++) {
                temp2 = temp2->next;
            }

            // Link the m-th node to the node after the deleted part
            temp1->next = temp2;
            temp1 = temp2;
        }
        return head;
    }
};

// Helper function to print linked list
void printList(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
Node* createList(vector<int> vals) {
    if(vals.empty()) return NULL;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for(int i=1; i<vals.size(); i++) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Testcase 1
    vector<int> vals1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* head1 = createList(vals1);
    cout << "Original List: ";
    printList(head1);
    head1 = sol.linkdelete(head1, 2, 2);  // Delete 2 nodes after every 2 nodes
    cout << "After deleting 2 nodes after every 2 nodes: ";
    printList(head1);

    // Testcase 2
    vector<int> vals2 = {10, 20, 30, 40, 50, 60};
    Node* head2 = createList(vals2);
    cout << "\nOriginal List: ";
    printList(head2);
    head2 = sol.linkdelete(head2, 1, 3);  // Delete 1 node after every 3 nodes
    cout << "After deleting 1 node after every 3 nodes: ";
    printList(head2);

    return 0;
}
