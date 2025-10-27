//gfg: Intersection of Two Linked Lists
#include <iostream>
#include <unordered_map>
using namespace std;

/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

// Definition for Node
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
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> freq;
        
        Node* temp = head2;
        while(temp) {
            freq[temp->data]++;
            temp = temp->next;
        }
        
        Node* head = new Node(-1);
        Node* tail = head;
        temp = head1;
        while(temp) {
            if(freq[temp->data] >= 1) {
                tail->next = new Node(temp->data);
                tail = tail->next;
            }
            temp = temp->next;
        }
        return head->next;
    }
};

class Solution2 {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int, int> freq;
        
        Node* temp = head2;
        while(temp) {
            freq[temp->data]++;
            temp = temp->next;
        }
        
        Node* head = NULL;
        Node* tail = 0;
        temp = head1;
        while(temp) {
            if(freq.find(temp->data) != freq.end()) {
                if(head == NULL) {
                    head = temp;
                    tail = head;
                }
                else {
                    if(freq[temp->data] > 0) {
                        tail->next = temp;
                        tail = tail->next;
                        freq[temp->data]--;
                    }
                }
            }
            temp = temp->next;
        }
        if(tail) {
            tail->next = NULL;
        }
        return head;
    }
};

int main() {
    // Creating first linked list: 1 -> 2 -> 3 -> 4 -> 6
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    // Creating second linked list: 2 -> 4 -> 6 -> 8
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    Solution obj;
    Node* intersection = obj.findIntersection(head1, head2);

    cout << "Intersection List: ";
    while(intersection) {
        cout << intersection->data << " ";
        intersection = intersection->next;
    }
    cout << endl;

    return 0;
}
