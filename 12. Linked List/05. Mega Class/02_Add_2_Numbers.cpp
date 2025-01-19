#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    ListNode* iterative(ListNode* l1, ListNode* l2){
        ListNode* ans=new ListNode(-1);
        ListNode* it=ans;
        int carry = 0;
        while(l1 || l2 || carry){
            int a=l1 ? l1->val:0; //check kr rhe h ki l1 bacha h ki nhi agar nhi toh 0 consider krenge
            int b=l2 ? l2->val:0; //check kr rhe h ki l2 bacha h ki nhi agar nhi toh 0 store krenge b mai
            int sum=a + b + carry;
            int digit=sum%10;
            carry=sum/10;
            it->next=new ListNode(digit);
            it=it->next;
            l1=l1 ? l1->next:nullptr;
            l2=l2 ? l2->next:nullptr;
        }
        ListNode* finalans=ans->next; //kyuki starting mai -1 store krke rakhe h jo nhi chahiye;
        delete ans;
        return finalans;
    }

    ListNode* recursive(ListNode* l1, ListNode* l2, int carry=0){
        if(!l1 && !l2 && !carry) return 0;

        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a + b + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode* ans=new ListNode(digit);
        ans->next = recursive(l1 ? l1->next : l1 , l2 ? l2->next : l2, carry);
        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return iterative(l1,l2);
        return recursive(l1, l2);
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input linked lists represented as arrays
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4, 6, 3, 7};

    // Create linked lists from arrays
    ListNode* l1 = createLinkedList(arr1, 3);
    ListNode* l2 = createLinkedList(arr2, 6);

    // Solve the problem
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    printLinkedList(result);

    return 0;
}
