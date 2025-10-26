//leetcode: 21. Merge Two Sorted Lists
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        // Ensure list1 always starts with the smaller node
        if(list1->val > list2->val) {
            swap(list1, list2);
        }

        ListNode* head = list1;

        // Merge process
        while(list1 && list2) {
            ListNode* temp = NULL;

            // Move list1 until the next node is greater than list2’s current value
            while(list1->next && list1->next->val <= list2->val) {
                list1 = list1->next;
            }

            // Swap links to merge correctly
            temp = list1->next;
            list1->next = list2;
            list1 = list2;
            list2 = temp;
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 && temp2) {
            if(temp1->val <= temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            }
            else {
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }
        if(temp1) {
            tail->next = temp1;
        }
        else {
            tail->next = temp2;
        }
        return head->next;
    }
};

// Helper function to create linked list from vector
ListNode* createList(vector<int> vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for(int i=1; i<vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution2 sol;

    // Example 1
    vector<int> list1Vals = {1, 2, 4};
    vector<int> list2Vals = {1, 3, 4};

    ListNode* list1 = createList(list1Vals);
    ListNode* list2 = createList(list2Vals);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    ListNode* merged = sol.mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printList(merged);

    // Example 2
    vector<int> list3Vals = {5, 10, 15};
    vector<int> list4Vals = {2, 3, 20};

    ListNode* list3 = createList(list3Vals);
    ListNode* list4 = createList(list4Vals);

    cout << "\nList 3: ";
    printList(list3);
    cout << "List 4: ";
    printList(list4);

    ListNode* merged2 = sol.mergeTwoLists(list3, list4);
    cout << "Merged List 2: ";
    printList(merged2);

    return 0;
}
