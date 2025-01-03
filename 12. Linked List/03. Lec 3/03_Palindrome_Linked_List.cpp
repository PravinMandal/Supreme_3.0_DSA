//leetcode:- 234. Palindrome Linked List
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
    ListNode* getMiddle(ListNode* &head, ListNode* &middleNodekaprev){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                middleNodekaprev=slow;
                slow=slow->next;
            }
        }
        return slow;
    }

    ListNode* reverse(ListNode* prev,ListNode* curr){
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            //LL is empty
            return true;
        }
        if(head->next==NULL){
            //single node hai 
            return true;
        }
        //middle nikal ke LL ko break krna h 2 halves mai middle se
        ListNode* firstHalfHead=head;
        ListNode* middleNodekaprev=NULL;
        ListNode* middleNode=getMiddle(head,middleNodekaprev);
        //break
        middleNodekaprev->next=NULL;

        //reverse the second half
        ListNode* prev=NULL;
        ListNode* curr=middleNode;
        ListNode* secondHalfHead=reverse(prev,curr);

        //compare both the halves and decide T/F
        // even length wale case mai dono part ki length equal hogi
        //odd wale case mai second half ki ki length badi hogi by 1
        //that's why mai humesha compare first half ki length ke hisaab se krunga
        ListNode* temphead1=firstHalfHead;
        ListNode* temphead2=secondHalfHead;
        while(temphead1 != NULL){
            if(temphead1->val != temphead2->val){
                //same nhi h mtlb not palindrome
                return false;
            }
            else{
                temphead1=temphead1->next;
                temphead2=temphead2->next;
            }
        }
        //yaha tak pohoch gya mtlb saare compare ho gye and return false bhi nhi hua
        //mtlb palindrome hai
        return true;

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
    // Input array for testing
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    ListNode* head = createList(arr, n);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Check if the linked list is a palindrome
    Solution solution;
    bool result = solution.isPalindrome(head);

    // Output the result
    if (result) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
