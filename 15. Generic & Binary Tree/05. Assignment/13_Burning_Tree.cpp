//gfg: Burning Tree

#include <bits/stdc++.h>
using namespace std;

// Actual Node definition required for compilation
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    
    void height(Node* root, int& start, int i, int& depth,int& startDepth,bool& position) {
        if(!root) return;

        // If start node is found, store its depth
        if(root->data == start) {
            startDepth = i+1;
            position = true;
        }

        // Track maximum depth in this subtree
        depth = max(depth, i);

        height(root->left, start, i+1, depth, startDepth, position);
        height(root->right, start, i+1, depth, startDepth, position);
    }

    int minTime(Node* root, int start) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;

        int i = 1;
        bool left = false;
        bool right = false;

        int depth = 0;
        int startDepth = 1;
        bool position = false;

        // Calculate height and start position in left subtree
        height(root->left, start, i, depth, startDepth, position);
        int leftheight = 1 + depth;

        depth = 0;

        // If start node was found in left subtree
        if(position) {
            left = true;
            position = false;
        }

        // Calculate height and start position in right subtree
        height(root->right, start, i, depth, startDepth, position);
        int rightheight = 1 + depth;

        // If start node was found in right subtree
        if(position) right = true;

        int ans = 0;

        // Compute burning time depending on which side contains start node
        if(right) {
            ans = leftheight + startDepth - 2; 
            ans = max(ans, rightheight - startDepth);
        } else {
            ans = rightheight + startDepth - 2;
            ans = max(ans, leftheight - startDepth);
        }

        // Recurse for subtrees
        int leftans = minTime(root->left, start);
        int rightans = minTime(root->right, start);

        return max(ans, max(leftans, rightans));
    }
};


class Solution2 {
public:
    Node* makeNodetoParentMappingAndFindTargetNode(Node* root, unordered_map<Node*, Node*>& parentMap, int& start) {
        Node* targetNode = nullptr;
        parentMap[root] = nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            auto front = q.front(); q.pop();
            if(front->data == start) {
                targetNode = front;
            }
            if(front->left) {
                q.push(front->left);
                parentMap[front->left] = front;
            }
            if(front->right) {
                q.push(front->right);
                parentMap[front->right] = front;
            }
        }
        return targetNode;
    }

    void burnTheTree(Node* root, unordered_map<Node*, Node*>& parentMap, unordered_map<Node*, bool>& visited, int i, int& ans) {
        if(!root) return;
        if(visited.find(root) != visited.end()) return;
        visited[root] = true;
        ans = max(ans, i);
        if(parentMap.find(root) != parentMap.end())
            burnTheTree(parentMap[root], parentMap, visited, i+1, ans);
        burnTheTree(root->left, parentMap, visited, i+1, ans);
        burnTheTree(root->right, parentMap, visited, i+1, ans);
    }
    int minTime(Node* root, int start) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = makeNodetoParentMappingAndFindTargetNode(root, parentMap, start);
        unordered_map<Node*, bool> visited;
        int i = 0;
        int ans = 0;
        burnTheTree(targetNode, parentMap, visited, i, ans);
        return ans;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case
    //            1
    //          /   \
    //         2     3
    //        / \     \
    //       4   5     6
    //          /
    //         7
    //
    // Start burning from node 5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->left->right->left = new Node(7);

    int start = 5;

    cout << "Minimum time to burn the tree from node " << start << " = "
         << sol.minTime(root, start) << endl;

    return 0;
}
