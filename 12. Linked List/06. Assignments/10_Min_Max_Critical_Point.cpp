//leetcode: 2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points
#include <iostream>
#include <vector>
#include <climits>
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
    // Function to find minimum and maximum distances between critical points in a linked list
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans = {-1, -1};

        // Base case: if list has less than 3 nodes, no critical points possible
        if(!head) return ans;
        if(temp->next == NULL) return ans;
        if(temp->next->next == NULL) return ans;

        vector<int> criticalIndex;  // Stores the indices of critical points
        int index = 2;  // Current index (1-based)
        
        // Traverse the list and find critical points
        while(temp->next->next) {
            ListNode* prev = temp;
            ListNode* curr = temp->next;
            ListNode* forward = curr->next;
        
            // Check for local maxima
            if(curr->val > prev->val && curr->val > forward->val) {
                criticalIndex.push_back(index);
            }
            // Check for local minima
            else if(curr->val < prev->val && curr->val < forward->val) {
                criticalIndex.push_back(index);
            }

            index++;
            temp = temp->next;
        }

        // If there are fewer than 2 critical points, we can’t calculate distance
        if(criticalIndex.size() < 2) return ans;

        // Find minimum and maximum distance between critical points
        int mini = INT_MAX;
        for(int i = 1; i < criticalIndex.size(); i++) {
            mini = min(criticalIndex[i] - criticalIndex[i - 1], mini);
        }

        ans[0] = mini;  // Minimum distance
        ans[1] = criticalIndex.back() - criticalIndex.front();  // Maximum distance
        return ans;
    }
};

class Solution2 {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;

        // Default answer if there are not enough critical points
        vector<int> ans = {-1, -1};

        // If list has fewer than 3 nodes, no critical points possible
        if (!head || !temp->next || !temp->next->next) return ans;
        
        int firstCP = -1;   // To store index of first critical point
        int lastCP = -1;    // To store index of last critical point
        int minDist = INT_MAX; // To track minimum distance between any two critical points
        int index = 2;      // Start from the 2nd node (1-based indexing)
        
        // Traverse the list until third-last node
        while (temp->next->next) {
            ListNode* prev = temp;           // Previous node
            ListNode* curr = temp->next;     // Current node
            ListNode* forward = curr->next;  // Next node

            // Check if current node is a critical point
            bool isCP = (curr->val > prev->val && curr->val > forward->val) || 
                        (curr->val < prev->val && curr->val < forward->val);

            if (isCP && firstCP == -1) {
                // Found the first critical point
                firstCP = index;
                lastCP = index;
            }
            else if (isCP) {
                // Found next critical point — update distances
                minDist = min(index - lastCP, minDist);
                lastCP = index;
            }

            // Move to the next node
            index++;
            temp = temp->next;
        }

        // If only one critical point found, return {-1, -1}
        if (firstCP == lastCP) return ans;

        // Minimum distance between any two CPs and maximum distance (first to last)
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;

        return ans;
    }
};

// Utility function to create a linked list from a vector
ListNode* createList(const vector<int>& arr) {
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Main function for testing
int main() {
    // Hardcoded test case
    vector<int> arr = {5, 3, 1, 2, 5, 1, 2};
    ListNode* head = createList(arr);

    Solution2 obj;
    vector<int> result = obj.nodesBetweenCriticalPoints(head);

    cout << "Minimum Distance: " << result[0] << endl;
    cout << "Maximum Distance: " << result[1] << endl;

    return 0;
}
