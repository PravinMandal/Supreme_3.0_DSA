#include<iostream>
#include<stack>
using namespace std;

int main()
{

    //creation
    stack<int>first;
    stack<int>second;

    first.push(10);
    first.push(20);
    first.push(30);

    first.pop();
    cout<<first.top()<<" ";
    cout<<first.size()<<endl;

    first.push(30);

    second.push(100);
    second.push(200);
    second.push(300);


    first.swap(second);

    cout<<first.top()<<endl;

    if( first.empty() == true)
    {
        cout<<"stack is empty";
    }
    else
    {
    cout<<"stack is not empty";
    }


    return 0;
}