//gfg: Rotate a Linked List
#include <iostream>
using namespace std;

/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

// Definition of Node
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
    // Function to get the length of the linked list
    int getLen(Node* head) {
        Node* temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to rotate the linked list by k nodes
    Node* rotate(Node* head, int k) {
        if(!head) return NULL; // Empty list case

        // Step 1: Get the length of the linked list
        int len = getLen(head);

        // Step 2: Reduce k to an effective rotation count
        int actualRotateK = k % len;
        if(actualRotateK == 0) return head; // No rotation needed

        // Step 3: Connect the last node to the head to form a circular linked list
        Node* it = head;
        while(it->next) {
            it = it->next;
        }
        it->next = head; // make circular link

        // Step 4: Find the new last node (after rotation)
        int newlastpos = actualRotateK - 1;
        Node* lastNode = head;
        for(int i = 0; i < newlastpos; i++) {
            lastNode = lastNode->next;
        }

        // Step 5: The node next to lastNode becomes the new head
        Node* newhead = lastNode->next;
        lastNode->next = NULL; // break the circular link

        // Step 6: Return the new head of the rotated list
        return newhead;
    }
};

// Utility function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function for testing
int main() {
    // Creating a linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node* n5 = new Node(50);
    Node* n4 = new Node(40); n4->next = n5;
    Node* n3 = new Node(30); n3->next = n4;
    Node* n2 = new Node(20); n2->next = n3;
    Node* n1 = new Node(10); n1->next = n2;

    cout << "Original List: ";
    printList(n1);

    int k = 2; // Rotate by 2 positions
    Solution obj;
    Node* rotated = obj.rotate(n1, k);

    cout << "Rotated List by " << k << ": ";
    printList(rotated);

    return 0;
}
