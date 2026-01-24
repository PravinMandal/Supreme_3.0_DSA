//gfg: Maximum sum of Non-adjacent nodes

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
    pair<int, int> getMaxSum_helper(Node* root) {
        if(!root) return {0,0};

        // Get answers from left and right subtrees
        auto left = getMaxSum_helper(root->left);
        auto right = getMaxSum_helper(root->right);

        // sum including the node;
        // If we include current node, we cannot include its children
        int a = root->data + left.second + right.second;

        // sum excluding current node;
        // If we exclude current node, we can choose best of include/exclude from children
        int b = max(left.first, left.second) + max(right.first, right.second);

        return {a,b};
    }

    int getMaxSum(Node *root) {

        auto ans = getMaxSum_helper(root);

        // Final answer is max of including or excluding root
        return max(ans.first, ans.second);
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    //          10
    //         /  \
    //        1    2
    //       / \    \
    //      3   4    5
    //
    // Non-adjacent max sum = 10 + 3 + 4 + 5 = 22

    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    cout << "Maximum Sum of Non-Adjacent Nodes = "
         << sol.getMaxSum(root) << endl;

    return 0;
}
