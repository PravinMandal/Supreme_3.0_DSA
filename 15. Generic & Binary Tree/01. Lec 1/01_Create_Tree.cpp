#include<iostream>
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
        cout<<"adding left child for root "<<root->data<<endl;
        root->left = createNode();

        cout<<"adding right child for root "<<root->data<<endl;
        root->right = createNode();
        return root;
    }
}

int main(){

    Node* root;

    root = createNode();


    return 0;
}