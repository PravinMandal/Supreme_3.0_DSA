#include<iostream>
#include<stack>
using namespace std;


int main(){

    stack<char>s;
    string name="pravin";

    //insertion
    for(int i=0; i<name.length(); i++){
        char ch=name[i];
        s.push(ch);
    }

    //retrival
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

    return 0;
}