//leetcode: 160. Intersection of Two Linked Lists
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
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

        // Count the number of nodes in the first linked list
        while(temp1) {
            count1++;
            temp1 = temp1->next;
        }

        // Count the number of nodes in the second linked list
        while(temp2) {
            count2++;
            temp2 = temp2->next;
        }

        // Reset both pointers to the start of each list
        temp1 = headA;
        temp2 = headB;

        // Make sure temp2 points to the longer list
        if(count1 > count2) {
            swap(count1, count2);
            swap(temp1, temp2);
        }
        
        // Move pointer of the longer list ahead by the difference in lengths
        int sub = count2 - count1;
        while(sub) {
            temp2 = temp2->next;
            sub--;
        }

        // Traverse both lists together until intersection is found
        while(temp1 && temp2) {
            if(temp1 == temp2){ // intersection node found
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // No intersection found
        return NULL;
    }
};

int main() {
    // Creating sample linked lists for testing:
    // List A: 1 -> 2 -> 3 \
    //                       6 -> 7
    // List B:       4 -> 5 /

    // Common intersection part
    ListNode* common = new ListNode(6);
    common->next = new ListNode(7);

    // First linked list
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common; // intersection starts here

    // Second linked list
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common; // intersection starts here

    Solution obj;
    ListNode* intersection = obj.getIntersectionNode(headA, headB);

    if(intersection)
        cout << "Intersection Node value: " << intersection->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}
