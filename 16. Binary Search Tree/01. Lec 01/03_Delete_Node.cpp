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

int getMin(Node* root) {
    if(root == NULL) return -1;
    while(root->left != NULL) {
        root = root->left;
    }
    //mai ab ekdum extreme left mai aa chuka hu
    // yaha pr mujhe sbse min element mil jayega
    return root->data;
}

int getMax(Node* root) {
    if(root == NULL) return -1;
    while(root->right != NULL) {
        root = root->right;
    }
    //mai ab ekdum extreme right mai aa chuka hu
    // yaha pr mujhe sbse min element mil jayega
    return root->data;
}

Node* deleteNode(Node* root, int key) {
        
    if(root == NULL) return NULL;

    if(root->data == key) {
        //wo value mil gya jise delete krna hai
        //ab 4 cases h
        //case 1: jisse delete krna h uske left aur right child hi na ho
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //case 2: left child ho and right child na ho
        if(root->left != NULL && root->right == NULL) {
            Node* leftChild = root->left; //uske left child ko store krlo
            root->left = NULL; //ab left child ko NULL mai point kara do
            delete root; 
            return leftChild; // left child ko return kr dunga toh wo upr connect ho jayega
        }
        //case 3: left child na ho and right child ho
        if(root->left == NULL && root->right != NULL) {
            Node* rightChild = root->right; //uske right child ko store krlo
            root->right = NULL;
            delete root;
            return rightChild;
        }
        //case 4: dono child ho 
        if(root->left != NULL && root->right != NULL) {
            // ab agar mujhe isse delete kr h toh kuch toh uske position pr rakhna hi pdega 
            // 2 options h yaa toh usse just chhota element rakhu yaa just bada dono chalega
            // for this question let's just chhota lete h
            // just chhota kaise milega uske left node se sbse extreme right
            // mtlb left jao then sbse right chale jao mil jayega 

            int justChhota = getMax(root->left);
            root->data = justChhota; // data overwrite kr diya
            //ab mujhe jo justChhota h usse delete krna hoga kyuki ab usse nhi rakh skte
            root->left = deleteNode(root->left, justChhota);
            return root;
        }

    }
    else {
        if(key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
    return root;
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
    cout<<endl;

    root = deleteNode(root, 100);

    levelorderTraversal(root);
    cout<<endl<<"Preorder: ";
    preorderTraversal(root);
    cout<<endl<<"Inorder: ";
    inorderTraversal(root);
    cout<<endl<<"Postorder: ";
    postorderTraversal(root);
    cout<<endl;

    return 0;
}