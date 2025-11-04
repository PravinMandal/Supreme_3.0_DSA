//leetcode: 148 - Sort List

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to find the middle of the linked list using slow and fast pointers
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Move 'fast' by two and 'slow' by one
        // When 'fast' reaches end, 'slow' will be at the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        // Create dummy node to simplify merging logic
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // Merge nodes in sorted order
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            } else {
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes (if any)
        if (temp1) tail->next = temp1;
        if (temp2) tail->next = temp2;

        // Return merged list (skipping dummy node)
        return head->next;
    }

    // Merge Sort for Linked List
    ListNode* sortList(ListNode* head) {
        // Base case: if list has 0 or 1 node, it’s already sorted
        if (head == NULL || head->next == NULL) return head;

        // Step 1: Split the list into two halves
        ListNode* mid = middle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL; // break the list

        // Step 2: Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Step 3: Merge sorted halves
        ListNode* mergedLL = merge(left, right);
        return mergedLL;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case:
    // Linked list: 4 -> 2 -> 1 -> 3
    // Sorted list should be: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* result = sol.sortList(head);

    cout << "Sorted Linked List: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
