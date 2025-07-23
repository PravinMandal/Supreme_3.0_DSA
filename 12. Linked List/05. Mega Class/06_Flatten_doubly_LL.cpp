//leetcode: 430. Flatten a Multilevel Doubly Linked List
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* solve(Node* head) {
        Node* it = head;
        Node* tail = it;

        while(it) {
            if(it->child) {
                Node* childptr = solve(it->child);
                Node* nextptr = it->next;
                it->next = it->child;
                it->next->prev = it;
                childptr->next = nextptr;
                if(nextptr) {
                    nextptr->prev = childptr;
                }
                it->child = nullptr;
            }
            tail = it;
            it = it->next;
        }
        return tail;
    }

    Node* flatten(Node* head) {
        if(!head) return nullptr;
        solve(head);
        return head;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Structure:
        1 - 2 - 3 - 4
              |
              7 - 8
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    // Connect main level
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    // Connect child
    n3->child = n7;
    n7->next = n8;
    n8->prev = n7;

    Solution sol;
    Node* flatHead = sol.flatten(n1);

    printList(flatHead);  // Output should be: 1 2 3 7 8 4

    return 0;
}
