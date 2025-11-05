//leetcode: 1721 - Swapping Nodes in a Linked List

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
    // Recursive helper function to reach kth node from end
    void swap2(ListNode* it, ListNode* temp, int& k) {
        if(!it) return; // Base condition — reached end of list
        
        // Recursive call to reach the last node
        swap2(it->next, temp, k);
        
        // As recursion unwinds, decrease k to count back from the end
        k--;
        
        // When k becomes 0, we've reached kth node from end — swap values
        if(k == 0) {
            int num = it->val;
            it->val = temp->val;
            temp->val = num;
            return;
        }
    }

    // Function to swap kth node from start and kth node from end
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;

        // Step 1: Move 'temp' pointer to kth node from start
        for(int i = 0; i < k - 1; i++) {
            temp = temp->next;
        }

        // Step 2: Use recursion to find kth node from end and swap
        ListNode* it = head;
        swap2(it, temp, k);

        // Step 3: Return the updated list
        return head;
    }
};

class Solution2 {
public:
    int getLength(ListNode* it) {
        int len = 0;
        while(it) {
            len++;
            it = it->next;
        }
        return len;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* it = head;
        int len = getLength(it);
        it = head;
        int i = 1;
        while(it) {
            if(i == k) {
                first = it;
            }
            if(i == len-k+1) {
                second = it;
            }
            i++;
            it = it->next;
        }
        swap(first->val, second->val);
        return head;
    }
};

class Solution3 {
public:
    // Recursive function to calculate the length of the linked list
    int Len(ListNode* head) {
        if (!head) return 0;
        return 1 + Len(head->next);
    }

    ListNode* swapNodes(ListNode* head, int k) {
        // Case 1: Empty list or single node
        if (!head || !head->next) return head;

        int len = Len(head);          // Find the total length of the list
        int lpos = k;                 // kth node from start
        int rpos = len - k + 1;       // kth node from end

        // Swap to ensure lpos < rpos for simpler logic
        if (rpos < lpos) swap(rpos, lpos);

        // Case 2: If both positions are the same, nothing to swap
        if (lpos == rpos) return head;

        // Case 3: If the list only has two nodes, simply reverse them
        if (len == 2) {
            ListNode* nextNode = head->next;
            nextNode->next = head;
            head->next = NULL;
            head = nextNode;
            return head;
        }

        // Case 4: If swapping involves the head (first node)
        if (lpos == 1) {
            ListNode* lp = nullptr;
            ListNode* ln = head; // left node (first)
            ListNode* rp = head;

            // Move rp to the node before right node
            for (int i = 0; i < len - 2; i++) {
                rp = rp->next;
            }

            ListNode* rn = rp->next;  // right node
            ListNode* rsave = rn->next; // node after rn

            // Perform swapping
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;

            head = rn; // new head
            return head;
        }

        // Case 5: If both nodes are adjacent
        int numberofNodesBtwSwapNodes = rpos - lpos - 1;
        if (numberofNodesBtwSwapNodes == 0) {
            ListNode* lp = head;
            for (int i = 0; i < lpos - 2; i++) lp = lp->next;
            ListNode* ln = lp->next;

            ListNode* rp = head;
            for (int i = 0; i < rpos - 2; i++) rp = rp->next;
            ListNode* rn = rp->next;
            ListNode* rsave = rn->next;

            // Perform adjacent swap
            lp->next = rp->next;
            rn->next = rp;
            rp->next = rsave;

            return head;
        }
        else {
            // Case 6: Nodes are not adjacent
            ListNode* lp = head;
            for (int i = 0; i < lpos - 2; i++) lp = lp->next;
            ListNode* ln = lp->next;

            ListNode* rp = head;
            for (int i = 0; i < rpos - 2; i++) rp = rp->next;
            ListNode* rn = rp->next;
            ListNode* rsave = rn->next;

            // Perform swapping between non-adjacent nodes
            lp->next = rn;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;

            return head;
        }
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // k = 2
    // After swapping: 1 -> 4 -> 3 -> 2 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution3 sol;
    ListNode* result = sol.swapNodes(head, k);

    cout << "List after swapping " << k << "th node from start and end: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
