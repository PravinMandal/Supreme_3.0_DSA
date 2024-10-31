#include<iostream>
#include<queue>
using namespace std;

void max_heap()
{

    //creation
    priority_queue<int> pq;
    //max_heap -> Maximum value -> highest priority

    pq.push(10);
    //10
    pq.push(25);
    //25,10
    pq.push(55);
    //55,25,10
    pq.push(21);
    //55,25,21,10


    
    //top element -> Highest priority element ( sabse bada number)

    cout<<pq.top()<<endl; //55

    pq.pop();
    // Highest priority element pop ho jayega i.e 55
    //25,21,10
    cout<<pq.top()<<endl;//25

    pq.pop();
    // Highest priority element pop ho jayega i.e 25
    //21,10
    cout<<pq.top()<<endl;//21


}

void min_heap()
{
    //min-heap -> minimum value -> highest priority

    priority_queue<int,vector<int>,greater<int>> pq;

    pq.push(10);
    //10
    pq.push(25);
    //10,25
    pq.push(55);
    //10,25,55
    pq.push(21);
    //10,21,25,55


    
    //top element -> Highest priority element ( sabse chota number because of min-heap)

    cout<<pq.top()<<endl; //10

    pq.pop();
    //21,25,55
    cout<<pq.top()<<endl; //21
    pq.pop();
    //25,55
    cout<<pq.top()<<endl; //25






}

int main()
{
    cout<<"Max heap"<<endl;
    max_heap();

    cout<<"Min heap"<<endl;
    min_heap();
    




    return 0;
}