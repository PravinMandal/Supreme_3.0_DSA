//gfg: Remove loop in Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to remove a loop in the linked list.
    Node* checkCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
                if(fast == slow) {
                    return slow;
                }
            }
        }
        return NULL;
    }
    
    void removeLoop(Node* head) {
        //algorithm aisa hai ki first find kro cycle hai ki nhi
        //and hai toh kaha pr slow and fast meet kr rhe h
        //uske baad slow ko wapas se head(starting) pr rakhdo
        //and slow and fast ko 1x speed se badhao
        //wo ek point pr meet krenge wahi ans hoga
        //wahi wo point hoga jaha cycle ki begening hai
        Node* fast = checkCycle(head);
        if(fast == NULL) return;
        Node* slow = head;
        
        // Special case: cycle starts at head
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
            return;
        }
        
        Node* prev = NULL;
        while(slow!=fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
};

Node* createListWithLoop() {
    // Create: 1->2->3->4->5->2 (loop starts at 2)
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; // loop

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp && count < 20) { // limit to avoid infinite printing
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

int main() {
    Node* head = createListWithLoop();

    Solution s;
    s.removeLoop(head);

    cout << "List after removing loop: ";
    printList(head); // should not loop infinitely

    return 0;
}
