//leetcode: 23. Merge k Sorted Lists
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    
    // Constructor to initialize a list node with a given value.
    ListNode(int x) : val(x), next(NULL) {}
};

class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
     };
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, compare> pq;
            ListNode* head = NULL;
            ListNode* tail = NULL;
    
            for(int row=0; row<lists.size(); row++) {
                ListNode* temp = lists[row];
                if(temp != NULL) {
                    //if its a valid node
                    pq.push(temp);
                }
            }
    
            while(!pq.empty()) {
                //front nikalo
                ListNode* front = pq.top();
                pq.pop();
                //ans mai insert kro
                if(head == NULL && tail == NULL) {
                    //it mean mai pehla node insert kr rha hu LL mai
                    head = front;
                    tail = front;
                }
                else {
                    //pehla node nhi h
                    tail->next = front;
                    tail = front;
                }
                //agar aage node h toh pq mai insert kro
                if(tail->next != NULL) {
                    pq.push(tail->next);
                }
            }
            return head;
        }
    };

int main() {
    /*
       Constructing three sorted linked lists:
       
       List 1: 1 -> 4 -> 5
       List 2: 1 -> 3 -> 4
       List 3: 2 -> 6
       
       Expected Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
    */
    
    // Creating list 1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    
    // Creating list 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    // Creating list 3: 2 -> 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    
    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);
    
    // Output the merged list.
    cout << "Merged List: ";
    while (merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    
    return 0;
}
