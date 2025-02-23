#include<iostream>
#include<queue>
using namespace std;

int main() {
    
    //by default Max heap rhta h
    priority_queue<int>pq;
    pq.push(10);
    pq.push(25);
    pq.push(15);
    pq.push(30);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    //Min heap
    priority_queue<int, vector<int>, greater<int>>pq2;
    pq2.push(10);
    pq2.push(5);
    pq2.push(20);
    pq2.push(30);
    pq2.push(25);

    cout<<pq2.top()<<endl;
    pq2.pop();
    cout<<pq2.top()<<endl;

    return 0;
}
