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

    return 0;
}