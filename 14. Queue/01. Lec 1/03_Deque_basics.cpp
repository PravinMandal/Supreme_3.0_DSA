#include<iostream>
using namespace std;

class Deque{
private:
    int* arr;
    int n;
    int front;
    int rear;
public:
    //ctor
    Deque(int size){
        arr=new int[size]();
        n=size;
        front=-1;
        rear=-1;
    }

    void push_front(int value){
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front]=value;
        }
        else if(front == 0){
            cout<<"Overflow"<<endl;
        }
        else{
            front--;
            arr[front]=value;
        }
    }

    void push_back(int value){
        if(front ==-1 && rear == -1){
            front++;
            rear++;
            arr[rear]=value;
        }
        else if(rear == n-1){
            cout<<"Overflow"<<endl;
        }
        else{
            rear++;
            arr[rear]=value;
        }
    }

    void pop_front(){
        if(front == -1 && rear ==-1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            arr[front]=0;
            front=-1;
            rear=-1;
        }
        else{
            arr[front]=0;
            front++;
        }
    }

    void pop_back(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            arr[rear]=0;
            front=-1;
            rear=-1;
        }
        else{
            arr[rear]=0;
            rear--;
        }
    }

    void print(){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){

    Deque dq(5);

    dq.push_front(10);
    dq.print();
    dq.push_front(20);
    dq.print();

    dq.push_back(20);
    dq.print();
    dq.push_back(30);
    dq.print();
    dq.push_back(40);
    dq.print();
    dq.push_back(50);
    dq.print();
    dq.push_back(60);
    dq.print();

    dq.pop_back();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_front();
    dq.print();
    
    dq.push_front(20);
    dq.print();
    dq.push_front(10);
    dq.print();
    dq.push_front(10);
    dq.print();

    


    return 0;
}