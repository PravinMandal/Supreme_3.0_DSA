#include<iostream>
using namespace std;

class Stack{
public:
    int* arr;
    int size;
    int top;

    Stack(int capacity){
        arr=new int[capacity](); // () paranthesis lagane se ye 0 se initialize ho jaata h
        size=capacity;
        top=-1;
    }

    void push(int value){
        if(top == size-1){
            //stack already full hai aur nhi bhar skte
            cout<<"Stack overflow"<<endl;
        }
        else{
            top++;
            arr[top]=value;
        }
    }

    void pop(){
        if(top==-1){
            //-1 pr hai mtlb stack khali h aur pop nhi kr skte
            cout<<"Stack underflow"<<endl;
        }
        else{
        arr[top]=0; // ye mandatory nhi h
        top--;           
        }
    }

    int getsize(){
        return top+1; //top toh index h agar 0 pr hai toh 1 size hai and soo on
    }

    bool isempty(){
        if(top==-1){
            //-1 hai mtlb empty hai
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            return arr[top];
        }
    }

    void print(){
        cout<<"Printing Stack"<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){

    Stack s(5);
    s.push(10);
    s.print();
    s.push(20);
    s.print();
    s.push(30);
    s.print();
    s.push(40);
    s.print();
    s.push(50);
    s.print();
    s.push(60);
    s.print();

    cout<<s.getTop()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.isempty()<<endl;

    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    
    return 0;
}