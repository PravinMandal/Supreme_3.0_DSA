//gfg: Sort a linked list of 0s, 1s and 2s
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    // Function to count occurrences of 0, 1, and 2 in the linked list.
    void countNumbers(int &countzero, int &countone, int &counttwo, Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == 0) {
                countzero++;
            }
            if (temp->data == 1) {
                countone++;
            }
            if (temp->data == 2) {
                counttwo++;
            }
            temp = temp->next;
        }
        return;
    }

    // Function to create a linked list from a vector.
    Node* createList(vector<int>& arr) {
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for (int i = 1; i < n; i++) {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    // Function to sort a linked list of 0s, 1s, and 2s.
    Node* segregate(Node* head) {
        int countzero = 0, countone = 0, counttwo = 0;
        countNumbers(countzero, countone, counttwo, head);

        vector<int> arr;
        for (int i = 0; i < countzero; i++) {
            arr.push_back(0);
        }
        for (int i = 0; i < countone; i++) {
            arr.push_back(1);
        }
        for (int i = 0; i < counttwo; i++) {
            arr.push_back(2);
        }

        Node* ans = createList(arr);
        return ans;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to free memory of the linked list
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create a linked list: 2 -> 1 -> 2 -> 0 -> 1 -> 0 -> NULL
    Node* node1 = new Node(2);
    Node* node2 = new Node(1);
    Node* node3 = new Node(2);
    Node* node4 = new Node(0);
    Node* node5 = new Node(1);
    Node* node6 = new Node(0);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    cout << "Original Linked List: ";
    printList(node1);

    // Sort the linked list
    Solution sol;
    Node* sortedHead = sol.segregate(node1);

    cout << "Sorted Linked List: ";
    printList(sortedHead);

    // Free memory
    freeList(sortedHead);

    return 0;
}
