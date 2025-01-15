//implement 2 stack in one array
#include<iostream>
using namespace std;

class Stack{
public:
    int* arr;
    int top1;
    int top2;
    int size;

    Stack(int capacity){
        arr=new int[capacity](); // () paranthesis lagane se dynamic array 0 se initialize ho jaata h
        size=capacity;
        top1=-1;
        top2=size;
    }

    void push1(int value){
        //pehle check kro if space available h then push kro warna stack overflow ho jayega
        if(top2-top1 == 1){
            //mtlb stack bhara hua h
            cout<<"Stack overflow"<<endl;
        }
        else{
            top1++;
            arr[top1]=value;
        }
    }

    void push2(int value){
        //if space h then push kro warna stack overflow ho jayega
        if(top2-top1 == 1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top2--;
            arr[top2]=value;
        }
    }

    void pop1(){
        //check kro if element hai ki nhi pop krne ko
        if(top1 == -1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            arr[top1]=0;
            top1--;
        }
    }

    void pop2(){
        if(top2 == size){
            cout<<"Stack underflow"<<endl;
        }
        else{
            arr[top2]=0;
            top2++;
        }
    }

    void print(){
        cout<<"Top1: "<<top1<<endl;
        cout<<"Top2: "<<top2<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

int main(){

    Stack s(6);
    s.push1(10);
    s.print();
    s.pop1();
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();

    s.push2(40);
    s.print();
    s.push2(50);
    s.print();
    s.push2(60);
    s.print();
    s.push2(70);
    s.print();



    return 0;
}