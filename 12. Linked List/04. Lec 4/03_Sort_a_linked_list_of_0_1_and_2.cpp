//gfg: Sort a linked list of 0s, 1s and 2s
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    // Function to count occurrences of 0, 1, and 2 in the linked list.
    void countNumbers(int &countzero, int &countone, int &counttwo, Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == 0) {
                countzero++;
            }
            if (temp->data == 1) {
                countone++;
            }
            if (temp->data == 2) {
                counttwo++;
            }
            temp = temp->next;
        }
        return;
    }

    // Function to create a linked list from a vector.
    Node* createList(vector<int>& arr) {
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for (int i = 1; i < n; i++) {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    // Function to sort a linked list of 0s, 1s, and 2s.
    Node* segregate(Node* head) {
        int countzero = 0, countone = 0, counttwo = 0;
        countNumbers(countzero, countone, counttwo, head);

        vector<int> arr;
        for (int i = 0; i < countzero; i++) {
            arr.push_back(0);
        }
        for (int i = 0; i < countone; i++) {
            arr.push_back(1);
        }
        for (int i = 0; i < counttwo; i++) {
            arr.push_back(2);
        }

        Node* ans = createList(arr);
        return ans;
    }
};

//ye zyada easy hai and extra space bhi nhi le rha just overwrite kr rhe h but interviewer mana kr skta h
class Solution2 {
public:
    // Function to sort a linked list of 0s, 1s, and 2s.
    Node* segregate(Node* head) {
        // Step 1: Count occurrences of 0, 1, and 2
        int countzero = 0, countone = 0, counttwo = 0;
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == 0) countzero++;
            else if (temp->data == 1) countone++;
            else if (temp->data == 2) counttwo++;
            temp = temp->next;
        }

        // Step 2: Overwrite values in the original linked list
        temp = head;
        while (temp != NULL) {
            if (countzero > 0) {
                temp->data = 0;
                countzero--;
            } else if (countone > 0) {
                temp->data = 1;
                countone--;
            } else if (counttwo > 0) {
                temp->data = 2;
                counttwo--;
            }
            temp = temp->next;
        }

        return head;
    }
};

//ye bhi o(n) time le rha h but const space le rha h o(1) and ye wala interviewer allow krega
class Solution3 {
  public:
    void insertAtTail(Node* &toMove, Node* &head, Node* &tail){
        //2 case h 
        //agar LL khali rha joki starting mai hoga hi
        if(head==NULL && tail==NULL){
            head=toMove;
            tail=toMove;
        }
        else{
            tail->next=toMove;
            tail=toMove;
        }
    }
    
    void print(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        Node* zeroHead=NULL;
        Node* zeroTail=NULL;
        
        Node* oneHead=NULL;
        Node* oneTail=NULL;
        
        Node* twoHead=NULL;
        Node* twoTail=NULL;
        
        Node* temp=head;
        
        while(temp!=NULL){
            
            Node* toMove=temp;
            temp=temp->next;
            toMove->next=NULL;
            
            if(toMove->data==0){
                insertAtTail(toMove,zeroHead,zeroTail);
            }
            else if(toMove->data==1){
                insertAtTail(toMove,oneHead,oneTail);
            }
            else if(toMove->data==2){
                insertAtTail(toMove,twoHead,twoTail);
            }
            
        }
        //ab yaha tk teeno ke alag alag LL bann chuke hai 
        //ab teeno ko combine krte hai
    
        
        if(zeroHead!=NULL){
            //zero ka LL is non-empty
            if(oneHead!=NULL){
                //one khali nhi hai
                zeroTail->next=oneHead;
                oneTail->next=twoHead;
                return zeroHead;
            }
            else{
                //one khali hai
                zeroTail->next=twoHead;
                //agar two khali bhi raha toh chalega
                //kyuki wo NUll ko hi point krega so wo chal jayega
                return zeroHead;
            }
        }
        else{
            //zero ka LL is empty
            if(oneHead!=NULL){
                //one bhara h but zero khali h
                oneTail->next=twoHead;
                //agar two khali bhi raha toh chalega
                //kyuki wo NUll ko hi point krega so wo chal jayega
                return oneHead;
            }
            else{
                //one bhi khali hai and two bhi khali hai
                return twoHead;
                
            }
        }
        return oneHead;
    }
};


// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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
    // Create a linked list: 2 -> 1 -> 2 -> 0 -> 1 -> 0 -> NULL
    Node* node1 = new Node(2);
    Node* node2 = new Node(1);
    Node* node3 = new Node(2);
    Node* node4 = new Node(0);
    Node* node5 = new Node(1);
    Node* node6 = new Node(0);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    cout << "Original Linked List: ";
    printList(node1);

    // Sort the linked list
    Solution2 sol;
    Node* sortedHead = sol.segregate(node1);

    cout << "Sorted Linked List: ";
    printList(sortedHead);

    // Free memory
    freeList(sortedHead);

    return 0;
}
