//gfg: Union of Two Linked Lists

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* makeUnion(Node* head1, Node* head2) {
        map<int, int> mp;

        Node* temp1 = head1;
        Node* temp2 = head2;

        // Insert elements of first list into map
        while(temp1) {
            mp[temp1->data]++;
            temp1 = temp1->next;
        }

        // Insert elements of second list into map
        while(temp2) {
            mp[temp2->data]++;
            temp2 = temp2->next;
        }

        // Create new sorted linked list from map keys
        Node* root = new Node(-1);  // dummy node
        Node* temp = root;

        for(auto i : mp) {
            temp->next = new Node(i.first);
            temp = temp->next;
        }

        return root->next;  // return actual head
    }
};

class Solution2 {
  public:
    Node* makeUnion(Node* head1, Node* head2) {
        map<int, Node*> mp;
        Node* curr = head1;
        while(curr) {
            mp[curr->data] = curr;
            curr = curr->next;
        }
        curr = head2;
        while(curr) {
            mp[curr->data] = curr;
            curr = curr->next;
        }
        Node* root = NULL;
        for(auto it : mp) {
            if(!root) {
                root = it.second;
                curr = root;
            } else {
                curr->next = it.second;
                curr = curr->next;
            }
        }
        curr->next = NULL;
        return root;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded linked list 1: 10 -> 15 -> 4 -> 20
    Node* head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(20);

    // Hardcoded linked list 2: 8 -> 4 -> 2 -> 10
    Node* head2 = new Node(8);
    head2->next = new Node(4);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(10);

    Node* result = sol.makeUnion(head1, head2);

    // Print union list
    while(result) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}