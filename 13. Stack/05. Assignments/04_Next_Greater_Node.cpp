//leetcode: 1019 - Next Greater Node In Linked List

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void solve(ListNode* temp, stack<int>& st, vector<int>& ans) {
        if(!temp) return;

        // Recursive call till the end of linked list
        // This ensures we start checking from the last node (reverse traversal)
        solve(temp->next, st, ans);

        int num = temp->val;

        // Pop all smaller or equal elements because they can’t be the “next greater”
        while(!st.empty() && num >= st.top()) {
            st.pop();
        }

        // If stack is empty, there’s no greater node to the right → push 0
        // Otherwise, the top of stack is the next greater element
        (st.empty()) ? ans.push_back(0) : ans.push_back(st.top());

        // Push current node value onto stack for future comparisons
        st.push(num);
    }

    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next == NULL) return {0};

        stack<int> st;
        ListNode* temp = head;
        vector<int> ans;

        // Recursive traversal to fill the answer array
        solve(temp, st, ans);

        // The recursion fills answers in reverse order, so we reverse them back
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution2 {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> ll;
        ListNode* temp = head;

        // Convert the linked list into a vector for easy index-based access
        while(temp) {
            ll.push_back(temp->val);
            temp = temp->next;
        }

        // Iterate over the vector to find next greater element for each node
        for(int i=0; i<ll.size(); i++) {
            // While stack is not empty and current element is greater than element at index stored in stack
            while(!st.empty() && ll[i] > ll[st.top()]) {
                int kids = st.top(); // Index of smaller element (waiting for its next greater)
                st.pop();
                ll[kids] = ll[i]; // Replace with the next greater value
            }
            st.push(i); // Push current index into stack to find its next greater element later
        }

        // For all remaining indices in stack, no greater element exists → replace with 0
        while(!st.empty()) {
            ll[st.top()] = 0;
            st.pop();
        }

        return ll; // Return final vector of next greater node values
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case 1:
    // Linked list: 2 -> 1 -> 5
    // Next greater node for:
    // 2 → 5, 1 → 5, 5 → 0  → Output: [5, 5, 0]
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    Solution2 sol;
    vector<int> result = sol.nextLargerNodes(head);

    cout << "Next greater nodes for each element: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Hardcoded test case 2:
    // Linked list: 2 -> 7 -> 4 -> 3 -> 5
    // Output should be: [7, 0, 5, 5, 0]
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(7);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(5);

    vector<int> result2 = sol.nextLargerNodes(head2);

    cout << "Next greater nodes for each element: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}
