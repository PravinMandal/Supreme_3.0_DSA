//leetcode: 2181 - Merge Nodes in Between Zeros

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // 'head' always starts with a zero, so we move to the next node
        ListNode* temp = head->next;

        // Dummy node to store the final merged list
        ListNode* anshead = new ListNode(-1);
        ListNode* ansit = anshead; // Iterator for building the new list

        int sum = 0; // Variable to store sum between zeros

        // Traverse the linked list
        while (temp) {
            if (temp->val == 0) {
                // When a zero is found, it means one group is completed
                ansit->next = new ListNode(sum); // Create new node with group sum
                ansit = ansit->next; // Move iterator to new node
                sum = 0; // Reset sum for next group
            } else {
                // Keep adding values until we reach the next zero
                sum += temp->val;
            }
            temp = temp->next; // Move to next node
        }

        // Return the list starting from the node after dummy
        return anshead->next;
    }
};

class Solution2 {
public:
    ListNode* mergeNodes(ListNode* head) {
        // Two pointers: 'slow' marks where we will store the next merged sum
        // 'fast' moves ahead to calculate sums between zeros
        ListNode *slow = head, *fast = head->next, *newlastnode = NULL;

        int sum = 0; // To store the cumulative sum between zeros
        while (fast) {
            if (fast->val != 0) {
                // Add current node’s value to sum until we find a zero
                sum += fast->val;
            } else {
                // Found a zero → current group ends
                newlastnode = slow;    // Mark current as last node of merged list
                slow->val = sum;       // Store the sum in current 'slow' node
                slow = slow->next;     // Move slow pointer to next group
                sum = 0;               // Reset sum for next group
            }
            fast = fast->next; // Move to next node
        }

        // Disconnect the remaining part of the old list
        ListNode* temp = newlastnode->next;
        newlastnode->next = NULL;

        // Free memory of unused nodes to prevent memory leaks
        while (temp) {
            ListNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }

        // Return head of the merged linked list
        return head;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case
    // Linked list: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    Solution2 sol;
    ListNode* result = sol.mergeNodes(head);

    cout << "Merged List: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
