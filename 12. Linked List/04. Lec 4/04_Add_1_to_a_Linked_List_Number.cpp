//gfg: Add 1 to a Linked List Number
#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
  public:
    Node* reverse(Node* &head){
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr!=NULL){
            Node* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        //step 1: LL ko reverse krnge
        head=reverse(head);
        //step 2: 1 ko add krenge
        
        //hume 1 add krna h isiliye carry one le liye
        int carry=1;
        Node* temp=head;
        
        while(temp!=NULL){
            int sum=carry+temp->data;
            int digit=sum%10;
            carry=sum/10;
            
            temp->data=digit;
            
            //special case
            if(temp->next == NULL && carry!=0){
                Node* newnode=new Node(carry);
                temp->next=newnode;
                temp=newnode;
            }
            
            temp=temp->next;
        }
        
        
        
        //step 3: LL ko wapas reverse krke pehle jaisa kr denge
        head=reverse(head);
        return head;
    }
};

// Helper function to create a linked list from a number
Node* createLinkedList(int number) {
    Node* head = NULL;
    Node* temp = NULL;

    // Extract digits from the number and create nodes
    while (number > 0) {
        Node* newNode = new Node(number % 10);
        number /= 10;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Reverse the list to ensure proper order
    Solution sol;
    return sol.reverse(head);
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to free memory of the linked list
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Input number represented by linked list
    int number = 129; // Example: number = 129 (linked list: 1 -> 2 -> 9)
    Node* head = createLinkedList(number);

    cout << "Original Number: ";
    printList(head);

    // Add 1 to the number represented by the linked list
    Solution sol;
    head = sol.addOne(head);

    cout << "After Adding 1: ";
    printList(head);

    // Free memory
    freeList(head);


    //iske baad "add 2 numbers represented in linked list" ye question kro , very imp , same approach 

    return 0;
}
