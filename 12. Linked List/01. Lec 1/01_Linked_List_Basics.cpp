#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //constructor
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};

//returns head of the updated list
Node* insertatHead(int value, Node* &head, Node* &tail){
    //starting mai LL khali rhega toh pehle hume create krna pdega
    // LL khali h mtlb head aur tail null ko point kr rhe honge
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value); //newnode ek pointer h jo Node type ke dyanamic datatype ko point kr rha h
        head=newnode; 
        tail=newnode;
    }
    else{
        //mtlb ab LL bana hua h khali nhi h
        // ek newnode banao to insert in starting
        Node* newnode=new Node(value);
        newnode->next=head; // newnode jo starting mai banaye ab usko next wale pr point kr rhe h
        head=newnode; // ab starting ka node bann gya toh ab head uspr bana do
    }

    return head;
}

//return head of the updated list
Node* insertatTail(int value, Node* &head, Node* &tail){
    //isme bhi dekhna pdega ki LL khali toh nahi
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
        // agar LL khali nhi h toh ab hume tail mai insert krna h
        Node* newnode=new Node(value); //ek newnode banaye
        tail->next=newnode;
        // newnode->next=NULL; //iski zaroorat nhi pdegi kyuki new node ka next null ko hi point kr rha hota h class Node class
        tail=newnode;
    }
    return head;
}

void print(Node* head){
    Node* temp=head; //temp ko head se intialize kr diye
    //ab head ko thodi idhr udhr kr skte h warna head lost ho jayega isiliye copy kr diye temp mai
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    //abhi LL khali hai

    head=insertatHead(10,head,tail);
    print(head);
    // 10->NULL
    head=insertatHead(20,head,tail);
    print(head);
    // 20->10->NULL
    head=insertatHead(30,head,tail);
    print(head);
    // 30->20->10->NULL
    head=insertatTail(40,head,tail);
    print(head);
    // 30->20->10->40->NULL
    head=insertatTail(50,head,tail);
    print(head);
    // 30->20->10->40->50->NULL



    return 0;
}