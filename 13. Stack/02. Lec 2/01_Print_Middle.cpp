#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>&s, int count){
    //base case
    if(count==0){
        cout<<s.top();
        return;
    }

    int currentElement=s.top();
    s.pop();
    count--;

    //baaki recursion samhal lega
    printMiddle(s,count);

    //backtracking, warna stack ke elements pop hone ke baar gayab ho jayega main stack mai se
    s.push(currentElement);
}

int main(){

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int count=s.size()/2;

    printMiddle(s,count);

    return 0;
}