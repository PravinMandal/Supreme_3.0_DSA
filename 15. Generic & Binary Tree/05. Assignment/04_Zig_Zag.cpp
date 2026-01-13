//leetcode: 103 Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;
        bool flag = false;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            auto front = q.front(); q.pop();
            if(front == NULL) {
                if(flag) {
                    reverse(temp.begin(), temp.end());
                }
                ans.push_back(temp);
                if(!q.empty()) q.push(NULL);
                flag = !flag;
                temp.clear();
            } else {
                temp.push_back(front->val);
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        bool LtoRdir = true;
        queue<TreeNode*> q;
        q.push(root);

        // Standard level order traversal using queue
        while(!q.empty()) {
            int width = q.size();

            // This vector stores values of one level in required zigzag order
            vector<int> oneLevel(width);

            for(int i=0; i<width; i++) {
                auto front = q.front(); 
                q.pop();

                // Decide index based on current direction
                int index = LtoRdir ? i : width - i - 1;
                oneLevel[index] = front->val;

                // Push children for next level
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            ans.push_back(oneLevel);

            //toggle direction
            LtoRdir = !LtoRdir;
        }
        return ans;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Print zigzag level order traversal
    cout << "Zigzag Level Order Traversal:" << endl;
    for(auto &level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
