#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    //constructor
    Node(int value){
        data=value;
        prev=NULL;
        next=NULL;
    }
};

void insertAtHead(int value, Node* &head, Node* &tail){
    // 2 cases bante h ek toh ki koi node nhi h dusra ki pehle se kuch nodes hai
    // case 1: first node create kr rhe h
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
        //case 2: not empty
        //pehle se kuch node hai
        Node* newnode=new Node(value);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void insertAtTail(int value,Node* &head, Node* &tail){
    // 2 cases bante h LL is empty or not empty
    //case 1: empty
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
        //case 2: not empty
        Node* newnode=new Node(value);
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

int getlength(Node* &head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPosition(int position,int value, Node* &head, Node* &tail){
    int len=getlength(head);
    // 3 cases bante h , pehle ki head pr insert kru , dusra ki tail mai insert kru , 3rd ki kahin bich mai kru
    if(position==1){
        //mtlb ki mai head mai insert krna chahta hu
        insertAtHead(value,head,tail);
    }
    else if(position==len+1){
        //iska mtlb tail pr insert krna chahta hu
        insertAtTail(value,head,tail);
    }
    else{
        //mtlb kahin bich mai insert krna chahta hu
        Node* temp=head;
        //jis position pr insert krna h uske piche wale pr temp ko point krwana h
        for(int i=0; i<position-2; i++){
            temp=temp->next;
        }

        //ab ek new node create kro
        Node* newnode=new Node(value);
        Node* forward=temp->next; // taaki aake wala node ghum na ho jaye
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=forward;
        forward->prev=newnode;
    }
}

void deleteInLL(int position,Node* &head, Node* &tail){
    int length=getlength(head);
    if(head==NULL && tail==NULL){
        //koi node hai hi nhi LL mai
        cout<<"NO node to delete"<<endl;
    }
    else if(head==tail){
        //ek hi node hai
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else if(position==1){
        //head node ko delete krna chahte hai
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
    }
    else if(position==length){
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    else{
        //other than head node and tail node delete krna chahte hai
        Node* backward=head;
        for(int i=0; i<position-2; i++){
            backward=backward->next;
        }
        //assigning node names
        Node* curr=backward->next;
        Node* forward=curr->next;
        
        //node change
        backward->next=forward;
        forward->prev=backward;

        //curr ko isolate kro
        curr->prev=NULL;
        curr->next=NULL;
        //curr isolate ho gya
        delete curr;
    }
}

int SearchInLL(int target,Node* &head,Node* &tail){
    int length=1;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return length;
        }
        length++;
        temp=temp->next;
    }
    //yaha tak aa gye mtlb target nhi mila
    return -1;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void printReverse(Node* &tail){
    Node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    insertAtHead(10,head,tail);
    print(head);
    //10->NULL

    insertAtHead(20,head,tail);
    print(head);
    //20->10->NULL

    insertAtHead(30,head,tail);
    print(head);
    //30->20->10->NULL
    printReverse(tail);
    //10->20->30->NULL

    insertAtTail(40,head,tail);
    print(head);
    //30->20->10->40->NULL

    insertAtPosition(3,15,head,tail);
    print(head);
    //30->20->15->10->40->NULL

    int search=SearchInLL(10,head,tail);
    if(search==-1){
        cout<<"target Not found"<<endl;
    }
    else{
        cout<<"Target found at position "<<search<<endl;
    }

    deleteInLL(1,head,tail);
    print(head);
    // 20->15->10->40->NULL
    deleteInLL(4,head,tail);
    print(head);
    // 20->15->10->NULL
    deleteInLL(2,head,tail);
    print(head);
    // 20->10->NULL

    return 0;
}