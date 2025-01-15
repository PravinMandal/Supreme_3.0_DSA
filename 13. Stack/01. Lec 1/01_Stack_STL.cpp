#include<iostream>
#include<stack>
using namespace std;


int main(){

    stack<int>s;

    //insertion
    s.push(10);
    s.push(20);
    s.push(30);

    //size
    cout<<s.size()<<endl;

    //empty
    cout<<s.empty()<<endl;

    //peek
    cout<<s.top()<<endl;
    
    //removal
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;


    return 0;
}