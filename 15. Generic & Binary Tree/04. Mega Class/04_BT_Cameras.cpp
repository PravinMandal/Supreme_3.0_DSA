//leetcode: 968. Binary Tree Cameras
//HW: leetcode: 297
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int solve(TreeNode* root, int& cameras) {
        if(!root) return 1; //NULL hai toh usse covered consider kro

        int left = solve(root->left, cameras);
        int right = solve(root->right, cameras);

        if(left == 0 || right == 0) {
            //agar dono mai se ek covered nhi h
            //camera lagana pdega
            cameras++;
            return 2;
        }
        if(left == 2 || right == 2) {
            //dono side camera hai
            //covered hai
            return 1;
        }
        else return 0; // (left == 1 && right == 1) dono side covered hai just like leaf node
    }

    int minCameraCover(TreeNode* root) {
        //camera states:
        //0 -> not covered
        //1 -> covered
        //2 -> camera installed at this node
        int cameras = 0;
        int rootState = solve(root, cameras);
        if(rootState == 0) {
            //last mai root hi covered nhi h
            cameras++;
        }
        return cameras;
    }
};

int main() {
    // Tree used:
    //         0
    //        / \
    //       0   0
    //      /
    //     0
    //    /
    //   0

    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->left->left = new TreeNode(0);

    Solution sol;
    int result = sol.minCameraCover(root);
    cout << "Minimum number of cameras needed: " << result << endl;

    // Free memory
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
