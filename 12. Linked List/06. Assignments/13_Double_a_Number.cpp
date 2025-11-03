//leetcode: 2816 - Double a Number Represented as a Linked List

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
    // Recursive helper function to process digits from the end (like we do in multiplication)
    void solve(ListNode* temp, int& carry) {
        if (!temp) return;

        // Recursively move to the last node
        solve(temp->next, carry);

        // Double the node's value and add carry
        temp->val = (temp->val * 2) + carry;

        // Calculate new carry and update current node value
        carry = temp->val / 10;
        temp->val = temp->val % 10;
    }

    // Main function to double the linked list number
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        ListNode* temp = head;

        // Perform doubling operation recursively
        solve(temp, carry);

        // If there's a leftover carry, insert a new node at the beginning
        if (carry) {
            ListNode* firstnode = new ListNode(carry);
            firstnode->next = head;
            head = firstnode;
        }

        return head;
    }
};

int main() {
    // Hardcoded test case: Linked list represents number 495
    // So doubling should result in 990
    ListNode* head = new ListNode(4);
    head->next = new ListNode(9);
    head->next->next = new ListNode(5);

    Solution sol;
    ListNode* result = sol.doubleIt(head);

    cout << "Doubled Number: ";
    while (result) {
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}
