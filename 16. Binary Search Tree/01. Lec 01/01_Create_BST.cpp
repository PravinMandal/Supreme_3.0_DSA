#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node* builtBST(int val, Node* root){
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root->data) {
        root->left = builtBST(val, root->left);
    }
    else {
        root->right = builtBST(val, root->right);
    }
    return root;
}

void createNode(Node* &root){
    int val;
    cout<<"Enter the value for Node: "<<endl;
    cin>>val;

    while(val != -1) {
        root = builtBST(val, root);
        cout<<"Enter the value for Node: "<<endl;
        cin>>val;
    }
}

void levelorderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
        
    }
}

int main() {

    Node* root = NULL;
    createNode(root);
    levelorderTraversal(root);

    return 0;
}