//leetcode:- 206. Reverse Linked List
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* prev, ListNode* curr){
        //base case
        if(curr==NULL){
            //curr NULL pr hai mtlb last tk pohoch gye and LL reverse ho gya h
            //ab prev last wale ko point kr rha h
            return prev;
        }

        ListNode* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        return reverseList(prev,curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;

        ListNode* newnode=reverseList(prev,curr);
        return newnode; //ye jo new head mila usse return kr rha h
    }

    ListNode* reverseListIterative(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Input array
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    ListNode* head = createList(arr, n);

    // // Print the original list
    // cout << "Original List: ";
    // printList(head);

    // // Reverse the list
    // Solution solution;
    // ListNode* reversedHead = solution.reverseList(head);

    // // Print the reversed list
    // cout << "Reversed List: ";
    // printList(reversedHead);



     // Print the original list
    cout << "Original List: ";
    printList(head);

    // Reverse the list
    Solution solution;
    ListNode* reversedHead2 = solution.reverseListIterative(head);

    // Print the reversed list
    cout << "Reversed List: ";
    printList(reversedHead2);

    return 0;
}
