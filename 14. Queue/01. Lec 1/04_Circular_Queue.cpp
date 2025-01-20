#include<iostream>
using namespace std;

class CircularQueue{
private:
    int* arr;
    int n;
    int front;
    int rear;
public:
    //ctor
    CircularQueue(int size){
        arr=new int[size]();
        n=size;
        front = -1;
        rear = -1;
    }

    void push(int value){
        // 4 cases: first element, overflow, circular , normal flow
        if(front ==-1 && rear == -1){
            front++;
            rear++;
            arr[rear]=value;
        }
        else if(front == 0 && rear == n-1 || rear==front-1){
            cout<<"overflow"<<endl;
        }
        else if(rear == n-1 && front != 0){
            //circular case
            //rear ko first pr laane se pehle check krna h ki pehle se front hai kya uspr agar nhi hoga tbhi jaana hai
            rear=0; //ab rear starting mai aa gya kyuki empty space tha
            arr[rear]=value;
        }
        else{
            //normal flow
            rear++;
            arr[rear]=value;
        }
    }
    void pop(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            arr[front]=0;
            front=-1;
            rear=-1;
        }
        else if(front == n-1){
            //circular flow
            arr[front]=0;
            front=0;
        }
        else{
            arr[front]=0;
            front++;
        }
    }
    int getFront(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            return arr[front];
        }
    }
    int getRear(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            return arr[rear];
        }
    }
    int size(){
        if(front == -1 && rear == -1){
            return 0;
        }
        else if(rear>=front){
            return rear-front+1;
        }
        else{
            return n-front+rear+1;
        }
    }
    bool isempty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }
    void print(){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){

    CircularQueue q(5);

    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    q.push(60);
    q.print();

    q.pop();
    q.print();
    q.pop();
    q.print();
    q.push(100);
    q.print();
    q.push(101);
    q.print();
    q.push(102);
    q.print();

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.size()<<endl;
    cout<<q.isempty()<<endl;

    return 0;
}