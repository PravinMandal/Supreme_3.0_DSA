//leetcode: 328 - Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or has less than 3 nodes, no rearrangement needed
        if (!head) return 0;
        if (head->next == NULL || head->next->next == NULL) return head;

        // Pointers to handle odd and even positioned nodes
        ListNode* odd = head;              // First node (odd position)
        ListNode* even = head->next;       // Second node (even position)
        ListNode* evenstart = head->next;  // To reconnect even list at the end

        // Loop until we reach the end of the list
        while (odd->next && even->next) {
            // Link current odd node to next odd node (skipping an even)
            odd->next = even->next;
            odd = even->next; // Move odd pointer to next odd node

            // Link current even node to next even node (skipping an odd)
            even->next = odd->next;
            even = odd->next; // Move even pointer to next even node
        }

        // Connect the end of the odd list to the start of even list
        odd->next = evenstart;

        // Return modified list starting from head
        return head;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* result = sol.oddEvenList(head);

    cout << "Reordered List (Odd-Even): ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
