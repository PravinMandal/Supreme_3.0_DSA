//gfg: top view of binary tree
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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q;
        //to maintail initial state
        q.push(make_pair(root, 0));
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
            if(distMap.find(hd) == distMap.end()){
                //iska mtlb iss distance ke liye
                //Koi node insert nhi hua h
                distMap[hd] = frontNode;
            }
            
            //left child
            if(frontNode->left != NULL){
                q.push(make_pair(frontNode->left, hd - 1));
            }
            //right child
            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right, hd + 1));
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
                /   \
               2     3
              / \   / \
             4   5 6   7
                      /
                     8

       Explanation of Horizontal Distances:
       - Node 4: hd = -2
       - Node 2: hd = -1
       - Node 1: hd =  0
       - Node 3: hd =  1
       - Node 7: hd =  2  (Node 8 has hd = 1 but is not the first node at hd=1)

       Expected Top View: 4, 2, 1, 3, 7
    */
    
    // Creating the tree nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    
    // Create an object of Solution and get the top view of the tree
    Solution sol;
    vector<int> top_view = sol.topView(root);
    
    // Output the top view
    cout << "Top View of the Tree: ";
    for (int val : top_view) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
