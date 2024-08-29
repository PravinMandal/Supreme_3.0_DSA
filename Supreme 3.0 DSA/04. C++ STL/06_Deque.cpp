#include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(10);
    //10
    dq.push_back(20);
    //10,20
    dq.push_back(30);
    //10,20,30

    dq.push_front(300);
    //300,10,20,30
    dq.push_front(200);
    //200,300,10,20,30
    dq.push_front(100);
    //100,200,300,10,20,30
    

    deque<int>::iterator it= dq.begin();

    while( it != dq.end())
    {
        cout<<*it<<" ";
        it++;
    }



    return 0;
}