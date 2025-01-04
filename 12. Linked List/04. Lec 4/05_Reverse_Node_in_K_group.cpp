//leetcode: 25. Reverse Nodes in k-Group
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
    int getlength(ListNode* head){
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //ek bhi Node nhi h, empty LL
        if(head==NULL){
            return head;
        }
        //LL mai ek hi node hai
        if(head->next==NULL){
            return head;
        }

        //LL mai ek se zyada node hai
        int len=getlength(head);
        if(len<k){
            //jab recursion use krenge toh LL cut kr jayega
            //toh baad mai last mai jab len kam hoga K se tb usse reverse nhi krna h and return ho jayega
            return head;
        }

        ListNode* prev=NULL;
        ListNode* curr=head;
        int position=0;
        while(position<k){ //isse hum sirk K node ke group mai reverse kr payenge
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            position++;
        }
        if(curr!=NULL){
            ListNode* recursionkahead=reverseKGroup(curr,k); //curr hai wo as a head jayega
            head->next=recursionkahead;
            //dry run kro tb pta chalega
            //jo head hoga humara ekdum starting ka , reverse krne ke baad wo tail ke position pr hona chahiye
            //toh usse hi hum recrusion ne head diya h usse head diya h usse connect kr denge
            //isse jo result hum chahte h wo mil jayega just dry run smjh jayega
        }
        return prev;
        //prev ko dekho dry run krke stating mai wo humara new head banega
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example linked list
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse in groups of k
    int k = 2;
    Solution solution;
    ListNode* newHead = solution.reverseKGroup(head, k);

    cout << "Reversed Linked List in groups of " << k << ": ";
    printList(newHead);

    return 0;
}
