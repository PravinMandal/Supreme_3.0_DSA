//gfg: Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf)

#include <bits/stdc++.h>
using namespace std;

// Actual Node definition required for compilation
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    void solve(Node* root, int& ans, int i, int& maxL, int sum) {
        if(!root) return;

        // Add current node value to path sum
        sum += root->data;

        // If leaf node is reached, check longest path length
        if(!(root->left) && !(root->right) && i >= maxL) {

            // If new longest path found, update answer directly
            if(i > maxL) ans = sum;

            // If same length path found, take maximum sum
            else ans = max(ans, sum);

            // Update maximum length
            maxL = i;
        }

        // Recurse left and right with increased length
        solve(root->left, ans, i+1, maxL, sum);
        solve(root->right, ans, i+1, maxL, sum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int ans = INT_MIN;
        int i = 0;
        int maxL = 0;
        int sum = 0;

        solve(root, ans, i, maxL, sum);

        return ans;
    }
};

class Solution2 {
  public:
    pair<int, int> height(Node* root) {
        if(!root) return {0,0};
        
        auto lh = height(root->left);
        auto rh = height(root->right);
        int sum = root->data;
        if(lh.first == rh.first) {
            sum += lh.second > rh.second ? lh.second : rh.second;
        } else {
            sum += lh.first > rh.first ? lh.second : rh.second;
        }
        return {max(lh.first, rh.first)+1, sum};
    }
    int sumOfLongRootToLeafPath(Node *root) {
        pair<int, int> h = height(root);
        return h.second;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    //          4
    //         / \
    //        2   5
    //       / \   \
    //      7   1   6
    //         /
    //        3
    //
    // Longest root-to-leaf path: 4 -> 2 -> 1 -> 3
    // Sum = 4 + 2 + 1 + 3 = 10

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(3);
    root->right->right = new Node(6);

    cout << "Sum of Longest Root to Leaf Path = "
         << sol.sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
