//leetcode: 142. Linked List Cycle II
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution 1 (Floyd's Cycle Detection)
class Solution1 {
public:
    ListNode* checkCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                slow = slow->next;
                if(fast == slow) {
                    return slow;
                }
            }
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        //algorithm aisa hai ki first find kro cycle hai ki nhi
        //and hai toh kaha pr slow and fast meet kr rhe h
        //uske baad slow ko wapas se head(starting) pr rakhdo
        //and slow and fast ko 1x speed se badhao
        //wo ek point pr meet krenge wahi ans hoga
        //wahi wo point hoga jaha cycle ki biggening hai
        //simple proof hai and interviwer puchega
        //dist cover by fast = 2 x dist cover by slow
        //and a,b,c,d aise variable leke ek example mai sarre dist ko mark krke 
        //proof nikal jayega
        ListNode* fast = checkCycle(head);
        if(fast == NULL) return NULL;
        else {
            ListNode* slow = head;
            while(slow!=fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
};

// Solution 2 (Using HashMap)
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;
        while(temp) {
            if(visited[temp]) {
                return temp;
            }
            else {
                visited[temp] = true;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

// Helper function to create a linked list with cycle
ListNode* createCyclicList() {
    // hardcoded list: [3,2,0,-4], pos = 1 (cycle starts at node with value 2)
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // cycle here

    return head;
}

//Main function
int main() {
    ListNode* head = createCyclicList();

    Solution1 s1;
    ListNode* result1 = s1.detectCycle(head);
    if(result1) {
        cout << "Solution1 (Floyd's) - Cycle starts at node with value: " << result1->val << endl;
    }
    else {
        cout << "Solution1 (Floyd's) - No cycle detected" << endl;
    }

    Solution2 s2;
    ListNode* result2 = s2.detectCycle(head);
    if(result2) {
        cout << "Solution2 (HashMap) - Cycle starts at node with value: " << result2->val << endl;
    }
    else {
        cout << "Solution2 (HashMap) - No cycle detected" << endl;
    }

    return 0;
}
