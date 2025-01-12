//Add 1 to linked list using recursion 
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};

void solve(Node* head, int &carry){
    if(!head) return;

    //ek case mai likhunga
    solve(head->next,carry);

    int sum=head->data+carry;
    int digit=sum%10;
    carry=sum/10;
    head->data=digit;
}

Node* add1(Node* head, int &carry){
    solve(head,carry);
    if(carry){
        Node* newnode=new Node(carry);
        newnode->next=head;
        head=newnode;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){

    Node* head=new Node(9);
    head->next=new Node(9);
    head->next->next=new Node(9);

    print(head);
    int carry=1;
    head=add1(head,carry);
    print(head);


    return 0;
}