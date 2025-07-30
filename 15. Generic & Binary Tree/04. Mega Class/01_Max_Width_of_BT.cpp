//leetcode: 662. Maximum Width of Binary Tree
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// TreeNode definition as given
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        unsigned long long maxWidth = 0;
        //sabko bss indexing kr rhe h phir usse, currWidth = rightMostindex - leftMostindex + 1;
        //ye formula use krke uss level pr kitna width h nikal jayega
        //fir max() use krke compare krke store kr lenge
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        while(!q.empty()) {

            unsigned long long size = q.size();
            unsigned long long leftMostindex = q.front().second;
            unsigned long long rightMostindex = q.back().second;
            unsigned long long currWidth = rightMostindex - leftMostindex + 1;
            maxWidth = max(maxWidth, currWidth);

            //naya tarika level order traversal ka
            // ab bina NULL push kiye bhi level order traversal kr skte h
            for(unsigned long long i=0; i<size; i++) {
                auto front = q.front();
                q.pop();
                auto Node = front.first;
                unsigned long long index = front.second;
                
                //left child index = 2*parent;
                //right child index = 2*parent+1;
                if(front.first->left) {
                    q.push({Node->left, 2*index});
                }
                if(front.first->right) {
                    q.push({Node->right, 2*index + 1});
                }
            }
        }
        return maxWidth;
    }
};

int main() {
    // Sample binary tree:
    //         1
    //        / \
    //       3   2
    //      /     \
    //     5       9
    //    /         \
    //   6           7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    int maxWidth = sol.widthOfBinaryTree(root);
    cout << "Maximum width of binary tree: " << maxWidth << endl;

    return 0;
}
