#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(){
    cout << "Enter the value for Node: "<<endl;
    int value;
    cin >> value;

    if(value == -1){
        return NULL;
    }
    else{
    Node* root = new Node(value);

    //ab baaki kaam recursion se karwa lo
    root->left = createNode();
    root->right = createNode();
    return root;
    }
}

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    else{
        //preorder
        //NLR
        //N
        cout<<root->data<<" ";
        //L
        preorderTraversal(root->left);
        //R
        preorderTraversal(root->right);
    }
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    else{
        //inorder
        //LNR
        //L
        inorderTraversal(root->left);
        //N
        cout<<root->data<<" ";
        //R
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    else{
        //postorder
        //LRN
        //L
        postorderTraversal(root->left);
        //R
        postorderTraversal(root->right);
        //N
        cout<<root->data<<" ";
    }
}

void leverOrderTraversal(Node* root) {
    queue<Node*>q;

    //initial state maintain
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        cout<<front->data<<" ";

        if(front->left != NULL) {
            q.push(front->left);
        }
        if(front->right != NULL) {
            q.push(front->right);
        }
    }
}

int main(){

    Node* root;

    root = createNode();
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    cout<<endl;
    leverOrderTraversal(root);

    return 0;
}