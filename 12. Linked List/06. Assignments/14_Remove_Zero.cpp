//leetcode: 1171 - Remove Zero Sum Consecutive Nodes from Linked List

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
    // Recursive helper function to remove zero-sum subarrays from vector
    void solve(vector<int>& arr) {
        unordered_map<int, int> map;  // prefix sum -> index
        bool changed = false;         // track if any change was made
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // Case 1: Subarray from start to i sums to zero
            if (sum == 0) {
                arr.erase(arr.begin(), arr.begin() + i + 1);
                changed = true;
                break;
            }

            // Case 2: Subarray between two equal prefix sums sums to zero
            else if (map.find(sum) != map.end()) {
                arr.erase(arr.begin() + map[sum] + 1, arr.begin() + i + 1);
                changed = true;
                break;
            }

            // Store current prefix sum with its index
            map[sum] = i;
        }

        // If something changed, recursively check again for new zero-sum subsequences
        if (changed) solve(arr);
    }

    // Main function to remove zero-sum sublists from a linked list
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return NULL;

        // Step 1: Copy linked list elements into a vector
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Remove zero-sum subarrays from vector representation
        solve(arr);

        // Step 3: If all elements removed, return NULL
        if (arr.empty()) return NULL;

        // Step 4: Rewrite remaining values into the linked list
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            if (i == arr.size() - 1) break;
            temp = temp->next;
        }

        // Step 5: Delete leftover nodes to prevent memory leaks
        ListNode* delTemp = temp->next;
        temp->next = NULL;

        while (delTemp) {
            ListNode* temp2 = delTemp->next;
            delete delTemp;
            delTemp = temp2;
        }

        // Step 6: Return modified head
        return head;
    }
};

class Solution2 {
public:
    // Helper function to clean up prefix sums from map between two points
    void sanitizeMap(ListNode* curr, unordered_map<int, ListNode*>& map, int& csum) {
        int temp = csum;
        while (true) {
            temp += curr->val;      // Increment temporary sum
            if (temp == csum) break; // Stop when we reach the target prefix sum again
            map.erase(temp);         // Remove intermediate sums from the map
            curr = curr->next;       // Move ahead in the list
        }
    }

    // Function to remove zero-sum consecutive nodes from the linked list
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Base case: empty list or single zero node
        if (!head || (!head->next && head->val == 0)) return 0;

        unordered_map<int, ListNode*> map; // prefix sum → corresponding node
        int csum = 0; // current prefix sum
        ListNode* it = head;

        // Traverse through the list
        while (it) {
            csum += it->val; // keep track of prefix sum

            if (csum == 0) {
                // Found a zero-sum from head to current node
                head = it->next;   // move head forward
                map.clear();       // reset the map as all sums before this are invalid
            }
            else if (map.find(csum) != map.end()) {
                // If current sum was seen before, that means nodes between the two equal prefix sums sum to zero
                sanitizeMap(map[csum]->next, map, csum); // Remove those prefix sums from map
                map[csum]->next = it->next; // Skip all zero-sum nodes
            }
            else {
                // Store the prefix sum with its corresponding node
                map[csum] = it;
            }

            // Move to the next node
            it = it->next;
        }

        return head;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // Hardcoded test case
    // Linked list: 1 -> 2 -> -3 -> 3 -> 1
    // After removing zero-sum sublists: 3 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    Solution2 sol;
    ListNode* result = sol.removeZeroSumSublists(head);

    cout << "Modified List: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
