//leetcode: 160 Intersection of Two Linked Lists

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ListNode structure required for compilation
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int count1 = 0;
        int count2 = 0;

        // Count length of list A
        while(temp1) {
            count1++;
            temp1 = temp1->next;
        }

        // Count length of list B
        while(temp2) {
            count2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        // Ensure temp2 points to longer list
        if(count1 > count2) {
            swap(count1, count2);
            swap(temp1, temp2);
        }
        
        // Move pointer of longer list ahead by length difference
        int sub = count2 - count1;
        while(sub) {
            temp2 = temp2->next;
            sub--;
        }

        // Traverse together to find intersection node
        while(temp1 && temp2) {
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        ListNode* curr = headA;
        while(curr) {
            mp[curr]++;
            curr = curr->next;
        }
        curr = headB;
        while(curr) {
            if(mp.find(curr) != mp.end()) return curr;
            curr = curr->next;
        }
        return NULL;
    }
};

int main() {
    Solution2 sol;

    // Create intersecting linked lists
    // Common part: 8 -> 10
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // List A: 3 -> 7 -> 8 -> 10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    // List B: 99 -> 1 -> 8 -> 10
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if(intersection)
        cout << intersection->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}