//gfg: Diagonal Traversal of Binary Tree

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
    void solve(Node *root, map<int, vector<int>>& vecMap, int d) {
        if(!root) return;

        // Store current node in its diagonal index
        vecMap[d].push_back(root->data);

        //logic ye hai ki left jayenge toh +1 bol denge and right ko nhi
        //toh jo 0 hoga wo 1st diagonal, 1-> 2nd diagonal, 2-> 3rd diagonal
        // Left child goes to next diagonal
        solve(root->left, vecMap, d+1);

        // Right child stays on same diagonal
        solve(root->right, vecMap, d);
    }

    vector<int> diagonal(Node *root) {
        vector<int> ans;
        map<int, vector<int>> vecMap;
        int d = 0;

        solve(root, vecMap, d);

        // Collect diagonal-wise traversal result
        for(auto i : vecMap) {
            for(int j : i.second) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};

class Solution2 {
  public:
    vector<int> diagonal(Node *root) {
       vector<int> ans;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()) {
           auto front = q.front(); q.pop();
           if(front->left) q.push(front->left);
           
           ans.push_back(front->data);
           while(front->right) {
               front = front->right;
               ans.push_back(front->data);
               if(front->left) q.push(front->left);
           }
       }
       return ans;
    }
};

class Solution3 {
  public:
    vector<int> diagonal(Node *root) {
       vector<int> ans;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()) {
           auto front = q.front(); q.pop();
           while(front) {
               ans.push_back(front->data);
               if(front->left) q.push(front->left);
               front = front->right;
           }
       }
       return ans;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case
    //          8
    //        /   \
    //       3     10
    //      / \      \
    //     1   6      14
    //        / \     /
    //       4   7   13
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    vector<int> result = sol.diagonal(root);

    // Print diagonal traversal
    cout << "Diagonal Traversal: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
