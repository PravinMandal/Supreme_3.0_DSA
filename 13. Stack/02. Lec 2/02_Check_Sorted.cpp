#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

bool checkSorted(stack<int>&s, int element1){
    //base case
    if(s.empty()){
        //yaha tk aa gya mtlb saare check kr liya and ab empty ho gya stack and saare compare ho chuke h
        return true;
    }

    int element2=s.top();
    s.pop();
    if(element2 < element1){
        bool aagekaAns=checkSorted(s,element2); //element 2 de rhe h taaki wo check kr paaye top wale se
        s.push(element2); //backtracking
        return aagekaAns;
    }
    else{
        //agar condition satify nhi krta mtlb sorted nhi h
        return false;
    }
}

int main(){

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int element1=INT_MAX;
    cout<<checkSorted(s,element1);

    return 0;
}