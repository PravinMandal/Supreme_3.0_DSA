//leetcode: 725. Split Linked List in Parts
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }

        int sizeofonePart = n/k;
        int remainingPart = n%k;

        vector<ListNode*> ans(k, nullptr);
        ListNode* it = head;
        for(int i=0; i<k && it; i++) {
            ans[i] = it;
            int currPart = sizeofonePart + (remainingPart-- > 0 ? 1:0);
            for(int j=0; j<currPart-1; j++) {
                it = it->next;
            }
            ListNode* nextPartStarting = it->next;
            it->next = nullptr;
            it = nextPartStarting;
        }
        return ans;
    }
};

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printParts(const vector<ListNode*>& parts) {
    for (int i = 0; i < parts.size(); i++) {
        ListNode* curr = parts[i];
        cout << "Part " << i+1 << ": ";
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    ListNode* head = createList(values);

    Solution sol;
    vector<ListNode*> parts = sol.splitListToParts(head, k);

    printParts(parts);

    return 0;
}
