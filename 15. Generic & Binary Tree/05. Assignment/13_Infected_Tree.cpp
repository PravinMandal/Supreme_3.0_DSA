//leetcode: 2385 Amount of Time for Binary Tree to Be Infected

#include <bits/stdc++.h>
using namespace std;

// Actual TreeNode definition required for compilation
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* makeNodetoParentMappingAndFindTargetNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, int& start) {
        TreeNode* targetNode = nullptr;

        // Root has no parent
        parentMap[root] = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        // BFS traversal to map each node to its parent
        while(!q.empty()) {
            auto front = q.front(); 
            q.pop();

            // If start node found, store it
            if(front->val == start) {
                targetNode = front;
            }

            // Map left child to parent
            if(front->left) {
                q.push(front->left);
                parentMap[front->left] = front;
            }

            // Map right child to parent
            if(front->right) {
                q.push(front->right);
                parentMap[front->right] = front;
            }
        }

        return targetNode;
    }

    void burnTheTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap,
                     unordered_map<TreeNode*, bool>& visited, int i, int& ans) {
        if(!root) return;

        // If node already visited, stop recursion
        if(visited.find(root) != visited.end()) return;

        // Mark current node as infected/visited
        visited[root] = true;

        // Update maximum time
        ans = max(ans, i);

        // Move infection to parent node
        if(parentMap.find(root) != parentMap.end())
            burnTheTree(parentMap[root], parentMap, visited, i+1, ans);

        // Move infection to left child
        burnTheTree(root->left, parentMap, visited, i+1, ans);

        // Move infection to right child
        burnTheTree(root->right, parentMap, visited, i+1, ans);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;

        // Find target node and build parent mapping
        TreeNode* targetNode = makeNodetoParentMappingAndFindTargetNode(root, parentMap, start);

        unordered_map<TreeNode*, bool> visited;

        int i = 0;
        int ans = 0;

        // Start infection spreading from target node
        burnTheTree(targetNode, parentMap, visited, i, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    //            1
    //          /   \
    //         5     3
    //        /     / \
    //       4     10  6
    //            /
    //           9
    //
    // Start infection from node 3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    root->right->left->left = new TreeNode(9);

    int start = 3;

    cout << "Amount of time to infect the whole tree starting from node "
         << start << " = " << sol.amountOfTime(root, start) << endl;

    return 0;
}
