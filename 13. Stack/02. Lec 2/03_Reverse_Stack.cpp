#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s, int val){
    //base case
    if(s.empty()){
        s.push(val);
        return;
    }

    int topE=s.top();
    s.pop();
    //recursion
    insertAtBottom(s,val);
    //backtracking
    s.push(topE);
}

void reverseStack(stack<int>&s){
    //base case
    if(s.empty()){
        return;
    }

    int topE=s.top();
    s.pop();

    //recursion
    reverseStack(s);
    
    //insertAtBottom
    insertAtBottom(s,topE);
}

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    print(s);
    reverseStack(s);
    print(s);

    return 0;
}