#include<iostream>
using namespace std;

class CircularDeque{
public: 
    int* arr;
    int n;
    int front;
    int rear;
    
    //ctor
    CircularDeque(int size){
        arr=new int[size]();
        n=size;
        front = -1;
        rear = -1;
    }

    void push_front(int val){
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front]=val;
        }
        else if((front == 0 && rear == n-1 ) || (rear == front -1)){
            cout<<"Overflow"<<endl;
        }
        else if(front == 0 && rear != n-1){
            //circular flow 
            front = n-1;
            arr[front] = val;
        }
        else{
            front--;
            arr[front] = val;
        }
    }
    
    void push_back(int val){
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else if((front == 0 && rear == n-1) || (rear == front -1)){
            cout<<"Overflow"<<endl;
        }
        else if(rear == n-1 && front != 0){
            //circular flow
            rear= 0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop_front(){
        if(front == -1 && rear == -1){
            cout<<"Underflow"<<endl;
        }
        else if(front == rear){
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        else if(front == n-1){
            arr[front] = 0;
            front = 0;
        }
        else{
            arr[front] = 0;
            front++;
        }
    }

    void pop_back(){
        if(front == -1 && rear == -1){
            cout<<"Underflow"<<endl;
        }
        else if(front == rear){
            arr[rear] = 0;
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
            arr[rear] = 0;
            rear = n-1;
        }
        else{
            arr[rear] = 0;
            rear--;
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

    CircularDeque q(5);
    q.push_front(10);
    q.print();
    q.push_front(20);
    q.print();
    q.push_back(30);
    q.print();
    q.push_back(40);
    q.print();
    q.push_back(50);
    q.print();

    q.pop_back();
    q.print();
    q.pop_back();
    q.print();

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.size()<<endl;

    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    q.pop_back();
    q.print();



    return 0;
}