#include<iostream>
#include<queue>
using namespace std;


int main(){

    queue<int> q;
    //insertion
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    //front
    cout<<q.front()<<endl;
    //pop
    q.pop();
    cout<<q.front()<<endl;
    //back
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    //size
    cout<<q.size()<<endl;
    //empty
    cout<<q.empty()<<endl;

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;

    cout<<"deque: "<<endl;
    deque<int>dq;

    //insertion
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(40);
    dq.push_front(50);
    dq.push_front(60);
    dq.push_front(70);
    dq.push_back(80);

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    dq.pop_front();
    dq.pop_back();

    cout<<dq.size()<<endl;
    cout<<dq.empty()<<endl;

    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }cout<<endl;

    return 0;
}