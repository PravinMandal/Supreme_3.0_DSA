//leetcode: 138. Copy List with Random Pointer
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of Node
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // Recursive helper function to create a deep copy of the linked list
    Node* solve(Node* head, unordered_map<Node*, Node*>& map) {
        if(!head) return NULL;  // Base case: if list is empty, return NULL

        // Create a new node with the same value as the current node
        Node* newhead = new Node(head->val);

        // Store mapping of original node to its copy
        map[head] = newhead;

        // Recursively copy the rest of the list (next pointer)
        newhead->next = solve(head->next, map);

        // Assign the random pointer using the map (if it exists)
        newhead->random = head->random ? map[head->random] : NULL;

        return newhead;
    }

    // Function to copy a linked list with random pointers
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        return solve(head, map);
    }
};

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        //step 1: clone A -> A'
        Node* it = head;
        while(it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        //step 2: assign random links of A' with the help of A
        it = head;
        while(it) {
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : NULL;
            it = it->next->next;
        }

        //step 3: Detach A' from A
        it = head;
        Node* clonedHead = it->next;
        while(it) {
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if(clonedNode->next) {
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }
        return clonedHead;
    }
};

// Utility function to print a linked list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << "Node value: " << temp->val;
        if(temp->random)
            cout << ", Random points to: " << temp->random->val;
        else
            cout << ", Random points to: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating a sample linked list:
    // List: 1 -> 2 -> 3
    // Random pointers: 1->3, 2->1, 3->2
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    
    n1->next = n2;
    n2->next = n3;

    n1->random = n3;
    n2->random = n1;
    n3->random = n2;

    cout << "Original List:\n";
    printList(n1);

    Solution2 obj;
    Node* copied = obj.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copied);

    return 0;
}
