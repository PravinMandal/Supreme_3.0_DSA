//gfg: Bottom view of binary tree
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

// Definition for a binary tree node using class
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize a node with a given value
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> bottomView(Node *root) {
       queue<pair<Node*, int>> q;
        //to maintail initial state
        q.push(make_pair(root,0));
        unordered_map<int, Node*> distMap;
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        
        //Rule: left(-1), right(+1) in distance
        
        while(!q.empty()){
            pair<Node*, int> frontPair = q.front();
            q.pop();
            Node* frontNode = frontPair.first;
            int hd = frontPair.second; // hd-> horizontal distance
            minDist = min(minDist, hd);
            maxDist = max(maxDist, hd);
            
                distMap[hd] = frontNode;
            
            
            //left child
            if(frontNode->left != NULL){
                q.push(make_pair(frontNode->left, hd-1));
            }
            //right child
            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        
        
        vector<int> ans;
        for(int i = minDist; i <= maxDist; i++){
            Node* temp = distMap[i];
            ans.push_back(temp->data);
        }
        return ans;
    }
};

int main() {
    // Constructing the following binary tree:
    /*
                1
               / \
              2   3
             / \   \
            4   5   6
                   /
                  7
       
       Explanation of Horizontal Distances:
       - Node 4: hd = -2
       - Node 2: hd = -1
       - Node 5: hd = 0  (replaces node 1 at hd 0 in bottom view)
       - Node 7: hd = 1  (replaces node 3 at hd 1 in bottom view)
       - Node 6: hd = 2
       
       Expected Bottom View: 4, 2, 5, 7, 6
    */
    
    // Creating the tree nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    
    // Create an object of Solution and get the bottom view of the tree
    Solution sol;
    vector<int> bottom_view = sol.bottomView(root);
    
    // Output the bottom view
    cout << "Bottom View of the Tree: ";
    for (int val : bottom_view) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
