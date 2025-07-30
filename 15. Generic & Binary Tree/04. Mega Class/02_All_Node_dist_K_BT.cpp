//leetcode: 863. All Nodes Distance K in Binary Tree
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(!root) return;

        if(root->left) {
            parent[root->left] = root;
            getParent(root->left, parent);
        }
        if(root->right) {
            parent[root->right] = root;
            getParent(root->right, parent);
        }
    }
    
    void solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, vector<int>& ans, int k) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*, bool>vis;
        q.push(root);
        vis[root] = true;
        int currLevel = 0;
        while(!q.empty()) {
            int size = q.size();//nodes in current level
            if(currLevel == k) break; //now my answer nodes should be present in queue itself
            currLevel++;
            //traverse over all nodes of current level
            for(int i=0; i<size; i++) {
                auto front = q.front();
                vis[front] = true;
                q.pop();
                if(front->left && !vis[front->left]) {
                    q.push(front->left);
                }
                if(front->right && !vis[front->right]) {
                    q.push(front->right);
                }
                if(parent[front] != NULL && !vis[parent[front]]) {
                    q.push(parent[front]);
                }
            }
        }
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;

        getParent(root, parent);

        vector<int> ans;

        solve(target, parent, ans, k);
        return ans;
    }
};

int main() {
    // Constructing the binary tree:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // node with value 5
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target node " << target->val << " are: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
