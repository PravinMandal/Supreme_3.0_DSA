//leetcode:- 83. Remove Duplicates from Sorted List
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //case1 LL is empty
        if(head==NULL){
            return head;
        }
        //case2 LL mai ek node h
        if(head->next==NULL){
            return head;
        }
        //case3 LL mai >1 nodes toh honge hi
        //atleast 2 node toh honge hi
        ListNode* prev=head;
        ListNode* temp=head->next;
        while(temp!=NULL){
            if(prev->val==temp->val){
                //duplicate mil gya
                prev->next=temp->next; //duplicate wala LL se hat gya
                temp->next=NULL; // duplicate isolate ho gya
                delete temp;
            }
            else{
                //duplicate not found
                prev=prev->next;
                temp=temp->next;
            }
            temp=prev->next; //temp=temp->next isiliye nhi kiya kyuki temp delete kr diye h if condition mai
            //toh temp NULL pointer ko access krke error na de isiliye prev ka use kr rhe h
        }
        //yaha tk aane pr saare duplicate remove ho chuke honge
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    cout << "Original list: ";
    printList(node1);

    // Test the solution
    Solution sol;
    ListNode* result = sol.deleteDuplicates(node1);

    cout << "List after removing duplicates: ";
    printList(result);

    // Free memory (manual cleanup)
    while (result != NULL) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
