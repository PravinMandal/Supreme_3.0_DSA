#include<iostream>
using namespace std;

class Queue{
private:
    int* arr;
    int n;
    int front;
    int back;
public:
    //ctor
    Queue(int size){
        arr = new int[size];
        n=size;
        front=-1;
        back=-1;
    }

    void push(int value){
        if(front == -1 && back == -1){
            front++;
            back++;
            arr[back]=value;
        }
        else if(back == n-1){
            cout<<"Overflow"<<endl;
        }
        else{
            back++;
            arr[back]=value;
        }
    }

    void pop(){
        if(front == -1 && back == -1){
            cout<<"Underflow"<<endl;
        }
        else if(front == back){
            //ek hi element h and usse pop krna h
            arr[back]=0; //it's optional
            front=-1;
            back=-1;
        }
        else{
            arr[front]=0; //it's optional
            front++;
        }
    }

    int getfront(){
        if(front == -1 && back == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            return arr[front];
        }
    }

    int getback(){
        if(front == -1 && back == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            return arr[back];
        }
    }

    int size(){
        if(front == -1 && back == -1){
            return 0;
        }
        else{
            return back-front+1;
        }
    }

    bool isempty(){
        if(front == -1 && back == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<q.size()<<endl;
    cout<<q.isempty()<<endl;
    cout<<q.getfront()<<endl;
    cout<<q.getback()<<endl;
    q.push(60);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.isempty()<<endl;
    q.pop();


    return 0;
}