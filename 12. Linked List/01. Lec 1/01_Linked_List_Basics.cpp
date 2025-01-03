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

int Length(Node* &head){
    int length=0;
    Node* temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void insertatPosition(int position, int value, Node* &head, Node* &tail){
    //mai assume krke chal rha hu ki mujhe valid position milega insert krne ke liye
    int length=Length(head);
    if(position==1){
        //iska mtlb mai insert at head krna chahta hu
        head=insertatHead(value,head,tail);
    }
    else if(position==length+1){
        //iska mtlb mai insert at tail krna chahta hu
        head=insertatTail(value,head,tail);
    }
    else{
        //LL mai koi bhi valid position pr insert krna chahta hu
        Node* temp=head;
        Node* newnode=new Node(value);
        for(int i=0; i<position-2; i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
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


void DeleteFromLL(int position,Node* &head, Node* &tail){
    //pehle check kro kya pta koi node bana hi na ho
    if(head==NULL && tail==NULL){
        cout<<"there is not even a single node to delete "<<endl;
    }
    
    //if sirf ek hi LL node ho
    if(head==tail){
        head=NULL;
        tail=NULL;
    }
    else{
        //multiple nodes
        // isme bhi 2 cases honge 
        //case 1: 1st node delete krna h
        if(position==1){
            Node* temp=head; //ek temp bana liye taaki uske through delete kre
            head=temp->next; // ab head next wale pr chala gya 
            temp->next=NULL;
            delete temp; //jo nodes bane hote h wo heap mai banaya h humne toh usse delete krna zaruri h
        }
        else{
            //other then 1st position delete krna h
            Node* prev=head;
            // ab temp ko aage badhakr jisse delete krna h uske piche wale pr point kr denge
            for(int i=0; i<position-2; i++){
                prev=prev->next; 
            }
            Node* curr=prev->next;
            Node* forward=curr->next;
            prev->next=forward;
            curr->next=NULL;
            delete curr;
        }
    }

}

// isme position nhi user bolega ye element delete krna h usko delete krna pdega
void DeleteTargetFromLL(int target,Node* &head, Node* &tail){
    int position=SearchInLL(target,head,tail); // ye mujhe position laake de dega
    //pehle check kro kya pta koi node bana hi na ho
    if(head==NULL && tail==NULL){
        cout<<"there is not even a single node to delete "<<endl;
    }
    
    //if sirf ek hi LL node ho
    if(head==tail){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else{
        //multiple nodes
        // isme bhi 2 cases honge 
        //case 1: 1st node delete krna h
        if(position==1){
            Node* temp=head; //ek temp bana liye taaki uske through delete kre
            head=temp->next; // ab head next wale pr chala gya 
            temp->next=NULL;
            delete temp; //jo nodes bane hote h wo heap mai banaya h humne toh usse delete krna zaruri h
        }
        else{
            //other then 1st position delete krna h
            Node* prev=head;
            // ab temp ko aage badhakr jisse delete krna h uske piche wale pr point kr denge
            for(int i=0; i<position-2; i++){
                prev=prev->next; 
            }
            Node* curr=prev->next;
            Node* forward=curr->next;
            prev->next=forward;
            curr->next=NULL;
            delete curr;
        }
    }

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
    insertatPosition(1,55,head,tail);
    print(head);
    // 55->30->20->10->40->50->NULL
    insertatPosition(7,90,head,tail);
    print(head);
    // 55->30->20->10->40->50->90->NULL
    insertatPosition(3,69,head,tail);
    print(head);
    // 55->30->69->20->10->40->50->90->NULL
    int search=SearchInLL(10,head,tail);
    if(search==-1){
        cout<<"target Not found"<<endl;
    }
    else{
        cout<<"Target found at position "<<search<<endl;
    }
    DeleteFromLL(1,head,tail);
    print(head);
    // 30->69->20->10->40->50->90->NULL
    DeleteFromLL(7,head,tail);
    print(head);
    // 30->69->20->10->40->50->NULL
    DeleteFromLL(4,head,tail);
    print(head);
    // 30->69->20->40->50->NULL
    DeleteTargetFromLL(69,head,tail);
    print(head);
    // 30->20->40->50->NULL



    return 0;
}