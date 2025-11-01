//leetcode: 61. Rotate List
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Helper function to calculate the length of the linked list
    int getLen(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to rotate the list to the right by k positions
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL; // If list is empty, return NULL

        // Step 1: Find the length of the list
        int len = getLen(head);

        // Step 2: Optimize k by taking modulo with length
        int actualRotateK = k % len;
        if(actualRotateK == 0) return head; // No rotation needed

        // Step 3: Find the new last node (just before rotation point)
        ListNode* lastNode = head;
        int newlastposition = len - actualRotateK - 1;
        for(int i=0; i<newlastposition; i++) {
            lastNode = lastNode->next;
        }

        // Step 4: Set the new start node (the node after the new last)
        ListNode* newstartnode = lastNode->next;
        lastNode->next = NULL; // Break the link

        // Step 5: Traverse to the end of the rotated part
        ListNode* it = newstartnode;
        while(it->next) {
            it = it->next;
        }

        // Step 6: Connect the end of rotated part to the old head
        it->next = head;

        // Step 7: Return the new head
        return newstartnode;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function for testing
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    cout << "Original List: ";
    printList(n1);

    int k = 2; // Number of rotations
    Solution obj;
    ListNode* rotated = obj.rotateRight(n1, k);

    cout << "Rotated List by " << k << ": ";
    printList(rotated);

    return 0;
}
