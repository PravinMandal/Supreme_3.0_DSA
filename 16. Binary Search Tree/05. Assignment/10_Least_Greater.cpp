//gfg: Least Greater Element on its Right

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node* makeBST(Node* root, int& elem, int& leastGreater) {
        if(!root) {
            return new Node(elem);
        }
        
        // If current element is smaller, update least greater and go left
        if(elem < root->data) {
            leastGreater = root->data;
            root->left = makeBST(root->left, elem, leastGreater);
        } 
        // Otherwise, go right
        else {
            root->right = makeBST(root->right, elem, leastGreater);
        }
        return root;
    }

    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), -1);

        // Last element has no element to its right
        Node* root = new Node(arr[arr.size() - 1]);
        ans[arr.size() - 1] = -1;

        // Insert elements from right to left into BST
        for(int i = arr.size() - 2; i >= 0; i--) {
            int leastGreater = -1;
            makeBST(root, arr[i], leastGreater);
            ans[i] = leastGreater;
        }
        return ans;
    }
};

class Solution2 {
  public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), -1);
        set<int> st;

        // Traverse array from right to left
        for(int i = arr.size() - 1; i >= 0; i--) {

            // upper_bound gives the least element strictly greater than arr[i]
            auto it = st.upper_bound(arr[i]);

            if(it == st.end()) {
                ans[i] = -1;
            } else {
                ans[i] = *it;
            }

            // Insert current element into set
            st.insert(arr[i]);
        }
        return ans;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = arr.size();

    vector<int> result = sol.findLeastGreater(arr, n);

    cout << "Least Greater Elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
