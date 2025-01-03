//leetcode:- 141. Linked List Cycle
//very very very very very very importanttttt
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>m;
        ListNode* temp=head;
        while(temp!=NULL){
            if(m[temp]==true){
                //pehle se true hai, mtlb pehle bhi aa chuka hai
                //mtlb cycle bana 
                return true;
            }
            else{
                //pehle se true nhi hai
                //mai visit kr rha hu, mark true kyuki visit kiya maine
                m[temp]=true;
            }
            temp=temp->next;
        }
        //loop ke bahar aa gya mtlb NULL pointer mil gya poora traverse krne ke baad
        //mtlb cycle not present
        return false;
    }

    //Method 2
    bool hasCycle2(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        //concept ye hai ki fast aage aage jaa rha h 2x ki speed se and slow 1x se
        //toh agar cycle present hogi toh wo pakka ek point pr milenge
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            //iske baad agar dono same position pr aa gye then cycle present
            if(fast==slow){
                return true;
            }
        }
        //loop ke bahar aa gya mtlb fast ko NULL mil gya mtlb cycle not present
        return false;
    }
};

int main() {
    // Create nodes
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Create a linked list with a cycle: 3 -> 2 -> 0 -> -4 -> 2
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Cycle here

    // Test the solution
    Solution sol;
    if (sol.hasCycle2(node1)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    // Free memory (to avoid memory leaks)
    // Note: In real cases, handling cycles while freeing memory is complex.
    // Here, we assume the program ends after detection.
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
