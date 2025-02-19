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

void preorderTraversal(Node* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return;
}

void inorderTraversal(Node* root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    return;
}

void postorderTraversal(Node* root) {
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
    return;
}

int main() {

    Node* root = NULL;
    createNode(root); //100 50 200 70 20 250 150 -1
    levelorderTraversal(root);
    cout<<endl<<"Preorder: ";
    preorderTraversal(root);
    cout<<endl<<"Inorder: ";
    inorderTraversal(root);
    cout<<endl<<"Postorder: ";
    postorderTraversal(root);


    //BST mai uska inorder traversal krenge toh humesha sorted hi aayega
    //BST ko inorder mai traverse kro dry run and dekho sorted print hota h

    return 0;
}