//gfg: Get Kth Node From End of Linked List

#include <iostream>
using namespace std;

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        int count = 0;
        Node* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }
        if(k > count) return -1;
        temp = head;
        for(int i=1; i<=count-k; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
};

class Solution2 {
  public:
    void solve(Node* head, int& count, int& ans, int k) {
        if(!head) return;
        
        solve(head->next, count, ans, k);
        count++;
        if(count == k) {
            ans = head->data;
            return;
        }
    }
    int getKthFromLast(Node* head, int k) {
        int count = 0;
        Node* temp = head;
        int ans = -1;
        solve(temp, count, ans, k);
        return ans;
    }
};

int main() {
    // Hardcoded test case
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Solution2 sol;

    int k = 2;  // Example test: find 2nd node from last
    cout << "Kth node from end (" << k << "): " << sol.getKthFromLast(head, k) << endl;

    k = 5;  // Another test
    cout << "Kth node from end (" << k << "): " << sol.getKthFromLast(head, k) << endl;

    k = 6;  // Out of bounds test
    cout << "Kth node from end (" << k << "): " << sol.getKthFromLast(head, k) << endl;

    return 0;
}
