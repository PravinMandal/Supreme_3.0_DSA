//leetcode: 987 Vertical Order Traversal of a Binary Tree

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
    int rowMin = INT_MAX;

    void solve(TreeNode* root, vector<pair<pair<int,int>, int>>& pairing, int row, int col) {
        if(!root) return;

        // Store (row, col) position along with node value
        pairing.push_back({{row, col}, root->val});

        // Track minimum row (leftmost vertical line)
        rowMin = min(rowMin, row);

        // Left child goes to left column (row-1) and next level (col+1)
        solve(root->left, pairing, row-1, col+1);

        // Right child goes to right column (row+1) and next level (col+1)
        solve(root->right, pairing, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<pair<pair<int,int>, int>> pairing;
        if(!root) return ans;

        int row = 0;
        int col = 0;

        solve(root, pairing, row, col);

        // Sort based on (row, col) first, then value automatically
        sort(pairing.begin(), pairing.end());

        int prev = rowMin;
        vector<int> temp;

        // Group nodes column by column
        for(auto i : pairing) {
            if(i.first.first == prev) {
                temp.push_back(i.second);
            } else {
                ans.push_back(temp);
                temp.clear();
                temp.push_back(i.second);
                prev = i.first.first;
            }
        }

        if(!temp.empty()) {
            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};


//same hi hai just jaisa question mai bola tha waise row and col mai aage badhe hai
class Solution2 {
public:
    int colMin = INT_MAX;
    void solve(TreeNode* root, vector<pair<pair<int,int>, int>>& pairing, int row, int col) {
        if(!root) return;
        pairing.push_back({{col, row}, root->val});
        colMin = min(colMin, col);
        solve(root->left, pairing, row+1, col-1);
        solve(root->right, pairing, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<pair<pair<int,int>, int>> pairing;
        if(!root) return ans;
        int row = 0;
        int col = 0;
        solve(root, pairing, row, col);
        sort(pairing.begin(), pairing.end());
        
        int prev = colMin;
        vector<int>temp;
        for(auto i : pairing) {
            if(i.first.first == prev) {
                temp.push_back(i.second);
            } else {
                ans.push_back(temp);
                temp.clear();
                temp.push_back(i.second);
                prev = i.first.first;
            }
        }
        if(!temp.empty()) {
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
};

//better
class Solution3 {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q; //Node, {row, col}
        map<int, map<int, multiset<int>>> mp; // col -> {row : [x, y, z...]}
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* &node = front.first;
            auto coordinate = front.second;
            int& row = coordinate.first;
            int& col = coordinate.second;
            mp[col][row].insert(node->val);
            if(node->left)
                q.push({node->left, {row+1, col-1}});
            if(node->right)
                q.push({node->right, {row+1, col+1}});
        }

        //store final vertical order into ans vector
        for(auto it : mp) {
            vector<int> vLine;
            auto colMap = it.second;
            for(auto colMapIt : colMap) {
                auto& mset = colMapIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};

int main() {
    Solution3 sol;

    // Hardcoded test case
    //          3
    //         / \
    //        9   20
    //           / \
    //          15  7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = sol.verticalTraversal(root);

    // Print vertical traversal
    cout << "Vertical Order Traversal:" << endl;
    for(auto &col : result) {
        for(int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
