#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //constructor
    Node(int value){
        this->data=value;
        this->next=Null;
    }
};

int lengthOfLL(Node* &head){
    int length=0;
    Node* temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

bool SearchInLL(int target,Node* &head,Node* &tail){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return true;
        }
        temp=temp->next;
    }
    //yaha tak aa gye mtlb target nhi mila
    return false;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;



    return 0;
}